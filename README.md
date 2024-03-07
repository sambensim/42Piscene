# Project 4 - C01
### ex00 - ft_ft
Don't forget to turn spaces into tabs if using VSCode! (ctrl+a>ctrl+shift+p>"convert indents to tabs")
##### Pointers
A pointer is a variable that contains a memory address, usually for another variable
- `datatype * pointer_name;` declares a pointer (to a pseudo-random value)
- `pointer_name = &variable_name;` initializes a pointer to a variable's memory address (`&` before a variable name gives the memory address of that variable)
- `*pointer_name` accesses the value the pointer holds the memory address of (in this way, the address operator `&` is the reverse of `*`: `&` returns the memory address of a variable and `*` returns the value held in a memory address)
Pointers must be declared to the same datatype they will represent
___
##### Problem
Create a function that takes a pointer to int as a parameter, and sets the value "42"
to that int.
Function Prototype - `void  ft_ft(int *nbr);`
> In other words - given a pointer to an int variable, change the int variable to 42
___
##### Code
```C
void  ft_ft(int *nbr)
{
  *nbr = 42;
}
//test by uncommenting main:
/*void main() {
  #include<unistd.h>
  int a = 10;
  int * ptra = &a
  ft_ft(*ptra);
  write(1,&a,1);
}*/
```
