/*
** update_tab_posi.c for dante in /home/costa_d/Documents/IA/dante/largeur
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue May  3 10:49:43 2016 Arnaud Costa
** Last update Sun May 29 13:49:05 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

t_maillon	**update_tab_posi(t_maillon **posi, int max)
{
  int		i;

  i = 0;
  while (posi[i] != NULL && i < max)
    {
      posi[i] = posi[i + 1];
      i++;
    }
  return (posi);
}

int	add_tab_posi(t_maillon **posi, t_maillon *tmp, int max)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (posi && posi[i] != NULL && i < max)
    i++;
  while (tmp->next[j] != NULL && i < max)
    {
      if (find_node(posi, tmp, max) == 0)
  	posi[i++] = tmp->next[j];
      else if (find_node(posi, tmp, max) == 1)
	return (1);
      j++;
    }
  posi[i] = NULL;
  return (0);
}

int	find_node(t_maillon **tab, t_maillon *nodes2, int max)
{
  int	i;

  i = 0;
  while (tab && tab[i] != NULL && i < max)
    {
      if (i > max)
	return (1);
      if (tab[i]->x == nodes2->x && tab[i]->y == nodes2->y)
	return (1);
      i++;
    }
  return (0);
}
