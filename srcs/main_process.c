/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sen46 <sen46@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:30:00 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/22 16:13:36 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	handle_format(const char *fmt, int *i,
		va_list *ap, int *printed_chars)
{
	t_flag	flag;
	int		f;

	f = 0;
	if (is_specifier(fmt[*i]))
	{
		spec_judge(fmt[(*i)++], ap, printed_chars);
		f = 1;
	}
	else
	{
		f = flag_check(&fmt[(*i)], &flag);
		(*i) += f;
		flag.spec = fmt[(*i)++];
		spec_judge_flag(&flag, ap, printed_chars);
	}
	if (f == 0)
		return (-1);
	return (0);
}

int	main_process(va_list *ap, const char *fmt)
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
