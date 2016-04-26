/*
** get_maze.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Mon Apr 25 17:10:45 2016 Arnaud Costa
** Last update Tue Apr 26 14:38:22 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"
#include "get_next_line.h"

int	feed_node(char	**map)
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

int	h_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab && tab[i] != NULL)
    i++;
  return (i);
}

char	**my_realloc_tab(char **tab)
{
  char	**new_tab;
  int	i;

  i = 0;
  if ((new_tab = malloc(sizeof(char *) * (h_tab(tab) + 2))) == NULL)
    return (NULL);
  while (tab && tab[i] != '\0')
    {
      if ((new_tab[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1))) == NULL)
        return (NULL);
      my_strcpy(new_tab[i], tab[i]);
      i++;
    }
  new_tab[i] = NULL;
  free_tab(tab);
  return (new_tab);
}

char	**get_maze(int fd)
{
  char		**tab;
  char		*str;
  int		i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * 2)) == NULL)
    return (NULL);
  while (str = get_next_line(fd))
    {
      if ((tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
	return (NULL);
      my_strcpy(tab[i], str);
      i++;
      tab[i] = NULL;
      tab = my_realloc_tab(tab);
      free(str);
    }
  print_tab(tab);
  free_tab(tab);
  return (tab);
}
