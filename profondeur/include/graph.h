/*
** my.h for lemin in /home/costa_d/Documents/CPE/lemin/CPE_2015_lemin_bootstrap
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Wed Mar 30 16:37:41 2016 Arnaud Costa
** Last update Wed May 18 16:27:35 2016 Samuel
*/

#ifndef MY_GRAPH_H_
# define MY_GRAPH_H_

#define LEFT 1
#define RIGHT 2
#define UP 4
#define DOWN 3

typedef struct		s_maillon
{
  int			x;
  int			y;
  int			id;
  int			side;
  struct s_maillon	**next;
  struct s_maillon	*parent;
}			t_maillon;

t_maillon	*create_maillon(int x, int y, int side, t_maillon *parent);
t_maillon	**update_tab_posi(t_maillon **pos);
t_maillon	**add_tab_posi(t_maillon **posi, t_maillon *tmp, char **m);
int		find_node(t_maillon **tab, t_maillon *nodes2);
int		my_strlen(char *str);
int		carve_tab(t_maillon *node, char **map);
int		check_direction(t_maillon *tmp, char **m, int t);
int		m_str(char *str);
void		memset_tab(t_maillon **posi, int max);
void		my_putstr(char *str);
void		get_maze(int fd);
void		print_tab(char **tab);
void		print_maillon(t_maillon *maillon);
void		link_maillon(t_maillon *maillon1, t_maillon *maillon2);
void		print_data_des_maillons_connexes(t_maillon *maillon);
void		free_tab(char **tab);
char		*my_strcpy(char *dest, char *src);
int		h_tab(char **tab);
char		**my_realloc_tab(char **tab);
void		get_maze(int fd);
char		**tab_cpy(char **tab_src);

#endif /* MY_GRAPH_H_ */
