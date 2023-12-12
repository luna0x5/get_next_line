#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
// int main()
// {
// 	int fd = creat("text.txt", 0777);
// 	int fd1 = creat("text1.txt", 0777);
// 	int fd2 = dup(1);
// 	write(fd, "hello this is a test", 20);
// 	write(fd1, "hello this is a test1", 21);
// 	write(fd2, "hello this is a test2", 21);
// 	write(1, "\nthis is a second testo", 23);
// 	printf("\n%d\n", fd);
// 	printf("%d\n", fd1);
// 	printf("%d\n", fd2);
// }

// int main()
// {
// 	int fd = creat("text.txt", 0777);
// 	//int fd1 = creat("text1.txt", 0777);
// 	printf("%dbefore\n", fd);
// 	write(2, "hello this is a test", 20);
// 	//write(fd1, "hello this is a test1", 21);
// 	//printf("%d\n", fd1);
// 	dup2(fd, 2);
// 	printf("%d\n", fd);
// 	write(2, "hello this is a test", 20);
// 	//write(fd1, "hello this is a test1", 21);
// 	//printf("%d\n", fd1);
	
// }

// int main()
// {
// 	int fd = open("txt.txt",O_CREAT | O_RDWR);
// 	write(fd, "hello this is a test", 20);
// 	lseek(fd, 0, SEEK_SET);
// 	char *s;
// 	int i = read(fd, s, 10);
// 	printf("the buff : %s\n", s);
// 	printf("return : %d\n", i);
// }

// int main()
// {
// 	int fd = open("test.txt", O_CREAT | O_RDWR);
// 	printf("my fd is -> %d\n", fd);
// 	char *s = malloc(2000);
// 	int count = read(fd, s, 2000);
// 	printf("my buffer contains : %s\n", s);
// 	printf("how much I read : %d\n", count);
// 	free(s);

// }