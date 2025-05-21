/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_judge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:08:34 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/20 21:19:31 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

void	spec_judge(char c, va_list *ap, int *cnt)
{
	if (c == 'c')
		*cnt += process_c(ap);
	else if (c == 's')
		*cnt += process_s(ap);
	else if (c == 'd')
		*cnt += process_d(ap);
	else if (c == 'i')
		*cnt += process_i(ap);
	else if (c == 'p')
		*cnt += process_ptr(ap);
	else if (c == 'u')
		*cnt += process_u(ap);
	else if (c == 'x')
		*cnt += process_lowerx(ap);
	else if (c == 'X')
		*cnt += process_upperx(ap);
	else if (c == '%')
		*cnt += process_per();
}


void	spec_judge_flag(t_flag *flag, va_list *ap, int *cnt)
{
	if (flag->spec == 'c')
		*cnt += process_c_flag(flag, ap);
	else if (flag->spec == 's')
	{
		*cnt += process_s_flag(flag, ap);
	}
	else if (flag->spec == 'd' || flag->spec == 'i')
		*cnt += process_di_flag(flag, ap);
	else if (flag->spec == 'u')
		*cnt += process_u_flag(flag, ap);
	else if (flag->spec == 'x')
	{
		*cnt += process_lowerx_flag(flag, ap);
	}
	else if (flag->spec == 'X')
		*cnt += process_upperx_flag(flag, ap);
	else if (flag->spec == 'p')
		*cnt += process_p_flag(flag, ap);
}

/*
void	spec_judge_flag(t_flag *flag, va_list *ap, int *cnt)
{
	t_val	val;

	if (flag->spec == 'c')
	{
		val.c = (unsigned char)va_arg(*ap, int);
		val.str = ft_strdup(&val.c);
	}
	else if (flag->spec == 's')
		val.str = va_arg(*ap, char *);
	else if (flag->spec == 'd' || flag->spec == 'i')
		val.sint= va_arg(*ap, int);
	else if (flag->spec == 'u')
		val.uint = va_arg(*ap, unsigned int);
	else if (flag->spec == 'x' || flag->spec == 'X')
		val.uint = va_arg(*ap, unsigned int);
	else if (flag->spec == 'p')
	{

	}
}
*/
