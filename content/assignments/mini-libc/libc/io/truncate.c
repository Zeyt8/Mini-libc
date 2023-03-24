// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	int result = syscall(__NR_truncate, path, length);
	if (result == -1)
	{
		errno = result;
	}
	return result;
}
