#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
char *get_next_line(int fd);
int     ft_strlen(char *s);
int	check(char *str);
char    *ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char *ft_line_trim(char *str);
#endif

