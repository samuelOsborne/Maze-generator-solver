/*
** memset_tab.c for dante in /home/costa_d/Documents/IA/dante/profondeur2/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Thu May  5 20:15:13 2016 Arnaud Costa
** Last update Tue May 10 13:42:58 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

void	memset_tab(t_maillon **posi, int max)
{
  int   i;

  i = 0;
  while (i < max)
    {
      posi[i] = NULL;
      i++;
    }
}
