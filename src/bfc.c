#include <bfcStr.h>
#include <stdlib.h>
#include <errno.h>

enum OutputArch outputArch = x86_64;
char *inputFile = NULL;
#ifdef _WIN32
char *outputFile = "a.exe";
#elif __unix__
char *outputFile = "a.out";
#endif

typedef struct whileElement
{
	string_t loopName;
	struct whileElement *next;
}whileStack;

size_t currentLoopIndex = 0;
whileStack stack = { 0 };

string_t pop()
{
	string_t str = stack.loopName;
	stack = *stack.next;
	return str;
}

void push(string_t str)
{
	whileElement elem = {
		.loopName = str,
		.next = &stack;
	};

	stack = elem;
}

bool Compilex86_64(char *source, size_t sourceLength)
{
	string_t code = newString("section .text\n\tglobal _start\nsection .bss\n\tmemory resb 256\nsection .data\n\tpointer db 0\nread:\n\tmov eax, 3\n\tmov ebx, 0\n\tlea ecx, [memory] + pointer\n\tmov edx, 1\n\tint 0x80\n\tret\nwrite:\n\tmov eax, 4\n\t_start:\n", 37);
	string_t additionCode = newString("\tadd [edi + pointer], ", 22);
	string_t subtractionCode = newString("\tsub [edi + pointer], ", 22);
	string_t printCode = newString("\tmov eax, 4\n\tmov ebx, 1\n\tmov ecx, edi\n\tmov edx, 1\n\tint 0x80\n", 60);
	string_t exitCode = newString("\tmov eax, 0\n\tmov ebx, 1\n\tint 0x80", 33);

	int repeats = 0;
	//Do stuff with the brainfuck code
	for(int i = 0; i < sourceLength; ++i)
	{
		switch(source[])
		{
			case '+':
				repeats = GetRepeats(source + i, sourceLength - i);
				string_t add = increase(repeats);
				stringAppend(&code, add.stt, add.length);
				free(add.str);
				i += repeats
				break;
		}
	}

	//Add Assembly code for safe program exit with return code 0
	stringAppend(&code, exitCode.str, exitCode.length);

	printf("%s\n", code.str);

	return TRUE;
}

bool Compile(void)
{
	//Read file
	FILE *input = fopen(inputFile, "r");

	if(!input)
	{
		printf("Failed to open file %s: %s\n", inputFile, strerror(errno));
		return FALSE;
	}

	fseek(input, 0, SEEK_END);
	size_t fsize = ftell(input);
	fseek(input, 0, SEEK_SET);

	char *content = malloc(fsize);
	if(!content)
		return FALSE;
	fread(content, 1, fsize, input);

	fclose(input);

	//Compile into assembly
	switch(outputArch)
	{
		case x86_64:
			return Compilex86_64(content, fsize);
		default:
			return FALSE;
	}

	return FALSE;
}
