/*
** check_for_prob.c for src in /media/samuel/Home/osborn_s/rendu/init_ia/dante/generateur/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Thu May 12 16:46:04 2016 Samuel
** Last update Thu May 12 16:47:20 2016 Samuel
*/

#include "maze.h"

int		check_for_prob(t_maze **maze, int r, int height, int y)
{
  if (maze[y][r].state == 'X')
    {
      while (y < height)
	maze[y++][r].state = 'X';
      return (1);
    }
  return (0);
}
