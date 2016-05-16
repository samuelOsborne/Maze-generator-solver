/*
** get_maze.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Mon Apr 25 17:10:45 2016 Arnaud Costa
** Last update Mon May 16 13:19:28 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"
#include "get_next_line.h"

int		finde_maze(char **m, t_maillon *n, int x, int y)
{
  int           i;
  t_maillon	**open;
  t_maillon	**close;
  t_maillon	*tmp;

  if ((open = malloc(sizeof(t_maillon *) * (x + 1) * (y + 1))) == NULL)
    return (-1);
  memset_tab(open, (x + 1) * (y + 1));
  if ((close = malloc(sizeof(t_maillon *) * (x + 1) * (y + 1))) == NULL)
    return (-1);
  memset_tab(close, (x + 1) * (y + 1));
  open[0] = n;
  open[1] = NULL;
  while (open[0] != NULL)
    {
      i = 0;
      printf("getmaze\n");
      tmp = open[find_smaller(open)];
      add_tmp_to_close(tmp, close);
      update_tab_open(open, find_smaller(open));
      if ((tmp->y == x - 1) && (tmp->x == y - 1))
  	{
  	  carve_tab(tmp, m);
  	  return (0);
  	}
      if ((tmp->y - 1 >= 0) && tmp->side != DOWN && m[tmp->y - 1][tmp->x] == '*')
  	if ((tmp->next[i++] = create_maillon(tmp->x, tmp->y - 1, UP, tmp)) == NULL)
  	  return (1);
      if (m_str(m[tmp->y]) >= tmp->x + 1 && tmp->side != 1 && m[tmp->y][tmp->x + 1] == '*')
  	if ((tmp->next[i++] = create_maillon(tmp->x + 1, tmp->y, RIGHT, tmp)) == NULL)
  	  return (1);
      if (tmp->y + 1 <= (h_tab(m) - 1) && tmp->side != UP && m[tmp->y + 1][tmp->x] == '*')
  	if ((tmp->next[i++] = create_maillon(tmp->x, tmp->y + 1, DOWN, tmp)) == NULL)
  	  return (1);
      if (tmp->x - 1 >= 0 && tmp->side != RIGHT && m[tmp->y][tmp->x - 1] == '*')
  	if ((tmp->next[i++] = create_maillon(tmp->x - 1, tmp->y, LEFT, tmp)) == NULL)
  	  return (1);
      add_tab_open(open, tmp, x, y);
    }
  my_putstr("Path not found\n");
  return (0);
}

int	h_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab && tab[i] != NULL)
    i++;
  return (i);
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
			       * (my_strlen(tab[i]) + 1))) == NULL)
        return (NULL);
      my_strcpy(new_tab[i], tab[i]);
      i++;
    }
  new_tab[i] = NULL;
  free_tab(tab);
  return (new_tab);
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
  while (str = get_next_line(fd))
    {
      if ((tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
	return ;
      my_strcpy(tab[i], str);
      i++;
      tab[i] = NULL;
      tab = my_realloc_tab(tab);
      free(str);
    }
  if ((maillon = create_maillon(0, 0, DOWN, (t_maillon*)NULL)) == NULL)
    return ;
  finde_maze(tab, maillon, h_tab(tab), my_strlen(tab[0]));
  free(maillon);
  print_tab(tab);
  free_tab(tab);
}
