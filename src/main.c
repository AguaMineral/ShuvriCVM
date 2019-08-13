#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum{
    PSH, // Push to the stack
    ADD, // pops to values opn top of the stack, add them pushes to stack
    POP, //pop the value on the stack and print it for debugging
    SET, // set register A to 0
    HLT // stop the program
} InstructionSet;

typedef enum{
    A, B, C, D, E, F,
    NUM_OF_REGISTERS
}Registers;

const int program[] = { //example program
    PSH, 5,
    PSH, 6,
    ADD,
    PSH, 7,
    ADD,
    POP,
    HLT
};

bool running = true; 
int ip = 0; // this is de instruction pointer, the program counter 
int sp = -1; // empty stack(-1) pointer, the stack size
int stack[256];
int registers[NUM_OF_REGISTERS];

int fetch() // one of the VM steps, extract the instruction
{
    return program[ip];
}

void eval(int instr) // evaluate the isntruction
{
    switch (instr)
    {
    case HLT:
        running = false;
        break;

    case PSH:
        /*
            sp is incremented to set the size of our stack
            then in that position we alocate the program next value that is the number we want to
            operate
        */
        sp++;
        stack[sp] = program[++ip];
        break;
        
    case POP:{
        //store the value at the stack in val_popped THEN decrement the sp
        int val_popped = stack[sp--];
        printf("popped %d\n", val_popped);
        break;
    }
    case ADD:{
        //1º pop the stack and store it as a var
        int a = stack[sp--];

        //2º pop the top of the stack and store it as b var
        int b = stack[sp--];

        //3º add the result and push it to the stack
        int result = b + a;
        sp++; 
        stack[sp] = result;
    }

    }
}

int main()
{
    while (running)
    {
        eval(fetch());
        ip++; // increment the ip every iteration
    }
    return 0;
}


