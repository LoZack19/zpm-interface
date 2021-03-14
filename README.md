# INTERFACE
The `interface` library provides functions to update the registry of installed packages via the `regman` interface. It consists of five functions:
- fpkg
- fver (*)
- lspkg
- rmpkg
- wrpkg
The `regman` program is called thanks to the `unirun` library, which provides functions to execute a program by saving its output in a buffer.

_(*) indicates that the function returns a pointer_

# RETURN VALUE
The error system is different depending on whether the function returns a pointer or not.

## Poiter returning functions
- `0` - something bad occured  
- other: function executed correctly

## Integer returning functions
Regman errors:
- `ER_ARG` - Bad number of arguments
- `ER_CMD` - Bad command
- `ER_FUN` - Package not found
- `ER_SYS` - Other kind of error in regman
Other errors:
- `_INT_ER` - Regman independent problem
Success:
- `0` - Success

# FUNCTIONS
## FPKG
```c
int fpkg(char* name);
```

The `fpkg` function takes the name of a packet as input and returns an error code to indicate whether the packet was found, not found, or a different kind of error occurred.  
- `0`      - found
- `ER_FUN` - not found

## FVER
```c
int* fver(char* name);
```

The `fver` function takes the name of a packet as input and returns an array of two integers. At position `[0]` is the package version, at position `[1]` is the subversion.  
- `0`
- other: version array

## LSPKG
```c
int lspkg();
```

The `lspkg` function prints the entire contents of the zpm package log to the screen.

## RMPKG
```c
int rmpkg(char* name);
```

The `rmpkg` function takes the name of a package as input and if it exists it deletes it from the package registry, otherwise it returns an error code.

## WRPKG
```c
int wrpkg(char* name, int ver, int sub);
```

The `wrpkg` function adds a package to the registry, taking its name, version and subversion as input. If the operation fails, an error code is returned.

# AUTHOR
Written by **Giovanni Zaccaria**.