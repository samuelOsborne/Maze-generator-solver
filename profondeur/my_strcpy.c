/*
** my_strcpy.c for dante in /home/costa_d/Documents/IA/dante/graphs/TMP_ARNADU
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Apr 26 12:54:27 2016 Arnaud Costa
** Last update Tue Apr 26 12:56:00 2016 Arnaud Costa
*/

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
