#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
  //printf("%s\n", "papa");
  void *p;
  int a;
  a = 2;
  p = &a;
 printf ("%d", ft_printf("Ceci est un test : %c %s %p %d %u %x %X", 'p', "papa", p, 1123, 15454876445, 1818, 1818));
   return 0;
}