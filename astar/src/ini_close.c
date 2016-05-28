/*
** ini_close.c for dante in /home/costa_d/Documents/IA/dante/astar/src
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sat May 28 13:15:38 2016 Arnaud Costa
** Last update Sat May 28 13:32:06 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

t_maillon	**init_close(char **m)
{
  t_maillon	**close;

  if ((close = malloc(sizeof(t_maillon *) * (h_tab(m) + 2)
                     * (m_str(m[0]) + 2))) == NULL)
    return (NULL);
  memset_tab(close, (h_tab(m) + 2) * (m_str(m[0]) + 2));
  return (close);
}
