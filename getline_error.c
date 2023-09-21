#include "ourHeaders.h"
/**
 * getline_eror - hundle numbre of characters typed
 *
 *
 * Return: numbre of characters typed
 */
char *getline_eror(void)
{
	char *bufferr = NULL;
	size_t m = 0;
	ssize_t characters_nb;

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);
	characters_nb = getline(&bufferr, &m, stdin);

		if (characters_nb == -1)
		{
			free(bufferr);
			return (NULL);
		}
	return (bufferr);
}

