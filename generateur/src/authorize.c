/*
** authorize.c for src in /media/samuel/Home/osborn_s/rendu/init_ia/dante/generateur/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Thu May 12 17:34:05 2016 Samuel
** Last update Wed May 18 13:39:36 2016 Samuel
*/

#include <unistd.h>
#include "maze.h"

int		imp_true(char *width, char *height)
{
  int		width1;
  int		height2;

  if ((width1 = my_getnbr(width)) <= 0)
    {
      write(2, "Please enter a number larger than 0.\n", 38);
      return (1);
    }
  if ((height2 = my_getnbr(height)) <= 0)
    {
      write(2, "Please enter a number larger than 0.\n", 38);
      return (1);
    }
  imparfait(width1, height2);
  return (0);
}

int		imp_parfait(char *width, char *height)
{
  int		width1;
  int		height2;

  if ((width1 = my_getnbr(width)) <= 0)
    {
      write(2, "Please enter a number larger than 0.\n", 38);
      return (1);
    }
  if ((height2 = my_getnbr(height)) <= 0)
    {
      write(2, "Please enter a number larger than 0.\n", 38);
      return (1);
    }
  parfait(width1, height2);
  return (0);
}

int		first_check(int ac, char **av)
{
  if (ac == 4 && my_strcmp(av[3], "parfait") == 0)
    {
      if ((imp_parfait(av[1], av[2])) == 1)
	return (1);
    }
  else if (ac == 4 && my_strcmp(av[3], "imparfait") == 0)
    {
      if ((imp_true(av[1], av[2])) == 1)
	return (1);
    }
  else if (ac == 4 && my_strcmp(av[3], "imparfait") != 0
	   && my_strcmp(av[3], "parfait") != 0)
    write(2, "Usage : ./generateur x y [parfait]\n", 36);
  else
    imp_true(av[1], av[2]);
  return (0);
}
