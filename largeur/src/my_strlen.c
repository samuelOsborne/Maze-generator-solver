/*
** my_strlen.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Apr 26 13:27:24 2016 Arnaud Costa
** Last update Wed May 18 15:57:38 2016 Samuel
*/

#include "graph.h"

int	m_str(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    i++;
  return (i);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    i++;
  return (i);
}
