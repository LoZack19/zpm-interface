#ifndef INTERFACE_H
#define INTERFACE_H

// Regman errors
#define ER_ARG  (unsigned char)(-1)
#define ER_CMD  (unsigned char)(-2)
#define ER_FUN  (unsigned char)(-3)
#define ER_SYS  (unsigned char)(-4)

// Internal error
#define _INT_ER (signed int)(-1)

typedef struct
{
    int ver;
    int sub;
} pkg_ver;

pkg_ver* new_pkg_ver();

int fpkg(char* name);
int fver(char* name, pkg_ver* version);
int lspkg();
int rmpkg(char* name);
int wrpkg(char* name, pkg_ver* version);

#endif