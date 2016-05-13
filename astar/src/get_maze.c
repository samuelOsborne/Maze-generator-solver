/*
** get_maze.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Mon Apr 25 17:10:45 2016 Arnaud Costa
** Last update Fri May 13 13:29:37 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"
#include "get_next_line.h"

int		finde_maze(char **m, t_maillon *n)
{
  int           i;
  t_maillon	**posi;
  t_maillon	**close;
  t_maillon	*tmp;

  i = 0;
  if ((posi = malloc(sizeof(t_maillon *) * (h_tab(m) + 1) * (my_strlen(m[0]) + 1))) == NULL)
    return (-1);
  memset_tab(posi, (h_tab(m) + 1) * (my_strlen(m[0]) + 1));
  if ((close = malloc(sizeof(t_maillon *) * (h_tab(m) + 1) * (my_strlen(m[0]) + 1))) == NULL)
    return (-1);
  memset_tab(close, (h_tab(m) + 1) * (my_strlen(m[0]) + 1));
  posi[0] = n;
  posi[1] = NULL;
  while (posi[0] != NULL)
    {
      i = 0;
      printf("getmaze\n");
      tmp = posi[find_smaller(posi)];
      add_tmp_to_close(tmp, close);
      update_tab_open(posi, find_smaller(posi));
      if ((tmp->y == h_tab(m) - 1) && (tmp->x == h_tab(m) - 1))
  	{
  	  carve_tab(tmp, m);
  	  return (0);
  	}
      if ((tmp->y - 1 >= 0) && tmp->side != DOWN && m[tmp->y - 1][tmp->x] == '*')
  	if ((tmp->next[i++] = create_maillon(tmp->x, tmp->y - 1, UP, tmp)) == NULL)
  	  return (1);
      if (m_str(m[tmp->y]) >= tmp->x + 1 && tmp->side != 1 && m[tmp->y][tmp->x + 1] == '*')
  	if ((tmp->next[i++] = create_maillon(tmp->x + 1, tmp->y, RIGHT, tmp)) == NULL)
  	  return (1);
      if (tmp->y + 1 <= (h_tab(m) - 1) && tmp->side != UP && m[tmp->y + 1][tmp->x] == '*')
  	if ((tmp->next[i++] = create_maillon(tmp->x, tmp->y + 1, DOWN, tmp)) == NULL)
  	  return (1);
      if (tmp->x - 1 >= 0 && tmp->side != RIGHT && m[tmp->y][tmp->x - 1] == '*')
  	if ((tmp->next[i++] = create_maillon(tmp->x - 1, tmp->y, LEFT, tmp)) == NULL)
  	  return (1);
      add_tab_open(posi, tmp, m);
    }
  /* if ((finder(posi, m)) != 0) */
  my_putstr("Path not found\n");
  return (0);
}

/* int	finder(t_maillon **posi, char **m) */
/* { */
/*   int	i; */
/*   t_maillon *tmp; */

/*   while (posi[0] != NULL) */
/*     { */
/*       i = 0; */
/*       tmp = posi[0]; */
/*       posi = update_tab_posi(posi); */
/*       if ((tmp->y == h_tab(m) - 1) && (tmp->x == h_tab(m) - 1)) */
/*         { */
/*           carve_tab(tmp, m); */
/*           return (0); */
/*         } */
/*       if ((tmp->y - 1 >= 0) && tmp->side != DOWN && m[tmp->y - 1][tmp->x] == '*') */
/*         if ((tmp->next[i++] = create_maillon(tmp->x, tmp->y - 1, UP, tmp)) == NULL) */
/*           return (1); */
/*       if (m_str(m[tmp->y]) >= tmp->x + 1 && tmp->side != 1 && m[tmp->y][tmp->x + 1] == '*') */
/*         if ((tmp->next[i++] = create_maillon(tmp->x + 1, tmp->y, RIGHT, tmp)) == NULL) */
/*           return (1); */
/*       if (tmp->y + 1 <= (h_tab(m) - 1) && tmp->side != UP && m[tmp->y + 1][tmp->x] == '*') */
/*         if ((tmp->next[i++] = create_maillon(tmp->x, tmp->y + 1, DOWN, tmp)) == NULL) */
/*           return (1); */
/*       if (tmp->x - 1 >= 0 && tmp->side != RIGHT && m[tmp->y][tmp->x - 1] == '*') */
/*         if ((tmp->next[i++] = create_maillon(tmp->x - 1, tmp->y, LEFT, tmp)) == NULL) */
/*           return (1); */
/*       add_tab_posi(posi, tmp); */
/*     } */
/*   return (1); */
/* } */

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
  int		i;
  t_maillon	*maillon;

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
  if ((maillon = create_maillon(0, 0, DOWN, (t_maillon*)NULL)) == NULL)
    return ;
  finde_maze(tab, maillon);
  free(maillon);
  print_tab(tab);
  free_tab(tab);
}
