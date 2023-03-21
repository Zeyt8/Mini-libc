/* SPDX-License-Identifier: BSD-3-Clause */

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		destination[i] = source[i];
	}
	destination[len] = '\0';
	return destination;
}

char *strcat(char *destination, const char *source)
{
	int i = 0;
	char* ptr = destination + strlen(destination);
	while (source[i] != '\0')
	{
		ptr[i] = source[i];
		i++;
	}
	ptr[i] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char* ptr = destination + strlen(destination);
	for (size_t i = 0; i < len; i++)
	{
		ptr[i] = source[i];
	}
	ptr[len] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return str1[i] - str2[i];
		}
		i++;
	}
	return str1[i] - str2[i];
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		if (str1[i] != str2[i])
		{
			return str1[i] - str2[i];
		}
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (char *)&str[i];
		}
		i++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	int i = strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == c)
		{
			return (char *)&str[i];
		}
		i--;
	}
	return NULL;
}

char *strstr(const char *str1, const char *str2)
{
	int i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[0])
		{
			int j = 0;
			while (str2[j] != '\0')
			{
				if (str1[i + j] != str2[j])
				{
					break;
				}
				j++;
			}
			if (str2[j] == '\0')
			{
				return (char *)&str1[i];
			}
		}
		i++;
	}
	return NULL;
}

char *strrstr(const char *str1, const char *str2)
{
	int i = strlen(str1) - 1;
	while (i >= 0)
	{
		if (str1[i] == str2[0])
		{
			int j = 0;
			while (str2[j] != '\0')
			{
				if (str1[i + j] != str2[j])
				{
					break;
				}
				j++;
			}
			if (str2[j] == '\0')
			{
				return (char *)&str1[i];
			}
		}
		i--;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	for (size_t i = 0; i < num; i++)
	{
		((char *)destination)[i] = ((char *)source)[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char tmp[num];
	for (size_t i = 0; i < num; i++)
	{
		tmp[i] = ((char *)source)[i];
	}
	for (size_t i = 0; i < num; i++)
	{
		((char *)destination)[i] = tmp[i];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	for (size_t i = 0; i < num; i++)
	{
		if (((char *)ptr1)[i] != ((char *)ptr2)[i])
		{
			return ((char *)ptr1)[i] - ((char *)ptr2)[i];
		}
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	for (size_t i = 0; i < num; i++)
	{
		((char *)source)[i] = value;
	}
	return source;
}
