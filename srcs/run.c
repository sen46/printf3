/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sen46 <sen46@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:30:00 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/12 19:58:19 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

int	set_len_info(t_len *len, const char *fmt, int i)
{
	len->dot = 0;
	if (ft_isdigit(fmt[i]))
	{
		len->width = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len->width);
	}
	else
		len->width = 0;
	if (fmt[i] == '.')
	{
		i++;
		len->dot = 1;
	}
	if (ft_isdigit(fmt[i]))
	{
		len->precision = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len->precision);
	}
	else
		len->precision = 0;
	return (i);
}

static int	handle_format(const char *fmt, int *i,
		va_list *ap, int *printed_chars)
{
	if (is_specifier(fmt[*i]))
		spec_judge(fmt[(*i)++], ap, printed_chars);
	else if (fmt[*i] == '-')
		minus(fmt, printed_chars, ap, i);
	else if (fmt[*i] == '+')
		plus(fmt, printed_chars, ap, i);
	else if (fmt[*i] == ' ')
		blank(fmt, printed_chars, ap, i);
	else if (fmt[*i] == '#')
		hash(fmt, printed_chars, ap, i);
	else if (fmt[*i] == '0')
		zero(fmt, printed_chars, ap, i);
	else if (ft_isdigit(fmt[*i]) || fmt[*i] == '.')
		width(fmt, printed_chars, ap, i);
	else
		return (-1);
	return (0);
}

int	run(va_list *ap, const char *fmt)
{
	int	i;
	int	printed_chars;

	i = 0;
	printed_chars = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (handle_format(fmt, &i, ap, &printed_chars) == -1)
				return (-1);
		}
		else
		{
			write(1, &fmt[i++], 1);
			printed_chars++;
		}
	}
	return (printed_chars);
}
