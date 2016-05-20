/*
** my_strcpy.c for dante in /home/costa_d/Documents/IA/dante/graphs/TMP_ARNADU
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Apr 26 12:54:27 2016 Arnaud Costa
** Last update Fri May 20 13:29:09 2016 Arnaud Costa
*/

#include <stdlib.h>
#include "graph.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src && src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	**tab_cpy(char **tab_src)
{
  char	**tab_dest;
  int	i;

  i = 0;
  if ((tab_dest = malloc(sizeof(char *) * (h_tab(tab_src) + 1))) == NULL)
    return (NULL);
  while (tab_src[i] != NULL)
    {
      if ((tab_dest[i] = malloc(sizeof(char) *
				(m_str(tab_src[i]) + 1))) == NULL)
	return (NULL);
      my_strcpy(tab_dest[i], tab_src[i]);
      i++;
    }
  tab_dest[i] = NULL;
  return (tab_dest);
}
