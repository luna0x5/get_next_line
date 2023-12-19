// #include <unistd.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include "get_next_line.h"

// // int main()
// // {
// // 	int fd = creat("text.txt", 0777);
// // 	int fd1 = creat("text1.txt", 0777);
// // 	int fd2 = dup(1);
// // 	write(fd, "hello this is a test", 20);
// // 	write(fd1, "hello this is a test1", 21);
// // 	write(fd2, "hello this is a test2", 21);
// // 	write(1, "\nthis is a second testo", 23);
// // 	printf("\n%d\n", fd);
// // 	printf("%d\n", fd1);
// // 	printf("%d\n", fd2);
// // }

// // int main()
// // {
// // 	int fd = creat("text.txt", 0777);
// // 	//int fd1 = creat("text1.txt", 0777);
// // 	printf("%dbefore\n", fd);
// // 	write(2, "hello this is a test", 20);
// // 	//write(fd1, "hello this is a test1", 21);
// // 	//printf("%d\n", fd1);
// // 	dup2(fd, 2);
// // 	printf("%d\n", fd);
// // 	write(2, "hello this is a test", 20);
// // 	//write(fd1, "hello this is a test1", 21);
// // 	//printf("%d\n", fd1);
	
// // }

// // int main()
// // {
// // 	int fd = open("txt.txt",O_CREAT | O_RDWR);
// // 	write(fd, "hello this is a test", 20);
// // 	lseek(fd, 0, SEEK_SET);
// // 	char *s;
// // 	int i = read(fd, s, 10);
// // 	printf("the buff : %s\n", s);
// // 	printf("return : %d\n", i);
// // }

// // int main()
// // {
// // 	int fd = open("test.txt", O_CREAT | O_RDWR);
// // 	printf("my fd is -> %d\n", fd);
// // 	char *s = malloc(2000);
// // 	int count = read(fd, s, 2000);
// // 	printf("my buffer contains : %s\n", s);
// // 	printf("how much I read : %d\n", count);
// // 	free(s);
// // }

// // char *read_line(int fd)
// // {
// //     char *line;
// //     char *temp;
// //     char c;
// //     size_t currentLength;
// //     int bytesRead;

// //     line = NULL;
// //     while ((bytesRead = read(fd, &c, 1)) > 0)
// //     {
// //         currentLength = 0;
// //         if (c == '\n')
// //             break;
// //         if (line == NULL)
// //             currentLength = 0;
// //         else
// //             currentLength = strlen(line);

// //         temp = malloc(currentLength + 2);
// //         if (temp == NULL)
// //             return (NULL);
// //         if (line != NULL)
// //             strcpy(temp, line);
// //         temp[currentLength] = c;
// //         temp[currentLength + 1] = '\0';
// //         line = temp;
// //     }
// //     if (bytesRead == -1)
// //         return (NULL);
// //     return (line);
// // }

// // int main(void)
// // {
// //     char *line;

// //     int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
// // 	write(fd, "Hello this is a test\nI write into this file using write\nand this is the third line\nand this is the fourth", 105);
// // 	lseek(fd, 0, SEEK_SET);
// //     while ((line = read_line(fd)) != NULL)
// //     {
// //         printf("%s\n", line);
// //     }
// //     close(fd);
// // }
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <fcntl.h>
// #include <stdio.h>
// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 100
// #endif
// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	s1len;
// 	size_t	s2len;
// 	char	*s;

// 	if (s1 == NULL && s2 == NULL)
// 		return (NULL);
// 	if (s1 == NULL)
// 		return (strdup(s2));
// 	if (s2 == NULL)
// 		return (strdup(s1));
// 	s1len = strlen(s1);
// 	s2len = strlen(s2);
// 	s = (char *)malloc((s1len + s2len + 1) * (sizeof(char)));
// 	if (s == NULL)
// 		return (NULL);
// 	strcpy(s, s1);
// 	strcpy(s + s1len, s2);
// 	return (s);
// }

// char *get_next_line(int fd)
// {
//     size_t i;
//     char buffer[BUFFER_SIZE + 1];
//     static char *line;
//     char *tmp;
// 	char *new_pos;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 		return (NULL);
// 	line = NULL;
//     tmp = malloc(BUFFER_SIZE + 1);
//     if (tmp == NULL)
//         return NULL;
//     while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
//     {
//         buffer[i] = '\0';
// 		i = 0;
//         while (buffer[i] != '\n' && buffer[i] != '\0')
//         {
//             tmp[i] = buffer[i];
//             i++;
//         }
//         tmp[i] = '\0';
// 		if (line == NULL)
//         	line = strdup(tmp);
//         else
//         {
//             char *new_line = ft_strjoin(line, tmp);
//             free(line);
//             line = new_line;
//         }
//         if (strchr(buffer, '\n'))
//             break ;
//     }
//     if (line && line[0] == '\0')
//     {
//         free(line);
//         line = NULL;
//     }
//     return (line);
// }

