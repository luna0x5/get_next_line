// #include "get_next_line.h"
// #include <stdio.h>
// #include <fcntl.h>
// int main(void)
// {
// 	system("leaks a.out");
// 	int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
// 	write(fd, "hello this is a test\nthe first writing was a line and this another one\nand this is the third\nand the fourth\n\n\n\n\n", 112);
// 	close(fd);
// 	fd = open("test.txt", O_RDWR, 0777);
// 	// fd = 0;
// 	int i = 1;
// 	char *s = get_next_line(fd);
// 	while (s)
// 	{
// 		printf("%d:=> %s", i, s);
// 		free(s);
// 		s = get_next_line(fd);
// 		i++;
// 	}
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%d:=> %s", i, s);
// 	free(s);
// 	close(fd);
// }
// int main(void)
// {
// 	system("leaks a.out");
// 	char *s = get_next_line(-5);
// 	printf("this is a negative fd:=> %s\n", s);
// 	s = get_next_line(3);
// 	printf("this is a fd that is not default one:=> %s\n", s);
// 	int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
// 	s = get_next_line(fd);
// 	printf("this is the first line:=> %s", s);
// 	free(s);
// 	close(fd);
// 	printf("this is with a closed fd:=> %s\n", get_next_line(fd));
// 	fd = open("test.txt", O_RDWR, 0777);
// 	// fd = 0; 
// 	int i = 1;
// 	s = get_next_line(fd);
// 	while (s)
// 	{
// 		printf("%d:=> %s", i, s);
// 		free(s);
// 		s = get_next_line(fd);
// 		i++;
// 	}
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%d:=> %s", i, s);
// 	free(s);
// }
