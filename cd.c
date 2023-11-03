#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "cd.h"
#include "global_var.h"

int cd(char **args, int argc)
{
	int sizeofbuffer = 1024;
	char temp_prev_dir[sizeofbuffer];

	if (getcwd(temp_prev_dir, sizeofbuffer) == NULL)
	{
		perror("shec_C: pwd: getcwd() error");
		return 1;
	}

	if (argc > 2)
	{
		fprintf(stderr, "shec_C: cd: too many arguments\n");
		return 1;
	}
	

	if (args[1] == NULL)
	{
	}
	else if (args[1] == "..")
	{
		chdir("..");
	}
	else if (!strcmp(args[1], "~"))
	{
		chdir(HOME);
	}
	else if (!strcmp(args[1], "-"))
	{
		chdir(PREV_WD);
		printf("%s\n", PREV_WD);
		
	

	}
	else if (args[1] == ".")
	{
		chdir(temp_prev_dir);
	}
	else if (chdir(args[1]) != 0)
	{
		printf("help: cd\n");

		perror("shec_C");
	}
	

	strcpy(PREV_WD, temp_prev_dir);

	return 1;
}