// int main()
// {
// 	int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
// 	write(fd, "Hello this is a test\nI write into this file using write\nand this is the third line\nand this is the fourth", 105);
// 	lseek(fd, 0, SEEK_SET);
// 	char *s = get_next_line(fd);
// 	printf("%s\n", s);
// 	free(s);
// 	while (s != NULL)
// 	{
// 		s = get_next_line(fd);
// 		printf("%s\n", s);
// 		free(s); 
// 	}
// 	close(fd);
// }
// #include <libc.h>
// #include "get_next_line.h"
// char    *ft_strjoin(char *s1, char *s2)
// {
//     size_t    s1len;
//     size_t    s2len;
//     char    *s;
//     if (s1 == NULL && s2 == NULL)
//         return (NULL);
//     if (s1 == NULL)
//         return (strdup(s2));
//     if (s2 == NULL)
//         return (strdup(s1));
//     s1len = strlen(s1);
//     s2len = strlen(s2);
//     s = (char *)malloc((s1len + s2len + 1) * (sizeof(char)));
//     if (s == NULL)
//         return (NULL);
//     strcpy(s, s1);
//     strcpy(s + s1len, s2);
//     return (s);
// }
// char	*get_next_line(int fd)
// {
// 	char	*res;
// 	char	*line = NULL;
// 	char	buffer[BUFFER_SIZE + 1];
// 	char	*tmp;
// 	static char	*saved = NULL;
// 	char	*newline_pos;

// 	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
// 		return (NULL);
// 	if (saved != NULL)
// 	{
// 		res = strchr(saved, '\n');
// 		if (res && *(res + 1) != '\0')
// 		{
// 			size_t j = res - saved + 1;
// 			char *s = malloc(strlen(saved) - j + 1);
// 			if (s == NULL)
// 				return (NULL);
// 			size_t	i = 0;
// 			while (saved[i] != '\n')
// 			{
// 				s[i] = saved[i];
// 				i++;
// 			}
// 			s[i] = '\n';
// 			line = ft_strjoin(line, s);
// 			//saved = NULL;
// 			saved = res + 1;
// 			return (line);
// 		}
// 		else
// 		{
// 			line = ft_strjoin(line, saved);
// 			saved = NULL;
// 		}
// 	}
// 	tmp = malloc(BUFFER_SIZE + 1);
// 	if (!tmp)
// 		return (NULL);
// 	while (read(fd, buffer, BUFFER_SIZE) > 0)
// 	{
// 		buffer[BUFFER_SIZE] = '\0';

// 		newline_pos = strchr(buffer, '\n');
// 		if (!newline_pos)
// 		{
// 			strcpy(tmp, buffer);
// 			line = ft_strjoin(line, tmp);
// 		}
// 		else
// 		{
// 			strncpy(tmp, buffer, newline_pos - buffer + 1);
// 			tmp[newline_pos - buffer + 1] = '\0';
// 			if (*(newline_pos + 1) != '\0')
// 				saved = strdup(newline_pos + 1);
// 			else
// 				saved = NULL;
// 			line = ft_strjoin(line, tmp);
// 			//return (line);
// 		}
// 		if (strchr(buffer, '\n'))
//             break ;
// 	}
// 	return (line);
// }
// int main()
// {

//     int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     close(fd);
// }

// // 8299999

