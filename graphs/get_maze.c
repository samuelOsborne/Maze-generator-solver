/*
** get_maze.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Mon Apr 25 17:10:45 2016 Arnaud Costa
** Last update Wed Apr 27 15:21:49 2016 Samuel
*/

#include <stdlib.h>
#include "graph.h"
#include "get_next_line.h"

#define LEFT 1
#define RIGHT 2
#define UP 0
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
  printf("node x : %d\n", node->x);
  printf("node y : %d\n", node->y);
  if ((node->x == size_map(map) - 1) && (node->y == length_map(map) - 1)) /* check end */
    {
      printf("at the end\n");
    }
  if ((node->y - 1 >= 0) && node->side != DOWN && map && map[node->y - 1][node->x] == '*') /* UP */
    {
      node->next[i] = create_maillon(node->x, node->y - 1, UP, node);
      printf("up");
    }
  if ((my_strlen(map[node->y]) >= node->x + 1 && node->side != LEFT && map && map[node->y][node->x + 1] == '*')) /*right*/
    {
      node->next[i] = create_maillon(node->x + 1, node->y, RIGHT, node);
      printf("right");
    }
  if (node->y + 1 <= h_tab(map) && node->side != UP && map && map[node->y + 1][node->x] == '*') /* down */
    {
      node->next[i] = create_maillon(node->x, node->y + 1, DOWN, node);
      printf("down");
    }
  if (node->x - 1 >= 0 && node->side != RIGHT && map && map[node->y][node->x - 1] == '*') /* left */
    {
      node->next[i] = create_maillon(node->x - 1, node->y, LEFT, node);
      printf("left");
    }
  while (node->next[i])
    {
      feed_node(map, node->next[i]);
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
  print_tab(tab);
  printf("%d\n", size_map(tab));
  printf("%d\n", length_map(tab));
  maillon = create_maillon(0, 0, NULL, NULL);
  feed_node(tab, maillon);
  /* free_tab(tab); */
}
