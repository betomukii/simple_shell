#include "shell.h"
#include <errno.h>
#include <ctype.h>

/**
 * run_cd_command - function runs change directory command
 * @token_arr: double character pointer.
 * @token_index: integer to the token index.
 *
 * Return: nothing.
 */

void run_cd_command(char **token_arr, int token_index)
{
	char *dir = NULL;
	char cwd[1024];
	char *oldpwd;

	if (token_index == 1 || strcmp(token_arr[1], "~") == 0)
		dir = my_getenv("HOME");
	else if (strcmp(token_arr[1], "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (dir == NULL)
		{
			fprintf(stderr, "Error: OLDPWD not set\n");
			return;
		}

		dir = my_getenv("OLDPWD");
	}
	else
		dir = token_arr[1];

	oldpwd = getenv("PWD");

	if (oldpwd == NULL)
	{
		fprintf(stderr, "Error: PWD not set\n");
		return;
	}
	setenv("OLDPWD", oldpwd, 1);
	if (chdir(dir) != 0)
		perror("error");
	else
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			setenv("PWD", cwd, 1);
		else
			perror("Error: could not get current working directory\n");
	}
}
/**
 * run_exit_command - function that exits a command.
 * @str: character pointer.
 * @index: integer index.
 *
 * Return: nothing
 */


