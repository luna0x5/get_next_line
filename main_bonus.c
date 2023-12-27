// #include "get_next_line_bonus.h"
// #include <stdio.h>
// #include <fcntl.h>
// int main(void)
// {
// 	system("leaks a.out");
// 	int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
// 	int fd1 = open("test1.txt", O_CREAT | O_RDWR, 0777);
// 	write(fd, "hello this is a test\nthe first writing was a line and this another one\nand this is the third\nand the fourth\n\n\n\n\n", 112);
// 	write(fd1, "hello this is a test\nthe first writing was a line and this another one\nand this is the third\nand the fourth\n\n\n\n\n", 112);
// 	close(fd);
// 	close(fd1);
// 	fd = open("test.txt", O_RDWR, 0777);
// 	fd1 = open("test1.txt", O_RDWR, 0777);
// 	// fd = 0;
// 	int i = 1;
// 	char *s = get_next_line(fd);
// 	char *s1 = get_next_line(fd1);
// 	while (s && s1)
// 	{
// 		printf("%d:=> %s", i, s);
// 		printf("%d:=> %s", i, s1);
// 		free(s);
// 		free(s1);
// 		s = get_next_line(fd);
// 		s1 = get_next_line(fd1);
// 		i++;
// 	}
// 	free(s);
// 	free(s1);
// 	s = get_next_line(fd);
// 	s1 = get_next_line(fd1);
// 	printf("%d:=> %s", i, s);
// 	printf("%d:=> %s", i, s1);
// 	free(s);
// 	free(s1);
// 	close(fd);
// 	close(fd1);
// }
// int main(void)
// {
// 	system("leaks a.out");
// 	char *s = get_next_line(42);
// 	char *s1 = get_next_line(1337);
// 	char *s2 = get_next_line(-99);
// 	char *s3 = get_next_line(3);
// 	printf("fd = 42:=> %s\n", s);
// 	printf("fd = 1337:=> %s\n", s1);
// 	printf("fd = -99:=> %s\n", s2);
// 	printf("fd =: -99:=> %s\n", s3);
// }