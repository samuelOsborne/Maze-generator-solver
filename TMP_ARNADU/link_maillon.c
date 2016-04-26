/*
** link_maillon.c for lemin in /home/costa_d/Documents/CPE/lemin/CPE_2015_lemin_bootstrap
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Wed Mar 30 18:39:43 2016 Arnaud Costa
** Last update Wed Apr 13 10:53:10 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

void	link_maillon(t_maillon *maillon1, t_maillon *maillon2)
{
  maillon1->next[maillon1->id] = maillon2;
  maillon1->id++;
}
