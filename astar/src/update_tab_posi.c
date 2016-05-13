/*
** update_tab_posi.c for dante in /home/costa_d/Documents/IA/dante/largeur
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue May  3 10:49:43 2016 Arnaud Costa
** Last update Thu May 12 15:02:21 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

int	find_smaller(t_maillon **posi)
{
  int		i;
  int		j;
  t_maillon	*smaller;

  i = 0;
  j = 0;
  smaller = posi[0];
  while (posi[i] != NULL)
    {
      printf("find_smaller\n");
      printf("f = %d\n", posi[i]->f);
      if (posi[i]->f < smaller[i].f)
	{
	  i = j;
	  printf("i = %d, j = %d\n", i, j);
	}
      i++;
    }
  return (j);
}

t_maillon	**update_tab_posi(t_maillon **posi)
{
  int		i;

  i = 0;
  while (posi[i] != NULL)
    {
      printf("update_tab_posi\n");
      posi[i] = posi[i + 1];
      i++;
    }
  return (posi);
}

int	calcul(t_maillon *posi, int x, int y)
{
  int	res;
  int	cal1;
  int	cal2;

  res = 0;
  cal1 = posi->x - x;
  if (cal1 < 0)
    cal1 *= -1;
  cal2 = posi->y - y;
  if (cal2 < 0)
    cal2 *= -1;
  res = cal1 + cal2;
  return (res);
}

void	add_tab_posi(t_maillon **posi, t_maillon *tmp, char **m)
{
  int	i;
  int	j;
  int	x;
  int	y;

  i = 0;
  j = 0;
  x = h_tab(m) - 1;
  y = length_map(m) - 1;
  while (posi && posi[i] != NULL)
    {
      printf("add_tab_posi1\n");
      posi[i]->f = calcul(posi[i], x, y);
      i++;
    }
  while (tmp->next[j] != NULL)
    {
      printf("add_tab_posi2\n");
      if (find_node(posi, tmp) == 0)
	{
	  posi[i] = tmp->next[j];
	  posi[i]->f = calcul(tmp->next[j], x, y);
	  i++;
	}
      j++;
    }
  posi[i] = NULL;
}

int	find_node(t_maillon **tab, t_maillon *nodes2)
{
  int	i;

  i = 0;
  while (tab && tab[i] != NULL)
    {
      printf("find_node\n");
      if (tab[i]->x == nodes2->x && tab[i]->y == nodes2->y)
	return (1);
      i++;
    }
  return (0);
}
