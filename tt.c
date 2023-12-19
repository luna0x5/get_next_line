#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
# define BUFFER_SIZE 10
char    *ft_strjoin(char *s1, char *s2)
{
    size_t    s1len;
    size_t    s2len;
    char    *s;
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
char    *get_next_line(int fd)
{
    char    *res;
    char    *line = NULL;
    char    *tmp;
    static char    *saved = NULL;
    char    *newline_pos;
    if (saved != NULL)
    {
        res = strchr(saved, '\n');
        if (res)
        {
            size_t j = res - saved + 1;
            char *s = malloc(strlen(saved) - j + 1);
            if (s == NULL)
                return (NULL);
            // size_t    i = 0;
            // while (saved[i] != '\n')
            // {
            //     s[i] = saved[i];
            //     i++;
            // }
            // s[i] = '\n';
			// s[i + 1] = '\0';
			strncpy(s, saved, j);
            //line = ft_strjoin(line, s);
            saved = res + 1;
            return (s);
        }
        else
        {
            line = ft_strjoin(line, saved);
            saved = NULL;
        }
    }
    tmp = malloc(BUFFER_SIZE + 1);
    if (!tmp)
        return (NULL);
    char buffer[BUFFER_SIZE + 1];
    int count;
    while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[count] = '\0';
        newline_pos = strchr(buffer, '\n');
        if (!newline_pos)
        {
            strcpy(tmp, buffer);
            line = ft_strjoin(line, tmp);
        }
        else
        {
            strncpy(tmp, buffer, newline_pos - buffer + 1);
            tmp[newline_pos - buffer + 1] = '\0';
            if (*(newline_pos + 1) != '\0')
                saved = strdup(newline_pos + 1);
            else
                saved = NULL;
            line = ft_strjoin(line, tmp);
            return(line);
        }
    }
    return (line);
}
// void f(void)
// {
// 	system("leaks a.out");
// }
int main()
{
	// atexit(f);
	//printf("anything");
	int i = 1;
    int fd = open("test1.txt", O_CREAT | O_RDWR, 0777);
    // write(fd, "Hello this is a test\nheey", 25);
    // lseek(fd, 0, SEEK_SET);
	// line = get_next_line(fd);
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	char *line;
	// line = get_next_line(fd);
	// printf("%s", line);
	// while (line)
	// {

    // 	printf("%d :==> %s", i, line);
	// 	//free(line);
	// 	line = get_next_line(fd);
	// 	i++;
	// }
	while (i < 128)
	{
		printf("%d :==> %s", i, get_next_line(fd));
		i++;
	}
    // close(fd);
}
