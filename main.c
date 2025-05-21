#include "includes/ft_printf.h"

int main()
{
	int ret, ft_ret;
	// ret = printf("=%-#020.03p=\n", 114514);
	// ft_ret = ft_printf("=%-#020.03p=\n", 114514);
	   ret =    printf("=%012x=\n", 0);
	ft_ret = ft_printf("=%012x=\n", 0);
	printf("ret = %d, ft_ret = %d\n", ret, ft_ret);
	return (0);
}
