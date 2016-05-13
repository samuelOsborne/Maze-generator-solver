/*
** update_tab_posi.c for dante in /home/costa_d/Documents/IA/dante/largeur
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue May  3 10:49:43 2016 Arnaud Costa
** Last update Tue May 10 13:42:31 2016 Arnaud Costa
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
  posi[i] = NULL;
  return (posi);
}

t_maillon	**add_tab_posi(t_maillon **posi, t_maillon *tmp, char **m)
{
  t_maillon	**tab_dest;
  int   i;
  int	j;

  i = 0;
  j = 0;
  if ((tab_dest = malloc(sizeof(t_maillon *) * (h_tab(m) + 1) * (my_strlen(m[0]) + 1))) == NULL)
    return (NULL);
  memset_tab(tab_dest, (h_tab(m) + 1) * (my_strlen(m[0]) + 1));
  while (tmp->next[i] != NULL)
    {
      if ((tab_dest[i] = malloc(sizeof(t_maillon))) == NULL)
	return (NULL);
      tab_dest[i++] = tmp->next[j];
      j++;
    }
  j = 0;
  while (posi[j] != NULL)
    {
      if ((tab_dest[i] = malloc(sizeof(t_maillon))) == NULL)
        return (NULL);
      tab_dest[i] = posi[j];
      i++;
      j++;
    }
  tab_dest[i] = NULL;
  /*free_tab(posi)*/
  return (tab_dest);
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
