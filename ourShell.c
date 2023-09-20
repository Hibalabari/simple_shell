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
	char *shel_prompt = "(LB-shell)$";
	char *bufferr = NULL, *bufferr_copy = NULL;
	ssize_t characters_nbr;
	const char *delimitors = " \n";
	int nbr_oftokens = 0;
	char *token;
	int i;
	(void)ac;
	while (1)
	{
		printf("%s", shel_prompt);
		characters_nbr = getline_eror();
		bufferr_copy = malloc(sizeof(char) * characters_nbr);
		if (bufferr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(bufferr_copy, bufferr);
		token = strtok(bufferr, delimitors);
		while (token != NULL)
		{
			nbr_oftokens++;
			token = strtok(NULL, delimitors);
		}
		nbr_oftokens++;
		argv = malloc(sizeof(char *) * nbr_oftokens);
		token = strtok(bufferr_copy, delimitors);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delimitors);
		}
		argv[i] = NULL;
		executee(argv);
		free(argv);
		free(bufferr_copy);
		free(bufferr);
	}

	return (0);
}
