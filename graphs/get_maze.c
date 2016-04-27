/*
** get_maze.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Mon Apr 25 17:10:45 2016 Arnaud Costa
** Last update Wed Apr 27 17:40:31 2016 Samuel
*/

#include <stdlib.h>
#include "graph.h"
#include "get_next_line.h"

#define LEFT 1
#define RIGHT 2
#define UP 4
#define DOWN 3

int	size_map(char **map)
{
  int	i;

  i = 0;
  while (map[i])
    i++;
  return (i);
}

int	length_map(char **map)
{
  int	i;

  i = 0;
  while (map[0][i] != '\0')
    i++;
  return (i);
}

int	feed_node(char	**map, t_maillon *node)
{
  int		i;

  i = 0;
  if ((node->y == size_map(map) - 1) && (node->x == length_map(map) - 1)) /* check end */
    return (0);
  if ((node->y - 1 >= 0) && node->side != DOWN && map && map[node->y - 1][node->x] == '*') /* UP */
    node->next[i++] = create_maillon(node->x, node->y - 1, UP, node);
  if ((my_strlen(map[node->y]) >= node->x + 1 && node->side != LEFT && map && map[node->y][node->x + 1] == '*')) /*right*/
    node->next[i++] = create_maillon(node->x + 1, node->y, RIGHT, node);
  if (node->y + 1 <= (h_tab(map) - 1) && node->side != UP && map && map[node->y + 1][node->x] == '*') /* down */
    node->next[i++] = create_maillon(node->x, node->y + 1, DOWN, node);
  if (node->x - 1 >= 0 && node->side != RIGHT && map && map[node->y][node->x - 1] == '*') /* left */
    node->next[i++] = create_maillon(node->x - 1, node->y, LEFT, node);
  i = 0;
  while (node->next[i] != NULL)
    {
      if ((feed_node(map, node->next[i])) == 0)
	{
	  i = 0;
	  while (node->parent != NULL)
	    {
	      map[node->y][node->x] = 'o';
	      node = node->parent;
	    }
	  map[0][0] = 'o';
	  map[size_map(map) - 1][length_map(map) - 1] = 'o';
	  return (0);
	}
      i++;
    }
  return (1);
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

void	get_maze(int fd)
{
  char		**tab;
  char		*str;
  t_maillon	*maillon;
  int		i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * 2)) == NULL)
    return ;
  while (str = get_next_line(fd))
    {
      if ((tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
	return ;
      my_strcpy(tab[i], str);
      i++;
      tab[i] = NULL;
      tab = my_realloc_tab(tab);
      free(str);
    }
  maillon = create_maillon(0, 0, NULL, NULL);
  feed_node(tab, maillon);
  print_tab(tab);
  free_tab(tab);
}
