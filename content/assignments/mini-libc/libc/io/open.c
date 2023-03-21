/* SPDX-License-Identifier: BSD-3-Clause */

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	int mode = 0;
    if (flags & O_CREAT)
    {
    	va_list arg_list;
        va_start(arg_list, flags);
        mode = va_arg(arg_list, mode_t);
        va_end(arg_list);
    }
    int result = syscall(__NR_open, filename, flags, mode);
    if (result == -1)
    {
        errno = result;
    }
    return result;
}
