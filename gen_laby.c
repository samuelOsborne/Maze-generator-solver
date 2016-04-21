/* Maze generator in C.
 * Joe Wingbermuehle
 * 19990805
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

/* Display the maze. */
void ShowMaze(const char *maze, int width, int height) 
{	
  int x, y, fd;
  
  if ((fd = open("gen", O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
    printf("open error\n");
  for(y = 0; y < height; y++) 
    {
      for(x = 0; x < width; x++) 
	{
	  if (maze[y * width + x] == 1)
	    write(fd, "[]", 2);
	  else if (maze[y * width + x] == 2)
	    write(fd, "<>", 2);
	  else
	    write(fd, "  ", 2);
	  /* switch(maze[y * width + x])  */
	  /*   { */
	  /*   case 1:   write(fd, "[]", 2; break; */
	  /*   case 2:   write(fd, "<>", 2); break; */
	  /*   default:  write(fd, "  ", 2); break; */
		/* case 1:  printf("[]");  break; */
		/* case 2:  printf("<>");  break; */
		/* default: printf("  ");  break; */
	}
      printf("\n");
    }
  close(fd);
}

void CarveMaze(char *maze, int width, int height, int x, int y) {

  int	x1;
  int	y1;
  int	x2;
  int	y2;
  int	dx;
  int	dy;
  int	dir;
  int	count;

  dir = rand() % 4;
  count = 0;
  while (count < 4)
    {
      dx = 0;
      dy = 0;
      if (dir == 0)
	dx = 1;
      else if (dir == 1)
	dy = 1;
      else if (dir == 2)
	dx = -1;
      else
	dy = -1;
      x1 = x + dx;
      y1 = y + dy;
      x2 = x1 + dx;
      y2 = y1 + dy;
      if (x2 > 0 && x2 < width && y2 > 0 && y2 < height && maze[y1 * width + x1] == 1 && maze[y2 * width + x2] == 1)
	{
	  maze[y1 * width + x1] = 0;
	  maze[y2 * width + x2] = 0;
	  x = x2;
	  y = y2;
	  dir = rand() % 4;
	  count = 0;
	}
      else
	{
	  dir = (dir + 1) % 4;
	  count += 1;
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
  maze[1 * width + 1] = 0;
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

/* Solve the maze. */
void SolveMaze(char *maze, int width, int height) {

  int dir, count;
  int x, y;
  int dx, dy;
  int forward;

  /* Remove the entry and exit. */
  maze[0 * width + 1] = 1;
  maze[(height - 1) * width + (width - 2)] = 1;
  forward = 1;
  dir = 0;
  count = 0;
  x = 1;
  y = 1;
  while(x != width - 2 || y != height - 2) {
    dx = 0; dy = 0;
    switch(dir) {
    case 0:  dx = 1;  break;
    case 1:  dy = 1;  break;
    case 2:  dx = -1; break;
    default: dy = -1; break;
    }
    if(   (forward  && maze[(y + dy) * width + (x + dx)] == 0)
	  || (!forward && maze[(y + dy) * width + (x + dx)] == 2)) {
      maze[y * width + x] = forward ? 2 : 3;
      x += dx;
      y += dy;
      forward = 1;
      count = 0;
      dir = 0;
    } else {
      dir = (dir + 1) % 4;
      count += 1;
      if(count > 3) {
	forward = 0;
	count = 0;
      }
    }
  }
  /* Replace the entry and exit. */
  maze[(height - 2) * width + (width - 2)] = 2;
  maze[(height - 1) * width + (width - 2)] = 2;
}

int	main(int argc,char **argv)
{

  int	width;
  int	height;
  char *maze;

  if (argc != 3 && argc != 4)
    {
      printf("usage: maze <width> <height> [s]\n");
      exit(EXIT_FAILURE);
    }
   /* Get and validate the size. */
   width = my_getnbr(argv[1]) * 2 + 3;
   height = my_getnbr(argv[2]) * 2 + 3;
   if (width < 7 || height < 7)
     {
       printf("error: illegal maze size\n");
       exit(EXIT_FAILURE);
     }
   if (argc == 4 && argv[3][0] != 's')
     {
       printf("error: invalid argument\n");
       exit(EXIT_FAILURE);
     }
   /* Allocate the maze array. */
   maze = (char*)malloc(width * height * sizeof(char));
   if (maze == NULL)
     {
       printf("error: not enough memory\n");
       exit(EXIT_FAILURE);
     }
   /* Generate and display the maze. */
   GenerateMaze(maze, width, height);
   ShowMaze(maze, width, height);
   /* Solve the maze if requested. */
   if (argc == 4)
     {
       SolveMaze(maze, width, height);
       ShowMaze(maze, width, height);
     }
   /* Clean up. */
   free(maze);
   exit(EXIT_SUCCESS);
}
