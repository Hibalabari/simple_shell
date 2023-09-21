#include "ourHeaders.h"

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
	return pointr;
}