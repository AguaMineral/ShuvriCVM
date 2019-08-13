# ShuvriCVM

## English Description

This is a learning excercise that consist on building a Virtual machine With C, GCC and CMake. My main goal is to learn throu this. Deeper understanding of low level code.

Instruction set..

PSH 5       ; pushes 5 to the stack
PSH 10      ; pushes 10 to the stack
ADD         ; pops two values on top of the stack, adds them pushes to stack
POP         ; pops the value on the stack, will also print it for debugging
SET A 0     ; sets register A to 0
HLT         ; stop the program

How a VM works?
    extract instruction, decode instruction, execute decoded instruction.

our stack will be an array instead of a linked list becouse it will hace a fixed size 
stacks are LIFO
## Descripción en español

Esto es un ejercicio de aprendizaje que consiste en crear una Máquina virtual con C, GCC y CMake. Mi objetivo es aprender durante el proceso. Un conocimiento más profundo de programación de bajo nivel y de cómo funcionan los lenguajes de programación.

