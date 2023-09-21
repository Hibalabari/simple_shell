#include "ourHeaders.h"
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