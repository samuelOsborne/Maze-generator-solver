/*
** free_tab.c for dante in /home/costa_d/Documents/IA/dante/graphs/TMP_ARNADU
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Apr 26 13:10:16 2016 Arnaud Costa
** Last update Tue May 10 14:05:15 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i] != '\0')
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void	free_tab_maillon(t_maillon **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
