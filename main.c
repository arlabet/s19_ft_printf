#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
  //ft_printf("%ss", "test");
  printf("%d\n", (printf("%5c", '\0')));
  printf("%d", ft_printf("%5c", '\0'));
  //printf("%tests", "papa");
}