// #include "get_next_line.h"
// #include <stdio.h>
// char	*get_next_line(int fd)
// {
// 	static char	*savedchar;
// 	char		buffer[BUFFER_SIZE + 1];
// 	char		*line;
// 	char		*tmp;
// 	char		*newline_pos;
// 	char		*s;
// 	int			read_ret;
// 	int count = 0;
// 	line = NULL;
// 	tmp = malloc(BUFFER_SIZE + 1);
// 	if (tmp == NULL)
// 		return (NULL);
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
// 		return (NULL);
// 	if (savedchar != NULL)
// 	{
// 		line = ft_strjoin(line, savedchar);
// 		savedchar = NULL;
// 	}
// 	while ((read_ret = read(fd, buffer, BUFFER_SIZE)) > 0)
// 	{
// 			count++;
// 			printf("%d\n", count);
// 		buffer[read_ret] = '\0';
// 		newline_pos = ft_strchr(buffer, '\n');
// 		if (!newline_pos)
// 		{
// 			ft_strcpy(tmp, buffer);
// 			if (line == NULL)
// 				line = ft_strdup(tmp);
// 			else
// 			{
// 				s = ft_strjoin(line, tmp);
// 				free(line);
// 				line = s;
// 			}
// 		}
// 		else
// 		{
// 			ft_strncpy(tmp, buffer, newline_pos - buffer);
// 			tmp[newline_pos - buffer] = '\0';
// 			savedchar = ft_strdup(newline_pos + 1);
// 			if (line == NULL)
// 				line = ft_strdup(tmp);
// 			else
// 			{
// 				s = ft_strjoin(line, tmp);
// 				free(line);
// 				line = s;
// 			}
// 			free(tmp);
// 			return (line);
// 		}
// 	}
// 	free(tmp);
// 	if (read_ret == -1)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	return (line);
// }
// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
//     int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
//     // write(fd, "Hello this is a test\nI write into this file using write\nand this is the third line\nand this is the fourth", 105);
//     // lseek(fd, 0, SEEK_SET);
//     char *s = get_next_line(fd);
// 	// char *ss = get_next_line(fd);
// 	// char *sss = get_next_line(fd);
// 	// char *ssss = get_next_line(fd);
//     printf("%s\n", s);
// 	// printf("%s\n", ss);
// 	// printf("%s\n", sss);
// 	// printf("%s\n", ssss);
//     free(s);
//     close(fd);
// }

// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <fcntl.h>
// #include <stdio.h>
// # define BUFFER_SIZE 10
// char    *ft_strjoin(char *s1, char *s2)
// {
//     size_t    s1len;
//     size_t    s2len;
//     char    *s;
//     if (s1 == NULL && s2 == NULL)
//         return (NULL);
//     if (s1 == NULL)
//         return (strdup(s2));
//     if (s2 == NULL)
//         return (strdup(s1));
//     s1len = strlen(s1);
//     s2len = strlen(s2);
//     s = (char *)malloc((s1len + s2len + 1) * (sizeof(char)));
//     if (s == NULL)
//         return (NULL);
//     strcpy(s, s1);
//     strcpy(s + s1len, s2);
//     return (s);
// }
// char    *get_next_line(int fd)
// {
//     char    *res;
//     char    *line = NULL;
//     // char    buffer[BUFFER_SIZE + 1];
//     char    *tmp;
//     static char    *saved = NULL;
//     char    *newline_pos;
//     if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
//         return (NULL);
//     if (saved != NULL)
//     {
// 		char	*s;
//         res = strchr(saved, '\n');
//         if (res && *(res + 1) != '\0')
//         {
//             size_t j = res - saved + 1;
//             s = malloc(strlen(saved) - j + 1);
//             if (s == NULL)
//                 return (NULL);
//             size_t    i = 0;
//             while (saved[i] != '\n')
//             {
//                 s[i] = saved[i];
//                 i++;
//             }
//             s[i] = '\n';
//             line = ft_strjoin(line, s);
//             saved = res + 1;
//             return (line);
//         }
//         else
//         {
//             line = ft_strjoin(line, saved);
//             saved = NULL;
//         }
//     }
// 	char *buffer;
// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (buffer == NULL)
// 		return (NULL);
//     tmp = malloc(BUFFER_SIZE + 1);
//     if (!tmp)
//         return (NULL);
//     while (read(fd, buffer, BUFFER_SIZE) > 0)
//     {
//         buffer[BUFFER_SIZE] = '\0';
//         newline_pos = strchr(buffer, '\n');
//         if (!newline_pos)
//         {
//             strcpy(tmp, buffer);
//             line = ft_strjoin(line, tmp);
//         }
//         else
//         {
//             strncpy(tmp, buffer, newline_pos - buffer + 1);
//             tmp[newline_pos - buffer + 1] = '\0';
//             if (*(newline_pos + 1) != '\0')
//                 saved = strdup(newline_pos + 1);
//             else
//                 saved = NULL;
//             line = ft_strjoin(line, tmp);
// 			return(line);
//         }
		 
//         // if (strchr(buffer, '\n'))
//         //     break ;
//     }
//     return (line);
// }
// int main()
// {
//     int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
//     write(fd, "Hello this is a test\nheey", 25);
//     lseek(fd, 0, SEEK_SET);
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     close(fd);
// }

// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <fcntl.h>
// #include <stdio.h>

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 1
// #endif
// char    *ft_strjoin(char *s1, char *s2)
// {
//     size_t    s1len;
//     size_t    s2len;
//     char    *s;
//     if (s1 == NULL && s2 == NULL)
//         return (NULL);
//     if (s1 == NULL)
//         return (strdup(s2));
//     if (s2 == NULL)
//         return (strdup(s1));
//     s1len = strlen(s1);
//     s2len = strlen(s2);
//     s = (char *)malloc((s1len + s2len + 1) * (sizeof(char)));
//     if (s == NULL)
//         return (NULL);
//     strcpy(s, s1);
//     strcpy(s + s1len, s2);
//     return (s);
// }
// // char    *get_next_line(int fd)
// // {
// // 	static char    *savedchar = NULL;
// // 	static char    *savedchar1 = NULL;
// //     char        buffer[BUFFER_SIZE + 1];
// //     char        *line;
// //     char        *tmp;
// //     char        *newline_pos;
// // 	char        *newline_pos1;
// //     char        *s;
// // 	char		*spos;
// //     ssize_t		read_ret;
    
// // 	line = NULL;
// //     tmp = malloc(BUFFER_SIZE + 1);
// //     if (tmp == NULL)
// //         return (NULL);
// //     if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
// //         return(NULL);
// //     if (savedchar != NULL)
// //     {
// // 		// spos = strchr(savedchar, '\n');
// // 		// char news[k + 1];
// // 		// strncpy(news, savedchar, k);
// // 		newline_pos1 = strchr(savedchar, '\n');
// // 		if (!newline_pos1)
// // 		{
// // 			line = ft_strjoin(line, savedchar);
// // 			savedchar = NULL;
// // 		}
// // 		else
// // 		{
// // 			size_t k = newline_pos1 - savedchar + 1;
// // 			char sth[k + 1];
// // 			strncpy(sth, savedchar, k);
// // 			line = ft_strjoin(line, savedchar);
// // 			return(line);
// // 		}
// //     } 
// //     while ((read_ret = read(fd, buffer, BUFFER_SIZE)) > 0 && !savedchar)
// //     {
// //         buffer[read_ret] = '\0';
// //         newline_pos = strchr(buffer, '\n');
// //         if (!newline_pos)
// //         {
// //             strcpy(tmp, buffer);
// // 			line = ft_strjoin(line, tmp);
// //         }
// //         else
// //         {
// //             strncpy(tmp, buffer, newline_pos - buffer + 1);
// //             tmp[newline_pos - buffer + 1] = '\0';
// //             savedchar = strdup(newline_pos + 1);
// // 			if (strchr(line, '\n'))
// //             	return (line);
// // 			else
// // 				line = ft_strjoin(line, tmp);
// //         }
// //     }
// //     free(tmp);
// //     if (read_ret == -1)
// //     {
// //         free(line);
// //         return (NULL);
// //     }
// //     return (line);
// // }
// char *check_newline(char *s, char *ss)
// {
// 	char *pos = strchr(s, '\n');

// }

// char	*get_next_line(int fd)
// {
// 	static char	*savedchar;
// 	char		*line;
// 	char		*buffer[BUFFER_SIZE + 1];
// 	char		*tmp;

// 	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	line = NULL;
// 	savedchar = NULL;
// 	tmp = malloc(BUFFER_SIZE + 1);
// 	if (tmp = NULL)
// 		return (NULL);
// 	if (savedchar != NULL)
// 	{
		
// 	}
// 	while (read(fd, buffer, BUFFER_SIZE) > 0)
// 	{

// 	}
// }
// int main()
// {
//     int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
// 	//printf("%s",get_next_line(fd));
// 	//printf("%s",get_next_line(fd));
// 	// char *ss = get_next_line(fd);
// 	// char *sss = get_next_line(fd);
// 	// char *ssss = get_next_line(fd);
//     // free(s);
//     close(fd);
// }
// #include "get_next_line.h"

// char	*check_newline(char *s)
// {
// 	size_t	i;
// 	size_t	newline_pos;

// 	i = 0;
// 	newline_pos = ft_strchr(s, '\n');
// 	if (newline_pos)
// 	{
// 		i = ft_strlen(newline_pos) - ft_strlen(s) + 1;
// 		if (s[i + 1] == '\0')
// 			return (NULL);
// 		return (&s[i]);
// 	}
// 	return (NULL);
// }
// size_t	ft_strlen(char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strdup(char *s)
// {
// 	char	*str;
// 	size_t	i;
// 	size_t	len;

// 	if (s == NULL)
// 		return (NULL);
// 	len = ft_strlen(s);
// 	str = malloc(len + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	*ft_strchr(char *s, char c)
// {
// 	size_t	i;

// 	if (s == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 			return (&s[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*substr;

// 	i = 0;
// 	if (s == NULL)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (len > ft_strlen(s) - start)
// 		len = ft_strlen(s) - start;
// 	substr = malloc(len + 1);
// 	if (substr == NULL)
// 		return (NULL);
// 	while (s[start + i] && i < len)
// 	{
// 		substr[i] = s[start + i];
// 		i++;
// 		len--;
// 	}
// 	substr[i] = '\0';
// 	return (substr);
// }