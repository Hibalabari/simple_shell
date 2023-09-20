#include "ourHeaders.h"
/**
 * getline_eror - hundle numbre of characters typed
 *
 *
 * Return: numbre of characters typed
 */
ssize_t getline_eror(void)
{
	char *bufferr = NULL;
	size_t m = 0;
	ssize_t characters_nb;

	characters_nb = getline(&bufferr, &m, stdin);

		if (characters_nb == -1)
		{
			printf("Exiting shell...byby ^^\n");
			return (-1);
		}
	return (characters_nb);
}

