/*
** my.h for lemin in /home/costa_d/Documents/CPE/lemin/CPE_2015_lemin_bootstrap
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Wed Mar 30 16:37:41 2016 Arnaud Costa
** Last update Mon Apr 25 18:07:59 2016 Arnaud Costa
*/

#ifndef MY_GRAPH_H_
# define MY_GRAPH_H_

typedef struct		s_maillon
{
  int			x;
  int			y;
  int			id;
  struct s_maillon	**next;
}			t_maillon;

t_maillon	*create_maillon(int x, int y);
void		print_maillon(t_maillon *maillon);
void		link_maillon(t_maillon *maillon1, t_maillon *maillon2);
void		print_data_des_maillons_connexes(t_maillon *maillon);

#endif /* MY_GRAPH_H_ */
