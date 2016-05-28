/*
** get_maze.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Mon Apr 25 17:10:45 2016 Arnaud Costa
** Last update Sat May 28 20:46:43 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "graph.h"

t_maillon	**init_posi(char **m, t_maillon *n)
{
  t_maillon	**posi;

  if ((posi = malloc(sizeof(t_maillon *) * (h_tab(m) + 2)
                     * (m_str(m[0]) + 2))) == NULL)
    return (NULL);
  memset_tab(posi, (h_tab(m) + 2) * (m_str(m[0]) + 2));
  posi[0] = n;
  posi[1] = NULL;
  return (posi);
}

int		finde_maze(char **m, t_maillon *n, int x, int y)
{
  t_maillon	**open;
  t_maillon	**close;
  t_maillon	*tmp;

  open = init_posi(m, n);
  close = init_close(m);
  if (x > 100 && y > 100)
    return (1);
  while (open[0] != NULL)
    {
      tmp = open[find_smaller(open, x * y)];
      add_tmp_to_close(tmp, close, x * y);
      update_tab_open(open, find_smaller(open, x * y), x * y);
      if ((tmp->y == x - 1) && (tmp->x == y - 1))
  	{
  	  carve_tab(tmp, m);
  	  return (0);
  	}
      check_direction(tmp, m, 0);
      add_tab_open(open, tmp, x, y);
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
  error_manager(finde_maze(tab, maillon, h_tab(tab), m_str(tab[0])), tab);
  free(maillon);
  free_tab(tab);
}
