/*
** check_direction.c for astar in /home/costa_d/Documents/IA/dante/astar/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue May 17 15:30:55 2016 Arnaud Costa
** Last update Thu May 19 11:30:09 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

int	check_direction(t_maillon *tmp, char **m, int i)
{
  if ((tmp->y - 1 >= 0) && tmp->side != DOWN &&
      m[tmp->y - 1][tmp->x] == '*')
    if ((tmp->next[i++] =
	 create_maillon(tmp->x, tmp->y - 1, UP, tmp)) == NULL)
      return (1);
  if (m_str(m[tmp->y]) >= tmp->x + 1 &&
      tmp->side != 1 && m[tmp->y][tmp->x + 1] == '*')
    if ((tmp->next[i++] =
	 create_maillon(tmp->x + 1, tmp->y, RIGHT, tmp)) == NULL)
      return (1);
  if (tmp->y + 1 <= (h_tab(m) - 1) &&
      tmp->side != UP && m[tmp->y + 1][tmp->x] == '*')
    if ((tmp->next[i++] =
	 create_maillon(tmp->x, tmp->y + 1, DOWN, tmp)) == NULL)
      return (1);
  if (tmp->x - 1 >= 0 &&
      tmp->side != RIGHT && m[tmp->y][tmp->x - 1] == '*')
    if ((tmp->next[i++] =
	 create_maillon(tmp->x - 1, tmp->y, LEFT, tmp)) == NULL)
      return (1);
  return (0);
}
