#include  <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	FILE *file;
	char *token, *buffer;
	ssize_t line_ptr = 1;
	size_t size = 0;
	unsigned int counter = 0;
	long long int n, p, q;

	if (argc < 2)
	{
		fprintf(stderr, "Error: cannot open file");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: cannot open file%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (line_ptr > 0 || line_ptr != EOF)
	{
		buffer = NULL;
		line_ptr = getline(&buffer, &size, file);
		counter++;		
		token = strtok(buffer, " \n\t");
		if (token == NULL)
		{
			fprintf(stderr, "line number %u is NULL", counter);
		}
		n = atoi(token);

		p = 2;
		while (p < n)
		{
			if (n % p == 0)
			{
				q = n / p;
				printf("%lld=%lld*%lld\n", n, q, p);
				break;
			}
			p++;
		}
		free(buffer);
	}
	fclose(file);
	return (0);
}
