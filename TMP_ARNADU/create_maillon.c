/*
** create_maillon.c for lemin in /home/costa_d/Documents/CPE/lemin/CPE_2015_lemin_bootstrap
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Wed Mar 30 18:37:17 2016 Arnaud Costa
** Last update Tue Apr 26 16:57:39 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

t_maillon       *create_maillon(int x, int y)
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
  while (i <= 5)
    {
      elem->next[i] = NULL;
      i++;
    }
  elem->parent = NULL;
  return (elem);
}
