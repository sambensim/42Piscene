# Project 4 - C01
### ex00 - ft_ft
Don't forget to turn spaces into tabs if using VSCode! (ctrl+a>ctrl+shift+p>"convert indents to tabs")
##### Problem
Create a function that takes a pointer to int as a parameter, and sets the value "42"
to that int.
> In other words - given a pointer to an int variable, change the int variable to 42
___
##### Pointers
A pointer is a variable that contains a memory address, usually for another variable
- `datatype *pointer_name;` declares a pointer (to a pseudo-random value)
- `pointer_name = &variable_name;` initializes a pointer to a variable's memory address (`&` before a variable name gives the memory address of that variable)
- `*pointer_name` accesses the value the pointer holds the memory address of (in this way, the address operator `&` is the reverse of `*`: `&` returns the memory address of a variable and `*` returns the value held in a memory address)
Pointers must be declared to the same datatype they will represent
___
##### Code
>```C
>void	ft_ft(int *nbr)
>{
>	  *nbr = 42;
>}
>//I'm unsure how to test if this works
>```
### ex01 - ft_ultimate_ft
##### Problem
Create a function that takes a pointer to pointer to pointer to pointer to pointer
to pointer to pointer to pointer to pointer to int as a parameter and sets the value
"42" to that int.
> In other words - given nine pointers to an int variable, change the int variable to 42
___
##### Pointers to Pointers
Pointers can also point to other pointers. To declare one such 'sub-pointer,' add an additional asterisk to its declaration - `datatype **pointer_to_pointer_name`. Access the pointer with the same number of asterisks before its name.
___
##### Code
>```C
>void	ft_ultimate_ft(*********nbr)
>{
>	*********nbr = 42;
>}
>//I'm unsure how to test if this works
>```
### ex02 - ft_swap
##### Problem
Create a function that swaps the value of two integers whose addresses are entered
as parameters.
> In other words - given two pointers to int variables, swap the values of the int variables
___
##### Code
>```C
>void	ft_swap(int *a, int *b)
>{
>	int temp;
>	temp = *a;
>	*a = *b;
>	*b = temp;
>}
>```
