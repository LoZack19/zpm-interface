#ifndef INTERFACE_H
#define INTERFACE_H

// Regman errors
#define ER_ARG  (unsigned char)(-1)
#define ER_CMD  (unsigned char)(-2)
#define ER_FUN  (unsigned char)(-3)
#define ER_SYS  (unsigned char)(-4)

// Internal error
#define _INT_ER (signed int)(-1)

int fpkg(char* name);
int* fver(char* name);
int lspkg();
int rmpkg(char* name);
int wrpkg(char* name, int ver, int sub);

#endif