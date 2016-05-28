/*
** update_tab_posi.c for dante in /home/costa_d/Documents/IA/dante/largeur
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue May  3 10:49:43 2016 Arnaud Costa
** Last update Sat May 28 19:42:01 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

int	find_smaller(t_maillon **posi, int max)
{
  int		i;
  int		j;
  t_maillon	*smaller;

  i = 0;
  j = 0;
  smaller = posi[0];
  while (posi[i] != NULL && i < max)
    {
      if (posi[i]->f < smaller->f)
	j = i;
      i++;
    }
  return (j);
}

t_maillon	**update_tab_open(t_maillon **posi, int i, int max)
{
  int	nb;

  nb = 0;
  while (posi[i] != NULL && nb < max)
    {
      posi[i] = posi[i + 1];
      i++;
      nb++;
    }
  posi[i] = NULL;
  return (posi);
}

int	calcul(t_maillon *posi, int x, int y)
{
  int	f;
  int	g;
  int	h;
  int	cal1;
  int	cal2;

  cal2 = cal1 = 0;
  f = g = h = 0;
  cal1 = posi->x - x;
  if (cal1 < 0)
    cal1 *= -1;
  cal2 = posi->y - y;
  if (cal2 < 0)
    cal2 *= -1;
  h = cal1 + cal2;
  cal2 = cal1 = 0;
  cal1 = posi->x - 0;
  if (cal1 < 0)
    cal1 *= -1;
  cal2 = posi->y - 0;
  if (cal2 < 0)
    cal2 *= -1;
  g = cal1 + cal2;
  f = g + h;
  return (f);
}

void	add_tmp_to_close(t_maillon *tmp, t_maillon **close, int max)
{
  int	i;

  i = 0;
  (void)tmp;
  while (close && close[i] != NULL && i < max)
    i++;
  close[i] = NULL;
}

void	add_tab_open(t_maillon **posi, t_maillon *tmp, int x, int y)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (posi && posi[i] != NULL)
    {
      posi[i]->f = calcul(posi[i], x, y);
      i++;
    }
  while (tmp->next[j] != NULL)
    {
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
