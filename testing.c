#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
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
// char    *get_next_line(int fd)
// {
// 	static char    *savedchar = NULL;
// 	static char    *savedchar1 = NULL;
//     char        buffer[BUFFER_SIZE + 1];
//     char        *line;
//     char        *tmp;
//     char        *newline_pos;
// 	char        *newline_pos1;
//     char        *s;
// 	char		*spos;
//     ssize_t		read_ret;
    
// 	line = NULL;
//     tmp = malloc(BUFFER_SIZE + 1);
//     if (tmp == NULL)
//         return (NULL);
//     if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
//         return(NULL);
//     if (savedchar != NULL)
//     {
// 		// spos = strchr(savedchar, '\n');
// 		// char news[k + 1];
// 		// strncpy(news, savedchar, k);
// 		newline_pos1 = strchr(savedchar, '\n');
// 		if (!newline_pos1)
// 		{
// 			line = ft_strjoin(line, savedchar);
// 			savedchar = NULL;
// 		}
// 		else
// 		{
// 			size_t k = newline_pos1 - savedchar + 1;
// 			char sth[k + 1];
// 			strncpy(sth, savedchar, k);
// 			line = ft_strjoin(line, savedchar);
// 			return(line);
// 		}
//     } 
//     while ((read_ret = read(fd, buffer, BUFFER_SIZE)) > 0 && !savedchar)
//     {
//         buffer[read_ret] = '\0';
//         newline_pos = strchr(buffer, '\n');
//         if (!newline_pos)
//         {
//             strcpy(tmp, buffer);
// 			line = ft_strjoin(line, tmp);
//         }
//         else
//         {
//             strncpy(tmp, buffer, newline_pos - buffer + 1);
//             tmp[newline_pos - buffer + 1] = '\0';
//             savedchar = strdup(newline_pos + 1);
// 			if (strchr(line, '\n'))
//             	return (line);
// 			else
// 				line = ft_strjoin(line, tmp);
//         }
//     }
//     free(tmp);
//     if (read_ret == -1)
//     {
//         free(line);
//         return (NULL);
//     }
//     return (line);
// }
char *check_newline(char *s, char *ss)
{
	char *pos = strchr(s, '\n');

}

char	*get_next_line(int fd)
{
	static char	*savedchar;
	char		*line;
	char		*buffer[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	savedchar = NULL;
	tmp = malloc(BUFFER_SIZE + 1);
	if (tmp = NULL)
		return (NULL);
	if (savedchar != NULL)
	{
		
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{

	}
}
int main()
{
    int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
	//printf("%s",get_next_line(fd));
	// char *ss = get_next_line(fd);
	// char *sss = get_next_line(fd);
	// char *ssss = get_next_line(fd);
    // free(s);
    close(fd);
}
