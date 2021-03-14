# INTERFACE
The `interface` library provides functions to update the registry of installed packages via the `regman` interface. It consists of five functions:
- fpkg
- fver (*)
- lspkg
- rmpkg
- wrpkg
The `regman` program is called thanks to the `unirun` library, which provides functions to execute a program by saving its output in a buffer.  

To be able to use this library you need to have installed [regman](https://github.com/LoZack19/regman).

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

# INSTALLATION
In order to use this library in one of your projects you need to perform the following instructions to compile and link the library correctly.

## Compile
First of all download this repository into your project.
```bash
$ git clone https://github.com/LoZack19/zpm-interface
$ cd zpm-interface
```

Then compile it:
```bash
$ make configure    # configure the enviroment
$ make              # compile
$ make clean        # (optional) remove object files
```
This will generate the library `librgmint.a`. Now copy this library and the `interface.h` header wherever you want. Afhter this you can delete the `zpm-interface` folder.  

**This step can be avoided by downloading the precompiled `.a` file and the header and placing them in the appropriate directories.**

## Usage
To use this library you must link it by specifying the path and using the `-lrgmint` flag in gcc. You'll need to include the `interface.h` header wherever you need to use the library.
```bash
gcc -L./ main.c -o main -lrgmint    # if librgmint.a is in the same directory of main.c
```

# AUTHOR
Written by **Giovanni Zaccaria**.