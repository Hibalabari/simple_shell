#include "ourHeaders.h"
/**
 * myPath - get path
 * @laCommande: null terminated array of strings
 *
 * Return: Always 0 on success, 1 on error
 */
char *myPath(char *laCommande)
{
	char *pathEnv, *toutCmd, *dirctry;
	struct stat st;
	int j;

	for (j = 0; laCommande[j]; j++)
	{
		if (laCommande[j] == '/')
		{
			if (stat(laCommande, &st) == 0)
				return (myStrdup(laCommande));
			return (NULL);
		}
	}
	pathEnv = findEnv("PATH");
	if (!pathEnv)
		return (NULL);

	dirctry = strtok(pathEnv, ":");
	while (dirctry)
	{
		toutCmd = malloc(getLongueur(dirctry) + getLongueur(laCommande) + 2);
		if (toutCmd)
		{
			_strCopy(toutCmd, dirctry);
			strConcact(toutCmd, "/");
			strConcact(toutCmd, laCommande);
			if (stat(toutCmd, &st) == 0)
			{
				free(pathEnv);
				return (toutCmd);
			}
			free(toutCmd), toutCmd = NULL;
			dirctry = strtok(NULL, ":");
		}
	}
	free(pathEnv);
	return (NULL);
}
