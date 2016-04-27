/*
** get_maze.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Mon Apr 25 17:10:45 2016 Arnaud Costa
** Last update Wed Apr 27 13:15:24 2016 Samuel
*/

#include <stdlib.h>
#include "graph.h"
#include "get_next_line.h"

#define LEFT 1
#define RIGHT 2
#define UP 0
#define DOWN 3

int	feed_node(char	**map, t_node *node)
{
  int		x;
  int		y;
  int		i;

  /* x = 0; */
  /* y = 0; */
  i = 0;
  if ((y - 1 >= 0) && node->side != DOWN && map && map[y - 1][x] == '*') /* UP */
    {
      node->next[i] = create_maillon(x, y - 1, UP);
      
    }
  if ((my_strlen(str[y]) >= x + 1 && node->side != LEFT && map && map[y][x + 1] == '*')) /*right*/
    {
      node->next[i] = create_maillon(x, y - 1, RIGHT);

    }
  if (y + 1 <= h_tab(map) && node->side != UP && map && map[y + 1][x] == '*') /* down */
    {
      node->next[i] = create_maillon(x, y - 1, DOWN);

    }
  if (x - 1 >= 0 && node->side != RIGHT && map && map[y][x - 1] == '*') /* left */
    {
      node->next[i] = create_maillon(x, y - 1, LEFT);

    }
  while (node->next[])
    {
      /* recursive */
      i++;
    }
  /* utilser les x y des maillons */
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
