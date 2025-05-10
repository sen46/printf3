/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_judge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:08:34 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 09:54:49 by ssawa            ###   ########.fr       */
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

void	spec_judge_minus(char c, va_list *ap, int *cnt, t_len len)
{
	if (c == 'c')
		*cnt += minus_c(ap, len);
	else if (c == 's')
		*cnt += minus_s(ap, len);
	else if (c == 'd' || c == 'i')
		*cnt += minus_di(ap, len);
	else if (c == 'p')
		*cnt += minus_ptr(ap, len);
	else if (c == 'u')
		*cnt += minus_u(ap, len);
	else if (c == 'x')
		*cnt += minus_lowerx(ap, len);
	else if (c == 'X')
		*cnt += minus_upperx(ap, len);
}

void	spec_judge_plus(char c, va_list *ap, int *cnt)
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

void	spec_judge_hash(char c, va_list *ap, int *cnt)
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

void	spec_judge_zero(char c, va_list *ap, int *cnt)
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

void	spec_judge_blank(char c, va_list *ap, int *cnt)
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
