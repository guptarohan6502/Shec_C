#include "pwd.h"
#include <stdio.h>
#include <unistd.h>

int pwd(){

	int sizeofbuffer = 1024;
	char buffer[sizeofbuffer];

	if(getcwd(buffer, sizeofbuffer) == NULL){
		perror("shec_C: pwd: getcwd() error");
		return 1;
	}
	else{
		printf("%s\n", buffer);
	}


	return 1;
}
