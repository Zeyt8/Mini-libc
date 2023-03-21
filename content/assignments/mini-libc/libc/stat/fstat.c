/* SPDX-License-Identifier: BSD-3-Clause */

#include <sys/stat.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement lseek(). */
	return -1;
}
