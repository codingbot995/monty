# Our own monty program

This is our monty program that will handle '.m' files for stacks and queues in C language

### About

# ```The Monty language```

> Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

> Monty byte code files

> Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
      
```      
      julien@ubuntu:~/monty$ cat -e bytecodes/000.m
      push 0$
      push 1$
      push 2$
        push 3$
                         pall    $
      push 4$
          push 5    $
            push    6        $
      pall$
      julien@ubuntu:~/monty$

```
> Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account):

```
      julien@ubuntu:~/monty$ cat -e bytecodes/001.m
      push 0 Push 0 onto the stack$
      push 1 Push 1 onto the stack$
      $
      push 2$
        push 3$
                         pall    $
      $
      $
                                 $
      push 4$
      $
          push 5    $
            push    6        $
      $
      pall This is the end of our program. Monty is awesome!$
      julien@ubuntu:~/monty$
```
# The monty program

> Usage: monty file

> where file is the path to the file containing Monty byte code
> If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status -- - EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
where <file> is the name of the file
- If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
- where is the line number where the instruction appears.
  - Line numbers always start at 1
  - The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file
- It finds an error in the file an error occured: 
  - If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
- You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

### Compilation
This monty program is compiled with:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```

### Output
This program successfully handles stacks and queues in C language

### Functions
This section is to explain the functions in the monty program

- PUSH - This will push a value to the stack or queue
- POP - This will pop(removes) a value from top of stack or bottom of queue
- PINT - This prints the top element in the stack or queue
- SWAP - This swaps the last two elements in the stack
- SUB - This carry out arithmetic operation on last two elements stack (subtraction)
- ROTR - Rotates stack from bottom to top
- ROTL - Rotates stack from top to bottom
- PSTR - Prints the ASCII value of the entire element of stack
- PCHAR - Prints the ASCII value of the top element of stack
- PALL - Prints all elements in stack
- MUL - Carries out arithmetic operation on last two elements of stack (multiplication)
- MOD - Carries out arithmetic operation on last two elements of stack (mod)
- DIV - Carries out arithmetic operation on last two elements of stack (division)
- ADD - Carries out arithmetic operation on last two elements of stack (addition)


#### Usage
```$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall

$ ./monty bytecodes/07.m 
3
2
1
2
1
1
```

```
$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint

$ ./monty bytecodes/06.m 
1
2
3
```

```
$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$

$ ./monty bytecodes/00.m
3
2
1
```

### Error Handling
This program intelligently handles error in file '.m';
only numbers allowed
```
$ cat -e bytecodes/001.m
push 0
push 2
push 3hu
pall

$ ./monty bytecodes/00.m
L3: usage: push integer
```
This prints the line where the error is and the opcode
```L<line number> usage: <opcode> integer```

### Authors
[Wiseman Umanah](https://github.com/wiseman-umanah)

[Jane mathenge](https://github.com/codingbot995)

You can always contact us if bugs are found in the process of running the program