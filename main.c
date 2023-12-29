#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
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

// int main(void)
// {
// 	system("leaks a.out");
// 	char *s = get_next_line(42);
// 	char *s1 = get_next_line(1337);
// 	char *s2 = get_next_line(-99);
// 	char *s3 = get_next_line(3);
// 	char *s4 = get_next_line(OPEN_MAX);
// 	char *s5 = get_next_line(OPEN_MAX + 1);
// 	char *s6 = get_next_line(INT_MAX);
// 	char *s7 = get_next_line(INT_MIN);
// 	printf("fd = 42:=> %s\n", s);
// 	printf("fd = 1337:=> %s\n", s1);
// 	printf("fd = -99:=> %s\n", s2);
// 	printf("fd = 3:=> %s\n", s3);
// 	printf("fd = OPEM_MAX:=> %s\n", s4);
// 	printf("fd = OPEN_MAX + 1:=> %s\n", s5);
// 	printf("fd = INT_MAX:=> %s\n", s6);
// 	printf("fd = INT_MIN:=> %s\n", s7);
// }