// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>
#include <sys/stat.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	if (fd != -1)
	{
		struct stat st;
		if (fstat(fd, &st) == -1)
		{
        	errno = EBADF;
			return MAP_FAILED;
    	}
	}
	if (!(flags & MAP_PRIVATE || flags & MAP_SHARED))
	{
		errno = EINVAL;
		return MAP_FAILED;
	}
	void* result = (void*)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	int res = *((int*)result);
	if (res < 0)
	{
		errno = -res;
		return MAP_FAILED;
	}
	return result;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	void* result = (void*)syscall(__NR_mremap, old_address, old_size, new_size, flags);
	int res = *((int*)result);
	if (res < 0)
	{
		errno = -res;
		return MAP_FAILED;
	}
	return result;
}

int munmap(void *addr, size_t length)
{
	int result = syscall(__NR_munmap, addr, length);
	if (result < 0)
	{
		errno = -result;
		return -1;
	}
	return 0;
}
