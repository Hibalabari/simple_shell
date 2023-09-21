#include "ourHeaders.h"
/**
 * emptytable - our main func
 * @tableau: null terminated array of strings
 *
 * Return: Always 0 on success, 1 on error
 */
void emptytable(char **tableau)
{
	int j;
	
	if (!tableau)
		return;

	for (j=0; tableau[j]; j++)
	{
		free(tableau[j]);
		tableau[j] = NULL;
	}

	free(tableau);
	tableau = NULL;
}
