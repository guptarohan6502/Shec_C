/*
 Shell envriome is also called REPL (Read Eval Print Loop)
 */

#include "headers.h"

#define Ini_BUFSIZE 1024

// function to get username for system

// Doubts - what does fprintf does..
//  doubts what does exit does in detail...

#define Ini_BUFSIZE 1024

void get_username()
{
	USER = getenv("USER");

	if (USER == NULL)
	{
		fprintf(stderr, "shec_C: allocation error\n");
		exit(EXIT_FAILURE);
	}
}

void get_cwd()
{
	if (getcwd(HOME, 1024 * sizeof(HOME)) == NULL)
	{
		perror("Error in finding the Current Working Directory");
		exit(1);
	}
	strcpy(PREV_WD, HOME);
}

void get_sysname()
{
	struct utsname sysname;
	uname(&sysname);

	if (uname(&sysname) != 0)
	{
		perror("uname() error");
		exit(EXIT_FAILURE);
	}

	strcpy(HOST, sysname.nodename);
}

void global_assign()
{
	HOST = malloc(Ini_BUFSIZE * sizeof(char));
	USER = malloc(Ini_BUFSIZE * sizeof(char));
	HOME = malloc(Ini_BUFSIZE * sizeof(char));
	PWD = malloc(Ini_BUFSIZE * sizeof(char));
	PREV_WD = malloc(Ini_BUFSIZE * sizeof(char));

	memset(HOST, '\0', sizeof(char) * Ini_BUFSIZE);
	memset(USER, '\0', sizeof(char) * Ini_BUFSIZE);
	memset(HOME, '\0', sizeof(char) * Ini_BUFSIZE);
	memset(PWD, '\0', sizeof(char) * Ini_BUFSIZE);
	memset(PREV_WD, '\0', sizeof(char) * Ini_BUFSIZE);
}

void initialise()
{
	global_assign();

	get_username();
	get_sysname();
	get_cwd();
}
void prompt()
{

	if (getcwd(PWD, 1024) == NULL)
	{
		perror("Error in retrieving the present working directory.");
	}

	char *occ = strstr(PWD, HOME);
	if (occ)
	{
		printf("shec_C:%s@%s:~%s$ ", USER, HOST, occ + strlen(HOME));
	}
	else
	{
		// printf("%s\n", PWD);
		printf("shec_C:%s@%s:%s$ ", USER, HOST, PWD);
	}
}

int main()
{
	int exe_status;

	initialise();

	do
	{

		char *cmd = NULL;
		char *cmd_cpy = NULL;
		char *token = NULL;
		char *delim = " \t\r\n";
		size_t n = 0; // this will hold the size of buffer
		int argc = 0;
		int i = 0;	    // counter variable
		char **argv = NULL; // array of pointers to strings - Non terminated strings
		int echo_flag = 0;

		prompt();

		if (getline(&cmd, &n, stdin) == -1)
		{
			return -1;
		}

		cmd_cpy = strdup(cmd);

		/*
	//Code to test addnition of \n
		// while(cmd[i]){
		// 	if(cmd[i]=='\n'){
		// 		printf("\\n --> Input has %ld characters\n", strlen(cmd));

		// 	}
		// 	else{
		// 		printf("%c", cmd[i]);
		// 	}
		// 	i++;
		// }
	*/

		token = strtok(cmd, delim);
		// Find out exact implementation of strktok and all related sting
		// functions if poosible
		// Also learn in detail about calloc and malloc and realloc

		while (token)
		{
			if (token[0] == '"')
			{
				char *token2 = strtok(NULL, "\"");
				// join argv[i] and token
			}

			token = strtok(NULL, delim);
			argc++;
		}
		argv = malloc(sizeof(char *) * (argc + 1));

		token = strtok(cmd_cpy, delim);

		i = 0;
		while (token)
		{
			if (token[0] == '"')
			{
				// join argv[i] and token
				int j = 0;
				while (token[j+1] != '\0')
				{
					token[j] = token[j + 1];
					j++;
				}
				token[j] = ' '; 
				char *token2 = strtok(NULL, "\"");
				argv[i] = strncat(token, token2,strlen(token2));
			}
			else
			{
				argv[i] = token;
			}

			token = strtok(NULL, delim);
			i++;
		}
		argv[i] = NULL; // because by defination argv is NULL terminated array of strings

		exe_status = shec_C_exec(argv, argc);

		free(cmd), free(cmd_cpy), free(argv);
	} while (exe_status);

	return 0;
}
