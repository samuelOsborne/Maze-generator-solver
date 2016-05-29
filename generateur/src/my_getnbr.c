/*
** my_getnbr.c for tetris in /home/costa_d/Documents/test_ncurses
** 
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
** 
** Started on  Fri Feb 26 16:42:24 2016 Arnaud Costa
** Last update Sun May 29 15:20:57 2016 Samuel
*/

int	my_getnbr(char *str)
{
  int	i;
  int	res;
  int	type;

  type = 1;
  i = 0;
  res = 0;
  if (str[0] == '-')
    {
      i++;
      type = 0;
    }
  while (str[i] != '\0')
    {
      if (str[i] < 48 || str[i] >= 57)
	return (-666);
      str[i] = str[i] - 48;
      res = res + str[i];
      if (str[i + 1] != '\0')
	res = res * 10;
      i++;
    }
  if (type == 0)
    res = res * -1;
  return (res);
}
