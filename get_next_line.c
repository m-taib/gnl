#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char    *ft_strdup(char *s1)
{
        char    *ptr;
        int             i;
        if (!s1)
                return (0);
        i = 0;
        ptr = malloc(ft_strlen(s1) + 1);
        if (!ptr)
                return (NULL);
        while (s1[i])
        {
                ptr[i] = s1[i];
                i++;
        }
        ptr[i] = '\0';
        return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	
	if (!s1)
        {
                s1 = malloc(1 * sizeof(char));
                if (!s1)
                        return (0);
                s1[0] = 0;
        }	
	if (!s2)
	{
		free(s1);
		return (0);
	}
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char *ft_line_trim(char *str)
{
	int	i;
	char *line;
	i = 0;
	if (!str[0])
                return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);

}
char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);	
	while (*s && *(unsigned char *)s != (unsigned char)c)
		s++;
	if (*(unsigned char *)s == (unsigned char)c)
		return ((char *)s + 1);
	if (*s == '\0')
		return (s);
	return (0);
}
char    *reminder(char *line)
{
        char    *str;
	
	if (line[0] == '\0')
        {
                free(line);
                return (0);
        }
        str = ft_strdup(ft_strchr(line,'\n'));
	free(line);
        return (str);
}

int	check(char *str)
{
	int	i;
	i = 0;
	if (!str)
		return(1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char *line_readed(int fd,char *line)
{
	char 	str[BUFFER_SIZE + 1];
	int	n;
	
	n = 1;
	while (n && check(line))
        {
                n = read(fd, str, BUFFER_SIZE);
                if (n < 0)
                        return (0);
                str[n] = '\0';
                line = ft_strjoin(line, str);
        }
	return (line);

}

char *get_next_line(int fd)
{
	static char 	*line[100];
	char		*newline;
	char	str[BUFFER_SIZE+1];
	int	n;
	if (fd < 0 || BUFFER_SIZE == 0 ) 
		return (0);
	n = 1;
	newline = 0;
	line[fd] = line_readed(fd,line[fd]);
	if (!line[fd])
		return (0);
	newline = ft_line_trim(line[fd]);
	line[fd] = reminder(line[fd]);
	return (newline);
}
#include <stdio.h>
#include <fcntl.h>
int     main()
{

        int fd = open("file1",O_RDONLY);
        char *test;
        test = get_next_line(fd);
        printf("%s",test);
        free(test);
        test = get_next_line(fd);
        printf("%s",test);
        free(test);
        test = get_next_line(fd);
        printf("%s",test);
        free(test);
        test = get_next_line(fd);
        printf("%s",test);
        free(test);
        return (0);
}

