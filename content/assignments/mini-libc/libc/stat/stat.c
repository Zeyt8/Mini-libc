// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#define AT_FDCWD -100

int stat(const char *restrict path, struct stat *restrict buf)
{
	int result = fstatat(AT_FDCWD, path, buf, 0);
	if (result == -1)
	{
		errno = result;
	}
	return result;
}
