#include "includes/ft_printf.h"

int main()
{
	int ret =       printf("=%0-50p=\n",(void *)0x5592ac2192a0);
	int ft_ret = ft_printf("=%0-50p=\n",(void *)0x5592ac2192a0);
	printf("ret = %d, ft_ret = %d\n", ret, ft_ret);
}
