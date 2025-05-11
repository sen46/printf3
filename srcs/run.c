/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assistant <assistant@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:30:00 by assistant         #+#    #+#             */
/*   Updated: 2025/05/10 15:27:05 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

void	minus(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	len.dot = 0;
	while (fmt[i] == '-')
		i++;
	if (ft_isdigit(fmt[i]))
	{
		len.width = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.width);
	}
	else
		len.width = 0;
	if (fmt[i] == '.')
	{
		len.dot = 1;
		i++;
	}
	if (ft_isdigit(fmt[i]))
	{
		len.precision = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.precision);
	}
	else
		len.precision = 0;
	spec_judge_minus(fmt[i++], ap, printed_chars, &len);
	*idx = i;
}

void	plus(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	len.dot = 0;
	while (fmt[i] == '+')
		i++;
	if (ft_isdigit(fmt[i]))
	{
		len.width = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.width);
	}
	else
		len.width = 0;
	if (fmt[i] == '.')
	{
		i++;
		len.dot = 1;
	}
	if (ft_isdigit(fmt[i]))
	{
		len.precision = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.precision);
	}
	else
		len.precision = 0;
	spec_judge_plus(fmt[i++], ap, printed_chars, len);
	*idx = i;
}

void	hash(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	len.dot = 0;
	while (fmt[i] == '#')
		i++;
	if (ft_isdigit(fmt[i]))
	{
		len.width = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.width);
	}
	else
		len.width = 0;
	if (fmt[i] == '.')
	{
		i++;
		len.dot = 1;
	}
	if (ft_isdigit(fmt[i]))
	{
		len.precision = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.precision);
	}
	else
		len.precision = 0;
	spec_judge_hash(fmt[i++], ap, printed_chars, len);
	*idx = i;
}

void	zero(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	len.dot = 0;
	while (fmt[i] == '0')
		i++;
	if (ft_isdigit(fmt[i]))
	{
		len.width = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.width);
	}
	else
		len.width = 0;
	if (fmt[i] == '.')
	{
		i++;
		len.dot = 1;
	}
	if (ft_isdigit(fmt[i]))
	{
		len.precision = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.precision);
	}
	else
		len.precision = 0;
	spec_judge_zero(fmt[i++], ap, printed_chars, &len);
	*idx = i;
}

void	blank(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	len.dot = 0;
	while (fmt[i] == ' ')
		i++;
	if (ft_isdigit(fmt[i]))
	{
		len.width = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.width);
	}
	else
		len.width = 0;
	if (fmt[i] == '.')
	{
		i++;
		len.dot = 1;
	}
	if (ft_isdigit(fmt[i]))
	{
		len.precision = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.precision);
	}
	else
		len.precision = 0;
	spec_judge_blank(fmt[i++], ap, printed_chars, len);
	*idx = i;
}

void	width(const char *fmt, int *printed_chars, va_list *ap, int *idx)
{
	t_len	len;
	int		i;

	i = *idx;
	len.dot = 0;
	if (ft_isdigit(fmt[i]))
	{
		len.width = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.width);
	}
	else
		len.width = 0;
	if (fmt[i] == '.')
	{
		len.dot = 1;
		i++;
	}
	if (ft_isdigit(fmt[i]))
	{
		len.precision = ft_atoi(&fmt[i]);
		i += ft_nbrlen_dec(len.precision);
	}
	else
		len.precision = 0;
	spec_judge_width(fmt[i++], ap, printed_chars, &len);
	*idx = i;
}

///////////////////////////////////////////////////////////////////////////////

int		run(va_list *ap, const char *fmt)
{
	int	i;
	int printed_chars;

	i = 0;
	printed_chars = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (is_specifier(fmt[i]))
				spec_judge(fmt[i++], ap, &printed_chars);
			else if (fmt[i] == '-')
				minus(fmt, &printed_chars, ap, &i);
			else if (fmt[i] == '+')
				plus(fmt, &printed_chars, ap, &i);
			else if(fmt[i] == ' ')
				blank(fmt, &printed_chars, ap, &i);
			else if (fmt[i] == '#')
				hash(fmt, &printed_chars, ap, &i);
			// else if (fmt[i] == '.')
			else if (fmt[i] == '0')
				zero(fmt, &printed_chars, ap, &i);
			else if (ft_isdigit(fmt[i]) || fmt[i] == '.')
				width(fmt, &printed_chars, ap, &i);
			else
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
