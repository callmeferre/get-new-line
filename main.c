#include "get_next_line.h"

int   main(int ac, char **av)
{
  int   fd1;
  int   fd2;
  char *line;
if (ac)
{
  fd1 = open(av[1], O_RDONLY);
  fd2 = open(av[2], O_RDONLY);
  /*printf("%s\n", get_next_line(fd2));//-------------------------
  printf("%s\n", get_next_line(fd1));//
  printf("%s\n", get_next_line(fd1));//
  printf("%s\n", get_next_line(fd2));//
  printf("%s\n", get_next_line(fd2));//
  printf("%s\n", get_next_line(fd1));//
  printf("%s\n", get_next_line(fd2));//
  printf("%s\n", get_next_line(fd1));//
  printf("%s\n", get_next_line(fd1));//
  printf("%s\n", get_next_line(fd2));//*/
  line = get_next_line(fd1);
  while (line)
  {
      printf("%s\n", line);
      free(line);
      line = get_next_line(fd1);
  }
  free(line);
  return (0);
}
  
}
