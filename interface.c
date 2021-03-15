#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Unirun/unirun.h"
#include "interface.h"

#define INTERFACE   "/usr/bin/regman"

// from https://gist.github.com/CMCDragonkai/9e5d8333e4404ee66491
char* itos(const int num)
{
    char* buffer;

    int digits = snprintf(NULL, 0, "%d", num); 
    int str_len = digits + 1;

    buffer = malloc(str_len);

    if (!buffer)
        return NULL;

    snprintf(buffer, str_len, "%d", num);
    
    return buffer;
}

pkg_ver* new_pkg_ver() { return (pkg_ver*) malloc(sizeof(pkg_ver)); }

int fpkg(char* name)
{
    char* args[4] = {"regman", "fpkg", name, 0};
    char* buffer = NULL;
    int status;

    buffer = run(INTERFACE, args, &status);
    if(!buffer)
        return _INT_ER;
    
    free(buffer);
    return status;
}

int fver(char* name, pkg_ver* version)
{
    char* args[4] = {"regman", "fver", name, 0};
    char* buffer = NULL;
    char* tmp;
    int status;
    
    if(!version)
        return _INT_ER;

    buffer = run(INTERFACE, args, &status);
    if(!buffer)
        return _INT_ER;
    if(status)
        return status;
    
    tmp = strtok(buffer, " ");
    version->ver = atoi(tmp);

    tmp = strtok(NULL, " ");
    version->sub = atoi(tmp);

    free(buffer);
    return status;
}

int lspkg()
{
    char* args[3] = {"regman", "print", 0};
    char* buffer = NULL;
    int status;

    buffer = run(INTERFACE, args, &status);
    if(!buffer)
        return _INT_ER;
    if(status)
        return status;
    
    fputs(buffer, stdout);
    
    free(buffer);
    return status;
}

int rmpkg(char* name)
{
    char* args[4] = {"regman", "rmpkg", name, 0};
    int status;

    if(!run(INTERFACE, args, &status))
        return _INT_ER;
    
    return status;
}

int wrpkg(char* name, pkg_ver* version)
{
    char* args[6] = {"regman", "write", name, itos(version->ver), itos(version->sub), 0};
    int status;

    if(!run(INTERFACE, args, &status))
        return _INT_ER;
    
    return status;
}
