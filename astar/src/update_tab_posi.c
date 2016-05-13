/*
** update_tab_posi.c for dante in /home/costa_d/Documents/IA/dante/largeur
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue May  3 10:49:43 2016 Arnaud Costa
** Last update Fri May 13 13:44:35 2016 Arnaud Costa
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
  smaller = posi[i];
  while (posi[i] != NULL)
    {
      printf("find_smaller\n");
      printf("f = %d\n", posi[i]->f);
      printf("x = %d && y = %d\n", posi[i]->x, posi[i]->y);
      if (posi[i]->f < smaller->f)
	{
	  i = j;
	}
      i++;
    }
  return (j);
}

t_maillon	**update_tab_open(t_maillon **posi, int i)
{
  while (posi[i] != NULL)
    {
      printf("update_tab_open\n");
      posi[i] = posi[i + 1];
      i++;
    }
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
  /*
  ** cal de h
  */
  cal1 = posi->x - x;
  if (cal1 < 0)
    cal1 *= -1;
  cal2 = posi->y - y;
  if (cal2 < 0)
    cal2 *= -1;
  h = cal1 + cal2;
  /*
  ** cal de g
  */
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

void	add_tmp_to_close(t_maillon *tmp, t_maillon **close)
{
  int	i;

  i = 0;
  while (close[i] != NULL)
    i++;
  close[i] = tmp;
  close[i] = NULL;
}

void	add_tab_open(t_maillon **posi, t_maillon *tmp,
		     t_maillon **close, char **m)
{
  int	i;
  int	j;
  int	x;
  int	y;

  i = 0;
  j = 0;
  x = h_tab(m) - 1;
  y = my_strlen(m[0]) - 1;
  while (posi && posi[i] != NULL)
    {
      printf("add_tab_posi1\n");
      posi[i]->f = calcul(posi[i], x, y);
      i++;
    }
  while (tmp->next[j] != NULL)
    {
      if (find_node(posi, tmp) == 0 && find_node(close, tmp) == 0)
	{
	  printf("add_tab_posi2\n");
	  posi[i] = tmp->next[j];
	  posi[i]->f = calcul(tmp->next[j], x, y);
	  i++;
	}
      j++;
    }
  posi[i] = NULL;
}

int	find_node(t_maillon **tab, t_maillon *nodes)
{
  int	i;

  i = 0;
  while (tab && tab[i] != NULL)
    {
      printf("find_node\n");
      if (tab[i]->x == nodes->x && tab[i]->y == nodes->y)
	return (1);
      i++;
    }
  return (0);
}
