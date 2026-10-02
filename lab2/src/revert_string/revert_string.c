#include "revert_string.h"
#include <stdlib.h>
#include <string.h>

void RevertString(char *str)
{
	char* result = malloc(sizeof(char) * strlen(str) + 1);
	for (int i = 0; i < strlen(str); i++)
	{
		result[i] = str[strlen(str) - i - 1];
	}
	result[strlen(str)] = '\0';
	strcpy(str, result);
	free(result);
}

