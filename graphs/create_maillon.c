/*
** create_maillon.c for lemin in /home/costa_d/Documents/CPE/lemin/CPE_2015_lemin_bootstrap
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Wed Mar 30 18:37:17 2016 Arnaud Costa
** Last update Wed Apr 13 10:53:03 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

t_maillon       *create_maillon(int data)
{
  t_maillon     *elem;
  int           i;

  i = 0;
  elem = malloc(sizeof(elem));
  elem->next = malloc(sizeof(elem) * 10);
  if (elem == NULL)
    return (NULL);
  elem->data = data;
  elem->id = 0;
  while (i <= 10)
    {
      elem->next[i] = NULL;
      i++;
    }
  return (elem);
}
