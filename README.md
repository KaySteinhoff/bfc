# Bfc: *THE* Brainfuck compiler

Bfc (short for Brainfuck-Compiler) is as far as I know at the making of this program the only Brainfuck compiler.
Bfc is a highly advanced program with state-of-the-art features like:
- Command line arguments
- Compiler errors
- ...

# Why should I use bfc?

You shouldn't.

# What does bfc actually do?

Bfc reads your *.bfk file, converts it to assembly, assembles it, links it and outputs an executable console application.
Other than for example python, bfc actually creates a final executable which is able to run on any machine of with the same OS and CPU architecture without needing bfc.

Additionally due to the few instructions of Brainfuck bfc creates a stunningly small and fast applications, enabling you to create blazing fast useless programs!

# How do I use it?

Bfc works on the same principle as other popular compilers and interpreters.
Bfc requires an input file and can take in multiple different flags such as '-o' to change the output file name.

Here's a complete list of bfc flags and their uses:

|---|---|
|-h|Prints a help page very similar to this table|
|-v|Prints the currently installed version and the license it's under|
|-m|Changes the target architecture from the default(it being the local one or if it couldn't be detected x86 64bit assembly)|
|-o|Changes the output file name. Very similar to gcc's -o.|


Thus an example usage would look like this:
```bash
bfc path/to/file.bfk -o output/file/path.out -m x86_64
``` 

The order of arguments is irrelevant.

Currently bfc only supports x86-64 for Linux and other Unix like systems.
