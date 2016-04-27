/*
** create_maillon.c for lemin in /home/costa_d/Documents/CPE/lemin/CPE_2015_lemin_bootstrap
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Wed Mar 30 18:37:17 2016 Arnaud Costa
** Last update Wed Apr 27 13:51:16 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

t_maillon       *create_maillon(int x, int y, int side, t_maillion *parent)
{
  t_maillon     *elem;
  int           i;

  i = 0;
  if ((elem = malloc(sizeof(elem))) == NULL)
    return (NULL);
  if ((elem->next = malloc(sizeof(elem) * 5)) == NULL)
    return (NULL);
  elem->id = 0;
  elem->x = x;
  elem->y = y;
  elem->side = side;
  elem->parent = parent;
  while (i <= 5)
    {
      elem->next[i] = NULL;
      i++;
    }
  elem->parent = NULL;
  return (elem);
}
