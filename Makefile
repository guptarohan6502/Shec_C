#compile command with prompt.h and header.h
Run:
	gcc -c -o echo.o echo.c
	gcc -c -o pwd.o pwd.c
	gcc -c -o cd.o cd.c
	gcc -c -o execute.o execute.c
	gcc -c -o main.o main.c
	gcc -c -o global_var.o global_var.c
	gcc -o shec_C global_var.o main.o cd.o echo.o pwd.o execute.o
	rm -rf *.o