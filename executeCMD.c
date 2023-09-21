#include "ourHeaders.h"
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