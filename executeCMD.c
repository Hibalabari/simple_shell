#include "ourHeaders.h"
/**
 * cmd_execute - our main func
 * @laCommande: array count
 * @argv: null terminated array of strings
 ** @id: index
 * Return: Always 0 on success, 1 on error
 */
int cmd_execute(char **laCommande, char **argv, int id)
{
	pid_t fils;
	int stats;
	char *toutCmd;

	toutCmd = myPath(laCommande[0]);
	if (!toutCmd)
	{
		errorMsg(argv[0], laCommande[0], id);
		emptytable(laCommande);
		return (127);
	}

	fils = fork();
	if (fils == 0)
	{
		if (execve(toutCmd, laCommande, environ) == -1)
		{
			emptytable(laCommande);
			free(toutCmd), toutCmd = NULL;
		}

	}
	else
	{
		waitpid(fils, &stats, 0);
		emptytable(laCommande);
		free(toutCmd), toutCmd = NULL;
	}
	return (WEXITSTATUS(stats));
}
