#ifndef BFC_COMPILER_H_
#define BFC_COMPILER_H_

#define TRUE 1
#define FALSE 0

enum OutputArch
{
	x86_64
};

typedef unsigned char bool;

extern char *inputFile;
extern enum OutputArch outputArch;
extern char *outputFile;

bool Compile(void);

#endif
