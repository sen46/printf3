/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec1_judge_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:09:37 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/12 20:20:09 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	spec_judge_minus(char c, va_list *ap, int *cnt, t_len *len)
{
	if (c == 'c')
		*cnt += minus_c(ap, *len);
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

void	spec_judge_zero(char c, va_list *ap, int *cnt, t_len *len)
{
	if (c == 'd' || c == 'i')
		*cnt += zero_di(ap, len);
	else if (c == 'u')
		*cnt += zero_u(ap, len);
	else if (c == 'x')
		*cnt += zero_lowerx(ap, len);
	else if (c == 'X')
		*cnt += zero_upperx(ap, len);
}

void	spec_judge_dot(char c, va_list *ap, int *cnt, t_len len)
{
	if (c == 'd' || c == 'i')
		*cnt += dot_di(ap, len);
	else if (c == 's')
		*cnt += dot_s(ap, len);
	else if (c == 'u')
		*cnt += dot_u(ap, len);
	else if (c == 'x')
		*cnt += dot_lowerx(ap, len);
	else if (c == 'X')
		*cnt += dot_upperx(ap, len);
}

void	spec_judge_width(char c, va_list *ap, int *cnt, t_len *len)
{
	if (c == 'c')
		*cnt += width_c(ap, len);
	else if (c == 's')
		*cnt += width_s(ap, len);
	else if (c == 'd' || c == 'i')
		*cnt += width_di(ap, len);
	else if (c == 'p')
		*cnt += width_ptr(ap, len);
	else if (c == 'u')
		*cnt += width_u(ap, len);
	else if (c == 'x')
		*cnt += width_lowerx(ap, len);
	else if (c == 'X')
		*cnt += width_upperx(ap, len);
}
