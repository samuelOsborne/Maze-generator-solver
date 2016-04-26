/*
** print_data_des_maillons_connexes.c for lemin in /home/costa_d/Documents/CPE/lemin/CPE_2015_lemin_bootstrap
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Wed Mar 30 18:41:09 2016 Arnaud Costa
** Last update Wed Apr 13 10:53:43 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

void	print_data_des_maillons_connexes(t_maillon *maillon)
{
  int	i;

  i = 0;
  while (maillon->next[i] != NULL)
    {
      printf("%d = %d\n", i, maillon->next[i]->data);
      i++;
    }
}
