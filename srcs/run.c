/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assistant <assistant@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:30:00 by assistant         #+#    #+#             */
/*   Updated: 2025/05/09 19:23:56 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"

int		run(va_list *ap, const char *fmt)
{
	int	i;
	t_len	len;
	int printed_chars;

	i = 0;
	printed_chars = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			len.width = 0;
			i++;
			if (is_specifier(fmt[i]))
				spec_judge(fmt[i++], ap, &printed_chars);
			else if (fmt[i] == '-')
			{
				if (ft_isdigit(fmt[++i]))
				{
					len.width = ft_atoi(&fmt[i]);
					i += ft_nbrlen_dec(len.width);
				}
				else
					len.width = 0;
				// len.width = ft_atoi(&fmt[++i]);
				// i += ft_nbrlen_dec(len.width);
				if (fmt[i] == '.')
					i++;
				if (ft_isdigit(fmt[i]))
				{
					len.precision = ft_atoi(&fmt[i]);
					i += ft_nbrlen_dec(len.precision);
				}
				else
					len.precision = 0;
				// len.precision = ft_atoi(&fmt[i]);
				// printf("width = %d\nprecision = %d\n", len.width, len.precision);
				// printf("\n指定子 =%c=\n", fmt[i++]);
				spec_judge_minus(fmt[i++] , ap, &printed_chars, len);
			}
			else if (fmt[i] == '+')
			{
			}
			else if(fmt[i] == ' ')
			{
			}
			else if (fmt[i] == '#')
			{
			}
			else if (fmt[i] == '0')
			{
			}
			else if (ft_isdigit(fmt[i]))
			{
				len.width = ft_atoi(&fmt[i]);
				i += ft_nbrlen_dec(len.width);
				if (fmt[i] == '.')
					i++;
				if (ft_isdigit(fmt[i]))
				{
					len.precision = ft_atoi(&fmt[i]);
					i += ft_nbrlen_dec(len.precision);
				}
				else
					len.precision = 0;
				// len.precision = ft_atoi(&fmt[i]);
				// printf("fmt[i] =%c=", fmt[i-1]);
				spec_judge_minus(fmt[i++] , ap, &printed_chars, len);
			}
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

