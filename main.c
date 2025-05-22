#include "includes/ft_printf.h"

int main()
{
	int ret =       printf("=% #-+02.3p=\n",(void*)0x5d29fa520b20);
	// int ft_ret = ft_printf("=% #-+0p=\n",(void*)0x5d29fa520b20);
	// printf("ret = %d, ft_ret = %d\n", ret, ft_ret);
}
