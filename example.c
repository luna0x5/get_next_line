#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (strdup(s2));
	if (s2 == NULL)
		return (strdup(s1));
	s1len = strlen(s1);
	s2len = strlen(s2);
	s = (char *)malloc((s1len + s2len + 1) * (sizeof(char)));
	if (s == NULL)
		return (NULL);
	strcpy(s, s1);
	strcpy(s + s1len, s2);
	return (s);
}

char *get_next_line(int fd)
{
    size_t i;
    char buffer[BUFFER_SIZE + 1];
    static char *line;
    char *tmp;
	char *new_pos;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
    tmp = malloc(BUFFER_SIZE + 1);
    if (tmp == NULL)
        return NULL;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		new_pos = ft_strc

	}
    // while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
    // {
    //     buffer[i] = '\0';
	// 	i = 0;
    //     while (buffer[i] != '\n' && buffer[i] != '\0')
    //     {
    //         tmp[i] = buffer[i];
    //         i++;
    //     }
    //     tmp[i] = '\0';
	// 	if (line == NULL)
    //     	line = strdup(tmp);
    //     else
    //     {
    //         char *new_line = ft_strjoin(line, tmp);
    //         free(line);
    //         line = new_line;
    //     }
    //     if (strchr(buffer, '\n'))
    //         break ;
    // }
    // if (line && line[0] == '\0')
    // {
    //     free(line);
    //     line = NULL;
    // }
    return (line);
}

int main()
{
	int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	write(fd, "Hello this is a test\nI write into this file using write\nand this is the third line\nand this is the fourth", 105);
	lseek(fd, 0, SEEK_SET);
	char *s = get_next_line(fd);
	printf("%s\n", s);
	free(s);
	while (s != NULL)
	{
		s = get_next_line(fd);
		printf("%s\n", s);
		free(s); 
	}
	close(fd);
}
