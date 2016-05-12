/*
** update_tab_posi.c for dante in /home/costa_d/Documents/IA/dante/largeur
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue May  3 10:49:43 2016 Arnaud Costa
** Last update Thu May  5 14:50:13 2016 Arnaud Costa
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

t_maillon	**add_tab_posi(t_maillon **posi, t_maillon *tmp, char **m)
{
  int		i;
  int		j;
  t_maillon	**posi2;

  i = 0;
  j = 0;
  if ((posi2 = malloc(sizeof(t_maillon *) * ((h_tab(m) + 1) * (my_strlen(m[0]) + 1)))) == NULL)
    return (NULL);
  while (tmp->next[j] != NULL)
    {
      if (find_node(posi, tmp) == 0)
	posi2[i++] = tmp->next[j];
      /* i++; */
      j++;
    }
  j = 0;
  while (posi[j] != NULL)
    {
      posi2[i] = posi[j];
      i++;
      j++;
    }
  posi2[i] = NULL;
  /* free(posi); */
  return (posi2);
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
