/*
** get_maze.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Mon Apr 25 17:10:45 2016 Arnaud Costa
** Last update Thu Apr 28 11:11:29 2016 Samuel
*/

#include <stdlib.h>
#include "graph.h"
#include "get_next_line.h"

int		feed_node(char	**m, t_maillon *n)
{
  int		i;

  i = 0;
  if ((n->y == h_tab(m) - 1) && (n->x == h_tab(m) - 1))
    return (0);
  if ((n->y - 1 >= 0) && n->side != DOWN && m[n->y - 1][n->x] == '*')
    if ((n->next[i++] = create_maillon(n->x, n->y - 1, UP, n)) == NULL)
      return (1);
  if (m_str(m[n->y]) >= n->x + 1 && n->side != 1 && m[n->y][n->x + 1] == '*')
    if ((n->next[i++] = create_maillon(n->x + 1, n->y, RIGHT, n)) == NULL)
      return (1);
  if (n->y + 1 <= (h_tab(m) - 1) && n->side != UP && m[n->y + 1][n->x] == '*')
    if ((n->next[i++] = create_maillon(n->x, n->y + 1, DOWN, n)) == NULL)
      return (1);
  if (n->x - 1 >= 0 && n->side != RIGHT && m[n->y][n->x - 1] == '*')
    if ((n->next[i++] = create_maillon(n->x - 1, n->y, LEFT, n)) == NULL)
      return (1);
  i = 0;
  while (n->next[i] != NULL)
    if ((feed_node(m, n->next[i++])) == 0)
      {
	carve_tab(n, m);
	return (0);
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
      if ((new_tab[i] = malloc(sizeof(char)
			       * (my_strlen(tab[i]) + 1))) == NULL)
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
  maillon = create_maillon(0, 0, DOWN, (t_maillon*)NULL);
  feed_node(tab, maillon);
  print_tab(tab);
  free_tab(tab);
}
