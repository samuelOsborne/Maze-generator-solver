/*
** memset_tab.c for dante in /home/costa_d/Documents/IA/dante/largeur/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu May  5 20:07:43 2016 Arnaud Costa
** Last update Thu May  5 20:15:41 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

void	memset_tab(t_maillon **posi, int max)
{
  int	i;

  i = 0;
  while (i < max)
    {
      posi[i] = NULL;
      i++;
    }
}
