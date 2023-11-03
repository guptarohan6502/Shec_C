#include "headers.h"
#include "echo.h"
#include "pwd.h"
#include "execute.h"
#include "cd.h"
// char *builtin_str[] = {
//   "cd",
//   "help",
//   "exit",
//   "echo",
//   "pwd",
//   "clear"
// };

char *builtin_str[] = {
    "echo",
    "pwd"};

int shec_C_num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

int shec_C_launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		// Child process
		if (execvp(args[0], args) == -1)
		{
			printf("shec_C: %s: command not found\n", args[0]);
			perror("shec_C");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		// Error forking
		printf("shec_C: Error forking\n");
		perror("shec_C");
	}
	else
	{
		// Parent process
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}
int terminate()
{

	printf("Exiting SHEC_C\n");


	return 0;
}
int shec_C_exec(char **args, int argc)
{

	if (args[0] == NULL)
	{
		return 1;
	}

	if (strcmp(args[0], "echo") == 0)
	{
		return echo(args, argc);
	}
	if (strcmp(args[0], "pwd") == 0)
	{
		return pwd();
	}
	if (strcmp(args[0], "cd") == 0)
	{
		return cd(args, argc);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		return terminate();
	}
	else{
		printf("shec_C: %s: command not found\n", args[0]);
		return 1;
	}

	return 0;
}
