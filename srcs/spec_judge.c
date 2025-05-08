/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_judge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:08:34 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/07 22:17:55 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	spec_judge_zero(char c, va_list *ap, int *cnt, int len)
{
	if (c == 'd')
		*cnt += process_d_flag0(ap, len);
	else if (c == 'i')
		*cnt += process_i_flag0(ap, len);
	else if (c == 's')
		*cnt += process_s_flag0(ap, len);
	else if (c == 'u')
		*cnt += process_u_flag0(ap, len);
	else if (c == 'x')
		*cnt += process_lowerx_flag0(ap, len);
	else if (c == 'X')
		*cnt += process_upperx_flag0(ap, len);
}

void	spec_judge_width(char c, va_list *ap, int *cnt, int len)
{
	if (c == 'c')
		*cnt += process_c_width(ap, len);
	else if (c == 's')
		*cnt += process_s_width(ap, len);
	else if (c == 'p')
		*cnt += process_ptr_width(ap, len);
	else if (c == 'd')
		*cnt += process_d_width(ap, len);
	else if (c == 'i')
		*cnt += process_i_width(ap, len);
	else if (c == 'u')
		*cnt += process_u_width(ap, len);
	else if (c == 'x')
		*cnt += process_lowerx_width(ap, len);
	else if (c == 'X')
		*cnt += process_upperx_width(ap, len);
}

void	spec_judge_minus(char c, va_list *ap, int *cnt, int len)
{
	if (c == 'c')
		*cnt += process_c_minus(ap, len);
	else if (c == 's')
		*cnt += process_s_minus(ap, len);
}
