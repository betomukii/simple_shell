#include "shell.h"

/**
 * print_env - This function prints the enviromnent variable
 *
 * Return: nothing
 */

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);

		env++;
	}
}
