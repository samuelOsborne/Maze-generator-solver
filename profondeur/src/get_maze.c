/*
** get_maze.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Mon Apr 25 17:10:45 2016 Arnaud Costa
** Last update Sat May 28 09:09:50 2016 Samuel
*/

#include <stdlib.h>
#include "graph.h"
#include "get_next_line.h"

t_maillon	**init_posi(char **m, t_maillon *n)
{
  t_maillon	**posi;

  if ((posi = malloc(sizeof(t_maillon *) * (h_tab(m) + 1) *
		     (m_str(m[0]) + 1))) == NULL)
    return (NULL);
  memset_tab(posi, (h_tab(m) + 1) * (m_str(m[0]) + 1));
  posi[0] = n;
  posi[1] = NULL;
  return (posi);
}

int		finde_maze(char **m, t_maillon *n)
{
  int           i;
  t_maillon	**posi;
  t_maillon	*tmp;

  i = 0;
  posi = init_posi(m, n);
  while (posi[0] != NULL)
    {
      if (i > ((h_tab(m) + 1) * (m_str(m[0]) + 1)))
	return (2);
      tmp = posi[0];
      posi = update_tab_posi(posi);
      if ((tmp->y == h_tab(m) - 1) && (tmp->x == m_str(m[0]) - 1))
  	{
  	  carve_tab(tmp, m);
  	  return (0);
  	}
      check_direction(tmp, m, 0);
      posi = add_tab_posi(posi, tmp, m);
      i++;
    }
  return (1);
}

char	**my_realloc_tab(char **tab)
{
  char	**new_tab;
  int	i;

  i = 0;
  if ((new_tab = malloc(sizeof(char *) * (h_tab(tab) + 2))) == NULL)
    return (NULL);
  while (tab && tab[i] != '\0')
    {
      if ((new_tab[i] = malloc(sizeof(char)
			       * (m_str(tab[i]) + 1))) == NULL)
        return (NULL);
      my_strcpy(new_tab[i], tab[i]);
      i++;
    }
  new_tab[i] = NULL;
  free_tab(tab);
  return (new_tab);
}

void	error_manager(int maze, char **tab)
{
  if (maze == 0)
    print_tab(tab);
  else
    my_putstr("No solution found\n");
}

void	get_maze(int fd)
{
  char		**tab;
  char		*str;
  int		i;
  t_maillon	*maillon;

  i = 0;
  if ((tab = malloc(sizeof(char *) * 2)) == NULL)
    return ;
  while ((str = get_next_line(fd)))
    {
      if ((tab[i] = malloc(sizeof(char) * (m_str(str) + 1))) == NULL)
	return ;
      my_strcpy(tab[i], str);
      i++;
      tab[i] = NULL;
      tab = my_realloc_tab(tab);
      free(str);
    }
  if ((maillon = create_maillon(0, 0, DOWN, (t_maillon*)NULL)) == NULL)
    return ;
  error_manager(finde_maze(tab, maillon), tab);
  free(maillon);
  free_tab(tab);
}
