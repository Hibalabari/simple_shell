#include "ourHeaders.h"
/**
 * path_getting - get the location
 * @commande: commande typed by user
 *
 * Return: Always 0
 */

char *path_getting(char *commande)
	{
		char *path, *cp_path, *path_tookenn, *filePath;
		int cmd_longueur, dir_longueur;
		struct stat buffer;

		path = getenv("PATH");

		if (path)
		{
			cp_path = strdup(path);
			cmd_longueur = strlen(commande);
			path_tookenn = strtok(cp_path, ":");
			while (path_tookenn != NULL)
			{
			dir_longueur = strlen(path_tookenn);
			filePath = malloc(cmd_longueur + dir_longueur + 2);
			strcpy(filePath, path_tookenn);
			strcat(filePath, "/");
			strcat(filePath, commande);
			strcat(filePath, "\0");

			if (stat(filePath, &buffer) == 0)
			{
				free(cp_path);
				return (filePath);
			}
			else
				{
					free(filePath);
					path_tookenn = strtok(NULL, ":");
				}
			}
			free(cp_path);
			if (stat(commande, &buffer) == 0)
				{
				return (commande);
				}
			return (NULL);
		}
	return (NULL);
}
