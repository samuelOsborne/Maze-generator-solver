/*
** get_maze.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Mon Apr 25 17:10:45 2016 Arnaud Costa
** Last update Mon Apr 25 18:10:21 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"
#include "get_next_line.h"

int	feed_node(t_maillon *start_nodes, char *str, int y)
{
  int		i;
  int		x;
  t_maillon	*new_nodes;
  t_maillon	*tmp_nodes;

  i = 0;
  x = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == '*')
	{
	  printf("I'find a * at %d - %d\n", y , x);
	  //new_nodes = create_maillon(x, y);
	  //link_maillon(new_nodes, tmp_nodes);
	}
      i++;
      x++;
    }
}

int	get_maze(int fd)
{
  char		*str;
  int		y;
  t_maillon	*start_nodes;

  y = 0;
  /* if ((start_nodes = create_maillon(0, 0)) == NULL) */
  /*   return (-1); */
  while (str = get_next_line(fd))
    {
      printf("beafor feed_node = %s\n", str);
      feed_node(start_nodes, str, y);
      y++;
      free(str);
    }
  return (0);
}
