// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	int result = mem_list_add(mem_list_head.prev->start + mem_list_head.prev->len, size);
	if (result < 0)
	{
		return NULL;
	}
	return mem_list_head.prev->start;
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
