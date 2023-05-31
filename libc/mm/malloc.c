// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void* tmp = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (tmp == MAP_FAILED)
	{
		return NULL;
	}
	int result = mem_list_add(tmp, size);
	if (result < 0)
	{
		return NULL;
	}
	return tmp;
}

void *calloc(size_t nmemb, size_t size)
{
	void* tmp = malloc(nmemb * size);
	if (tmp != NULL)
	{
		memset(tmp, 0, nmemb * size);
	}
	return tmp;
}

void free(void *ptr)
{
	struct mem_list *item = mem_list_find(ptr);
	int result = munmap(ptr, item->len);
	if (result < 0)
	{
		return;
	}
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL)
	{
		return malloc(size);
	}
	void *dest = malloc(size);
    if (dest)
	{
        memcpy(dest, ptr, size);
	}
    free(ptr);
    return dest;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return realloc(ptr, nmemb * size);
}
