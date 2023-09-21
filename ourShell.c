#include "ourHeaders.h"

/**
 * main - our main func
 * @ac: array count
 * @argv: null terminated array of strings
 *
 * Return: Always 0 on success, 1 on error
 */


int main(int ac, char **argv)
{
	char *bufferr = NULL, **laCommande;
	int stats = 0;
	(void) ac;
	while (1)
	{
		bufferr = getline_eror();

		if (bufferr == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stats);	
		}
		
		laCommande = spliter(bufferr);
		if (!laCommande)
			continue;

		stats = cmd_execute(laCommande, argv);
	}
	return (0);
}
