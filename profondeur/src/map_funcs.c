/*
** map_funcs.c for map_funcs in /media/samuel/Home/osborn_s/rendu/init_ia/dante/graphs
**
** Made by Samuel
** Login   <samuel@epitech.net>
**
** Started on  Thu Apr 28 10:44:24 2016 Samuel
** Last update Fri May 20 11:45:41 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

int	length_map(char **map)
{
  int	i;

  i = 0;
  while (map[0][i] != '\0')
    i++;
  return (i);
}

int	carve_tab(t_maillon *node, char **map)
{
  while (node->parent != NULL)
    {
      map[node->y][node->x] = 'o';
      node = node->parent;
    }
  map[0][0] = 'o';
  map[h_tab(map) - 1][length_map(map) - 1] = 'o';
  return (0);
}

int	h_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i] != NULL)
    i++;
  return (i);
}
