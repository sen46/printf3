/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:56:24 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/12 20:12:49 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	plus(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	while (fmt[i] == '+')
		i++;
	i = set_len_info(&len, fmt, i);
	spec_judge_plus(fmt[i++], ap, printed_chars, len);
	*idx = i;
}

void	hash(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	while (fmt[i] == '#')
		i++;
	i = set_len_info(&len, fmt, i);
	spec_judge_hash(fmt[i++], ap, printed_chars, len);
	*idx = i;
}

void	blank(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	while (fmt[i] == ' ')
		i++;
	i = set_len_info(&len, fmt, i);
	spec_judge_blank(fmt[i++], ap, printed_chars, len);
	*idx = i;
}
