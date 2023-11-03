#include "headers.h"
#include "echo.h"

int echo(char **argv, int argc)
{
	
	for (int i = 0; i < argc; i++)
	{

		printf("%s ", argv[i]);
	}
	printf("\n");

	return 1;
}