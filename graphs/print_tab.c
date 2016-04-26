/*
** print_tab.c for test in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Apr 26 13:46:00 2016 Arnaud Costa
** Last update Tue Apr 26 13:49:59 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      printf("tab[%d] = %s\n", i , tab[i]);
      i++;
    }
}
