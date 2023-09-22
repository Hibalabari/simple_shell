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

	for (j = 0; tableau[j]; j++)
	{
		free(tableau[j]);
		tableau[j] = NULL;
	}

	free(tableau);
	tableau = NULL;
}

/**
 * errorMsg - our main func
 * @nom: null terminated array of strings
 * @laCommande: null terminated array of strings
 * @id: null terminated array of strings
 * Return: Always 0 on success, 1 on error
 */

void errorMsg(char *nom, char *laCommande, int id)
{
	char *indexx, msg[] = ": not found\n";

	indexx = i_toa(id);

	write(STDERR_FILENO, nom, getLongueur(nom));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, indexx, getLongueur(indexx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, laCommande, getLongueur(laCommande));
	write(STDERR_FILENO, msg, getLongueur(msg));

	free(indexx);

}

/**
 * i_toa - int to assci
 * @m: null terminated array of strings
 *
 * Return: Always 0 on success, 1 on error
 */

char *i_toa(int m)
{
	char buferr[20];
	int j = 0;

	if (m == 0)
		buferr[j++] = '0';
	else
	{
		while (m > 0)
		{
			buferr[j++] = (m % 10) + '0';
			m /= 10;
		}
	}
	buferr[j] = '\0';
	inverser_strg(buferr, j);

	return (myStrdup(buferr));
}

/**
 * inverser_strg - inverser le str
 * @str: null terminated array of strings
 * @longg: null terminated array of strings
 * Return: Always 0 on success, 1 on error
 */

void inverser_strg(char *str, int longg)
{
	char coppy;
	int debut = 0;
	int fin = longg - 1;

	while (debut < fin)
	{
		coppy = str[debut];
		str[debut] = str[fin];
		str[fin] = coppy;
		debut++;
		fin--;
	}
}
