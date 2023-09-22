#include "ourHeaders.h"
/**
 * findEnv - get the path
 * @x: input strings
 *
 * Return: Always 0 on success
 */
char *findEnv(char *x)
{
	char *coppy, *id, *valeur, *envv;
	int j;

	for (j = 0; environ[j]; j++)
	{
		coppy = myStrdup(environ[j]);
		id = strtok(coppy, "=");
		if (strCompare(id, x) == 0)
		{
			valeur = strtok(NULL, "\n");
			envv = myStrdup(valeur);
			free(coppy);
			return (envv);
		}
		free(coppy), coppy = NULL;
	}
	return (NULL);
}
