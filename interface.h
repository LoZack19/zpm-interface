#ifndef INTERFACE_H
#define INTERFACE_H

int fpkg(char* name);
int* fver(char* name);
int lspkg();
int rmpkg(char* name);
int wrpkg(char* name, int ver, int sub);

#endif