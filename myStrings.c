#include "ourHeaders.h"
/**
 * myStrdup - duplicate string
 * @strr: input strings
 *
 * Return: Always 0 on success
 */
char *myStrdup(const char *strr)
{
	char *pointr;
	int j, lengh = 0;

	if (strr == NULL)
		return (NULL);
	while (*strr != '\0')
	{
		lengh++;
		strr++;
	}
	strr = strr - lengh;
	pointr = malloc(sizeof(char) * (lengh + 1));
	if (pointr == NULL)
		return (NULL);
	for (j = 0; j <= lengh; j++)
		pointr[j] = strr[j];
	return (pointr);
}

/**
 * strCompare - compare string
 * @str1: input strings
 * @str2: input strings
 * Return: Always 0 on success
 */

int strCompare(char *str1, char *str2)
{
	int compare;

	compare = (int)*str1 - (int)*str2;
	while (*str1)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
		compare = (int)*str1 - (int)*str2;
	}
	return (compare);
}

/**
 * getLongueur - get lengh of string
 * @str: input strings
 * Return: Always 0 on success
 */

int getLongueur(char *str)
{
	int longg = 0;

	while (str[longg])
		longg++;
	return (longg);
}

/**
 * strConcact - caoncactenate string
 * @orgin: source strings
 * @destination: destina of string
 * Return: Always 0 on success
 */

char *strConcact(char *destination, char *orgin)
{
	char *ptr = destination;

	while (*ptr)
		ptr++;

	while (*orgin)
	{
		*ptr = *orgin;
		ptr++;
		orgin++;
	}
	*ptr = '\0';
	return (destination);
}

/**
 * _strCopy - copy string
 * @destination: input strings
 * @orgin: input strings
 * Return: Always 0 on success
 */

char *_strCopy(char *destination, char *orgin)
{
	int j = 0;

	while (orgin[j])
	{
		destination[j] = orgin[j];
		j++;
	}
	destination[j] = '\0';
	return (destination);
}
