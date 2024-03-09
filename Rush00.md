# Rush00
### Problem
> Write a function 'rush' that takes to integers and prints a rectangle made of chars to the screen, wuth dimensions defined by the given integers.
> For subject 00, the vertices should be 'o's, the left and right edges '|', the top and bottom edges '-', and the center ' '
### Code
```C
//all untested
void  ft_putchar(char character)
{
  write(1, &character, 1);
}

void  rush(int w, int h) //for subjects beyond 00, a wrapper function could be made which changes the characters printed for parts of the rect
{
  int  x;
  int  y;

  y = 0;
  while (y < h)
  {
    x = 0;
    while (x < w)
    {
      if ((x == w-1 || x == 0) && (y == h-1 || y == 0)) //to increase readability, the condition for each axis could be made into a variable
        ft_putchar('o');
      else if ((x == w-1 || x == 0))
        ft_putchar('|');
      else if ((y == h-1 || y == 0))
        ft_putchar('-');
      else
        ft_putchar(' ');
      x++;
    }
    ft_putchar('\n');
    y++;
  }
}
```
### Code (for beyond subject 00)
```C
void  ft_putchar(char character)
{
  write(1, &character, 1);
}

void  rush_inside(int w, int h, char vertex, char lr_side, char tb_side, char inside)
{
  int  x;
  int  y;
  int x_isonedge;
  int y_isonedge;

  y = 0;
  while (y < h)
  {
    x = 0;
    y_isonedge = (y == h-1 || y == 0);
    while (x < w)
    {
      x_isonedge = (x == w-1 || x == 0);
      if (x_isonedge && y_isonedge)
        ft_putchar(vertex);
      else if (x_isonedge)
        ft_putchar(lr_side);
      else if (y_isonedge)
        ft_putchar(tb_side);
      else
        ft_putchar(inside);
      x++;
    }
    ft_putchar('\n');
    y++;
  }
}

void rush(int w, int h)
{
  rush_inside(w, h, 'o', '|', '-', ' ')
}
```
