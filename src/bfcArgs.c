#include <bfcArgs.h>
#include <bfc.h>
#include <stdio.h>
#include <stdlib.h>

void GetVersion(void)
{
	printf("Brainfuck compiler version 0.1\nGNU general public license version 3.1\n");
}

void PrintHelp(void)
{
	printf("%s\n\n%s\n\n%s\n",
		"bfc [input file] [options]",
		"The Brainfuck compiler only supports a single input file(as there is no way to use multiple). The order of options and the input file doesn't matter and the above is an illustration of a usage.",
		"-h: Brings up this help page.\n\n-v: Prints the currently installed version of the brainfuck compiler.\n\n-m: Changes the architecture of the oitput file from the default to one of the following: (not implemented)\n\n-o: Chnages the output file name from 'a' to the inputed value");
}

int ExecuteArgument(char **args, int count)
{
	switch(args[0][1])
	{
		case 'v':
			GetVersion();
			exit(0);
			return 0;
		case 'h':
			PrintHelp();
			exit(0);
			return 0;
		case 'o':
			outputFile = args[1];
			return 1;
	}

	return 0;
}

void ParseArguments(char **args, int count)
{
	for(int i=0; i < count; ++i)
	{
		if(args[i][0] == '-')
			i+=ExecuteArgument(args+i, count-i);
		else
			inputFile = args[i];
	}
}
