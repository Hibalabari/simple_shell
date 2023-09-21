#include "ourHeaders.h"
char **spliter(char *bufferr)
{
	char *token = NULL, *copy_buffer = NULL;
	char **laCommande = NULL;
	int compteur = 0, j = 0;

	if (!bufferr)
		return (NULL);
	copy_buffer = strdup(bufferr);
	token = strtok(copy_buffer, DELIM);
	if (token == NULL)
	{
		free (copy_buffer);
		copy_buffer = NULL;
		free (bufferr);
		bufferr = NULL;
		return(NULL);
	}
	while (token)
	{
		compteur++;
		token = strtok(NULL, DELIM);
	}
	free(copy_buffer);
	copy_buffer = NULL;
	laCommande = malloc(sizeof(char *) * (compteur + 1));
	if (!laCommande)
	{
		free(bufferr);
		bufferr = NULL;
		return(NULL);
	}
	token = strtok(bufferr, DELIM);
	while (token)
	{
		laCommande[j] = strdup(token);
		token = strtok(NULL, DELIM);
		j++;
	}
	free(bufferr);
	bufferr = NULL;
	laCommande[j] = NULL;
	return(laCommande);
}