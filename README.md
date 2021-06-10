# minic-compiler

Course project of the course "Compiler Principle", 2021 spring. It compiles a mini-C program to risc-V assembly.

## How to run

```
cd src
cmake .
make

cd bin
./main -S testcase.c -o testcase.S
```