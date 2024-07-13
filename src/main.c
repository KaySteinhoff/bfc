#include <stdio.h>
#include <bfcArgs.h>
#include <bfc.h>
#include <bfcStr.h>

int main(int argc, char **argv)
{
	ParseArguments(++argv, --argc);
	if(!inputFile)
	{
		printf("No input file passed! Please pass an input file to compile as a command line argument.\n");
		return -1;
	}

	if(!Compile())
		printf("Compilation of file %s failed.\n", inputFile);

	return 0;
}
