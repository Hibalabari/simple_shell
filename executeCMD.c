#include "ourHeaders.h"
/**
 * cmd_execute - our main func
 * @laCommande: array count
 * @argv: null terminated array of strings
 *
 * Return: Always 0 on success, 1 on error
 */
int cmd_execute(char **laCommande, char **argv)
{
	pid_t fils;
	int stats;

	fils = fork();
	if (fils == 0)
	{
		if (execve(laCommande[0], laCommande, environ) == -1)
		{
			perror(argv[0]);
			emptytable(laCommande);
			exit(0);
		}
	
	}
	else
	{
		waitpid(fils, &stats, 0);
		emptytable(laCommande);
	}
	return(WEXITSTATUS(stats));
}
