/* SPDX-License-Identifier: BSD-3-Clause */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	FILE *f;
	char buffer[128];

	f = fopen("ana.txt", "r+");
	if (f == NULL)
		exit(EXIT_FAILURE);

	fwrite("anaaremere\n", 1, 11, f);
	fread(buffer, 1, 128, f);

	fclose(f);

	write(1, buffer, 11);

	return 0;
}
