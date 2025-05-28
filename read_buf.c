#include <fcntl.h> /* open(), close() */
#include <sys/types.h> 
#include <unistd.h> /* read(), write() */
#include <stdio.h> /* printf(), perror() */
#include <errno.h> /* eerno */

#define SIZE_MAX	100

int main(int argc, char **argv, char **envp) {
	char buf[SIZE_MAX];
	char *filename = "file.txt";

	int len = sizeof(buf) / sizeof(char);

	int fd = open(filename, O_CREAT | O_WRONLY, 0640);
	if (fd < 0) {
		perror("Open");
		close(fd);
		return 1;
	}

	ssize_t rd = read(0, buf, len);

	ssize_t wrt = write(fd, buf, len);
/*
	ssize_t ret;
	while (len != 0 && (ret = read(fd, buf, len)) != 0) {
		if (ret == -1) {
			if (ret == EINTR) {
				continue;
			}
			perror("read");
			break;
		}
	}
*/
	 printf("buf[] = %s\n", buf);



	close(fd);

	return 0;
}
