/*
** update_tab_posi.c for dante in /home/costa_d/Documents/IA/dante/largeur
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue May  3 10:49:43 2016 Arnaud Costa
** Last update Tue May  3 16:29:03 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

t_maillon	**update_tab_posi(t_maillon **posi)
{
  int		i;

  i = 0;
  while (posi[i] != NULL)
    {
      posi[i] = posi[i + 1];
      i++;
    }
  return (posi);
}

void	add_tab_posi(t_maillon **posi, t_maillon *tmp)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (posi[i] != NULL)
    i++;
  while (tmp->next[j])
    {
      if (find_node(posi, tmp) == 0)
	posi[i] = tmp->next[j];
      j++;
      i++;
    }
  posi[i] = NULL;
}

int	find_node(t_maillon **tab, t_maillon *nodes2)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (tab[i]->x == nodes2->x && tab[i]->y == nodes2->y)
	return (1);
      i++;
    }
  return (0);
}
