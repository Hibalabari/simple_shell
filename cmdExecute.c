#include "ourHeaders.h"
/**
 * executee - responsible for execution
 * @argv: null terminated array of strings
 *
 * Return: nothing
 */

void executee(char **argv)
{
char *commande = NULL, *actual_commande = NULL;

if (argv)
{
    commande = argv[0];
    actual_commande = path_getting(commande);

    if (execve(actual_commande, argv, NULL) == -1)
    {
        perror("Error:");
    }
}

}
