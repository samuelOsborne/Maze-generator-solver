/*
** gen_laby.c for gen_laby in /media/samuel/Home/osborn_s/rendu/init_ia/dante/gen_lab
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Fri Apr 22 17:12:21 2016 Samuel
** Last update Mon Apr 25 11:15:46 2016 Samuel
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"

void		ShowMaze(const char *maze, int width, int height)
{
  int		x;
  int		y;
  int		fd;

  y = 0;
  x = 0;
  if ((fd = open("gen", O_CREAT | O_WRONLY, 0644)) == -1)
    printf("open error\n");
  while (y < height)
    {
      x = 0;
      while (x < width)
	{
	  if (maze[y * width + x] == 1)
	    write(fd, "X", 1);
	  else if (maze[y * width + x] == 2)
	    write(fd, "o", 1);
	  else
	    write(fd, "*", 1);
	  x++;
	}
      write(fd, "\n", 1);
      y++;
    }
  close(fd);
}

void		increment(t_maze *maze, int x, int y)
{
  maze->x1 = x + maze->dx;
  maze->y1 = y + maze->dy;
  maze->x2 = maze->x1 + maze->dx;
  maze->y2 = maze->y1 + maze->dy;
}

void		maze_start(t_maze *maze)
{
  maze->dir = rand() % 4;
  maze->count = 0;
}

void		check_maze(t_maze *maze)
{
  maze->dx = 0;
  maze->dy = 0;
  if (maze->dir == 0)
    maze->dx = 1;
  else if (maze->dir == 1)
    maze->dy = 1;
  else if (maze->dir == 2)
    maze->dx = -1;
  else
    maze->dy = -1;
}

void		CarveMaze(char *mazer, int width, int height, int x, int y) 
{
  t_maze	maze;

  maze_start(&maze);
  while (maze.count < 4)
    {
      check_maze(&maze);
      increment(&maze, x, y);
      if (maze.x2 > 0 && maze.x2 < width && maze.y2 > 0 
	  && maze.y2 < height && mazer[maze.y1 * width + maze.x1] == 1 
	  && mazer[maze.y2 * width + maze.x2] == 1)
	{
	  mazer[maze.y1 * width + maze.x1] = 0;
	  mazer[maze.y2 * width + maze.x2] = 0;
	  x = maze.x2;
	  y = maze.y2;
	  maze.dir = rand() % 4;
	  maze.count = 0;
	}
      else
	{
	  maze.dir = (maze.dir + 1) % 4;
	  maze.count += 1;
	}
    }
}

/* Generate maze in matrix maze with size width, height. */
void	GenerateMaze(char *maze, int width, int height)
{
  int	x;
  int	y;

  x = 0;
  y = 1;
  while (x < width * height)
    {
      maze[x] = 1;
      x++;
    }
  maze[width + 1] = 0;
  srand(time(0));
  while (y < height)
    {
      x = 1;
      while (x < width)
	{
	  CarveMaze(maze, width, height, x, y);
	  x += 2;
	}
      y += 2;
    }
  maze[0 * width + 1] = 0;
  maze[(height - 1) * width + (width - 2)] = 0;
}

void	solve_start(t_solve *solve, int width, int height, char *maze)
{
  maze[0 * width + 1] = 1;
  maze[(height - 1) * width + (width - 2)] = 1;
  solve->forward = 1;
  solve->dir = 0;
  solve->count = 0;
  solve->x = 1;
  solve->y = 1;
}

void	solve_check(t_solve *solve)
{
  if (solve->dir == 0)
    solve->dx = 1;
  else if (solve->dir == 1)
    solve->dy = 1;
  else if (solve->dir == 2)
    solve->dx = -1;
  else
    solve->dy = -1;
}

void	solve_increment(t_solve *solve)
{
  solve->x += solve->dx;
  solve->y += solve->dy;
  solve->forward = 1;
  solve->count = 0;
  solve->dir = 0;
}

void	second_solve_check(t_solve *solve)
{
  solve->dir = (solve->dir + 1) % 4;
  solve->count += 1;
  if (solve->count > 3)
    {
      solve->forward = 0;
      solve->count = 0;
    }
}

void	SolveMaze(char *maze, int width, int height)
{
  t_solve	solve;

  /* Remove the entry and exit. */
  solve_start(&solve, width, height, maze);
  while(solve.x != width - 2 || solve.y != height - 2)
    {
      solve.dx = 0; 
      solve.dy = 0;
      solve_check(&solve); /*the starting block is filled in */
      if((solve.forward && maze[(solve.y + solve.dy)
				* width + (solve.x + solve.dx)] == 0)
	 || (!solve.forward && maze[(solve.y + solve.dy)
				    * width + (solve.x + solve.dx)] == 2))
	{
	  maze[solve.y * width + solve.x] = solve.forward ? 2 : 3;
	  solve_increment(&solve);
 	}
      else
	second_solve_check(&solve);
    }
  /* Replace the entry and exit. */
  maze[(height - 2) * width + (width - 2)] = 2;
  maze[(height - 1) * width + (width - 2)] = 2;
}

int	check_args(int width, int height, int argc, char **argv)
{
  if (width < 7 || height < 7)
    {
      printf("error: illegal maze size\n");
      return (1);
    }
  if (argc == 4 && argv[3][0] != 's')
    {
      printf("error: invalid argument\n");
      return (1);
    }
  return (0);
}

int	main(int argc,char **argv)
{
  int	width;
  int	height;
  char	*maze;

  if (argc != 3 && argc != 4)
    {
      printf("usage: maze <width> <height> [s]\n");
      return (0);
    }
   width = my_getnbr(argv[1]) * 2 + 3;
   height = my_getnbr(argv[2]) * 2 + 3;
   if ((check_args(width, height, argc, argv)) == 1)
     return (1);
   if ((maze = malloc(width * height * sizeof(char))) == NULL)
     return (0);
   GenerateMaze(maze, width, height);
   ShowMaze(maze, width, height);
   if (argc == 4)
     {
       SolveMaze(maze, width, height);
       ShowMaze(maze, width, height);
     }
   free(maze);
   return (0);
}