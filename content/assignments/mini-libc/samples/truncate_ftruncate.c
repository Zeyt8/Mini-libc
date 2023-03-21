/* SPDX-License-Identifier: BSD-3-Clause */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE_1	5000
#define SIZE_2	10000

int main(void)
{
	/*
	 * Try to open a file that doesn't exit, specify the O_CREAT flag.
	 * Open should succeed.
	 * Specify access mode as O_WRONLY and the user permissions as write to be able to truncate the file.
	 */
	int fd1, fd2;
	int r;

	fd1 = open("./file1", O_CREAT | O_WRONLY, S_IWUSR);
	if (fd1 < 0) {
		write(1, "Something went wrong - open.\n", strlen("Something went wrong - open.\n"));
		return -1;
	}

	/*
	 * Try to open a file that doesn't exit, specify the O_CREAT flag.
	 * Open should succeed.
	 * Specify access mode as O_WRONLY and the user permissions as write to be able to truncate the file.
	 */
	fd2 = open("./file2", O_CREAT | O_WRONLY, S_IWUSR);
	if (fd2 < 0) {
		write(1, "Something went wrong - open.\n", strlen("Something went wrong - open.\n"));
		return -1;
	}

	/* truncate to 5000 size "file1" */
	r = truncate("./file1", SIZE_1);
	if (r < 0) {
		write(1, "Something went wrong - truncate.\n", strlen("Something went wrong - truncate.\n"));
		return -1;
	}

	/* truncate to 10000 size "file2" */
	r = ftruncate(fd2, SIZE_2);
	if (r < 0) {
		write(1, "Something went wrong - ftruncate.\n", strlen("Something went wrong - ftruncate.\n"));
		return -1;
	}

	/* Try to close the file descriptor. */
	r = close(fd1);
	if (r < 0)
		write(1, "Something went wrong - close.\n", strlen("Something went wrong - close.\n"));

	/* Try to close the file descriptor. */
	r = close(fd2);
	if (r < 0)
		write(1, "Something went wrong - close.\n", strlen("Something went wrong - close.\n"));

	return 0;
}
