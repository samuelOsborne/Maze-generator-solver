/*
** map_funcs.c for map_funcs in /media/samuel/Home/osborn_s/rendu/init_ia/dante/graphs
**
** Made by Samuel
** Login   <samuel@epitech.net>
**
** Started on  Thu Apr 28 10:44:24 2016 Samuel
** Last update Wed May 18 16:12:31 2016 Samuel
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
