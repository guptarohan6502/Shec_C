#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define Ini_BUFSIZE 1024

#include "echo.h"
#include "execute.h"
#include "pwd.h"
#include "cd.h"
#include "global_var.h"