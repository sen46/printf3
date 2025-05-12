/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:50:22 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/12 20:12:42 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	minus(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	while (fmt[i] == '-')
		i++;
	i = set_len_info(&len, fmt, i);
	spec_judge_minus(fmt[i++], ap, printed_chars, &len);
	*idx = i;
}

void	zero(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	while (fmt[i] == '0')
		i++;
	i = set_len_info(&len, fmt, i);
	spec_judge_zero(fmt[i++], ap, printed_chars, &len);
	*idx = i;
}

void	width(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	i = set_len_info(&len, fmt, i);
	spec_judge_width(fmt[i++], ap, printed_chars, &len);
	*idx = i;
}
