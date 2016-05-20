/*
** my_strlen.c for dante in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Apr 26 13:27:24 2016 Arnaud Costa
** Last update Fri May 20 13:31:20 2016 Arnaud Costa
*/

int	m_str(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    i++;
  return (i);
}
