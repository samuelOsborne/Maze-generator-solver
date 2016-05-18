/*
** maze.h for maze in /media/samuel/Home/osborn_s/rendu/init_ia/dante/mazes
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Fri Apr 29 13:41:18 2016 Samuel
** Last update Wed May 18 13:38:26 2016 Samuel
*/

#ifndef MAZE_H
# define MAZE_H

typedef struct	s_start
{
  int		x;
  int		y;
  int		r;
  int		width;
  int		height;
}		t_start;

typedef	struct	s_bot
{
  int		y;
  int		width;
  int		height;
  int		tmp;
}		t_bot;

typedef struct	s_top
{
  int		y;
  int		tmp;
  int		i;
  int		width;
  int		height;
}		t_top;

typedef struct	s_pos
{
  int		x;
  int		y;
  struct s_pos	*next;
}		t_pos;

typedef struct	s_maze
{
  char		state;
  int		x;
  int		y;
  int		walls;
}		t_maze;

typedef struct	s_split
{
  int		r;
  int		t;
  int		i;
  int		x;
  int		d;
  int		count;
}		t_split;

t_maze		**create_maze(int, int);
void		init_maze(t_maze **, int, int);
void		carve_maze(t_maze **, int, int);
void		start_route(t_maze **, int, int);
void		print_maze(t_maze **, int, int);
void		zig_lines(t_maze **, int, int);
void		free_maze(t_maze **, int);
void		end_line(t_maze **, int ,int, int);
void		bottom(t_bot *, t_maze **, int );
void		imparfait(int, int);
void		parfait(int, int);
int		first_check(int, char **);
int		my_strcmp(char *, char *);
int		my_getnbr(char *);
int		top(t_maze **, int, int, int);
int		check_for_prob(t_maze **, int, int, int);

#endif /* !MAZE_H */
