/*
** main.c for lemin in /home/costa_d/Documents/CPE/lemin/CPE_2015_lemin_bootstrap
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Wed Mar 30 16:43:05 2016 Arnaud Costa
** Last update Sun Apr 17 15:29:42 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

t_maillon	*build_my_graph()
{
  t_maillon	*graph;
  t_maillon     *elem0;
  t_maillon     *elem1;
  t_maillon     *elem2;
  t_maillon     *elem3;
  t_maillon     *elem4;
  t_maillon     *elem5;
  t_maillon     *elem6;
  t_maillon     *elem7;

  graph = create_maillon(0);
  elem0 = create_maillon(42);
  elem1 = create_maillon(60012);
  elem2 = create_maillon(30012);
  elem3 = create_maillon(48);
  elem4 = create_maillon(50012);
  elem5 = create_maillon(3);
  elem6 = create_maillon(98);
  elem7 = create_maillon(8);
  link_maillon(graph, elem0);
  link_maillon(elem0, elem1);
  link_maillon(elem0, elem2);
  link_maillon(elem1, elem3);
  link_maillon(elem3, elem4);
  link_maillon(elem4, elem5);
  link_maillon(elem4, elem6);
  link_maillon(elem2, elem7);
  print_my_graph_data(graph);
  return (graph);
}

void	print_my_graph_data(t_maillon *graph)
{
  int	i;

  i = 0;
  print_maillon(graph);
  while (graph->next[i] != NULL)
    {
      print_my_graph_data(graph->next[i]);
      i++;
    }
}

int	main()
{
  t_maillon	*elem0;

  elem0 = build_my_graph();
}
