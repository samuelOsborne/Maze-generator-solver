/*
** check_direction.c for src in /media/samuel/Home/osborn_s/rendu/init_ia/dante/profondeur/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Fri May 13 14:25:17 2016 Samuel
** Last update Wed May 18 16:28:10 2016 Samuel
*/

#include <stdlib.h>
#include "graph.h"

int		check_direction(t_maillon *tmp, char **m, int i)
{
  if ((tmp->y - 1 >= 0) &&
      tmp->side != DOWN && m[tmp->y - 1][tmp->x] == '*')
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
