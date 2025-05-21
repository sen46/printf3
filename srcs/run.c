/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sen46 <sen46@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:30:00 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/17 19:13:58 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	handle_format(const char *fmt, int *i,
		va_list *ap, int *printed_chars)
{
	t_flag	flag;

	if (is_specifier(fmt[*i]))
		spec_judge(fmt[(*i)++], ap, printed_chars);
	else if ((*i) += flag_check(&fmt[(*i)], &flag))
	{
		flag.spec = fmt[(*i)++];
		spec_judge_flag(&flag, ap, printed_chars);
		// 処理
		// フローチャートを参照
	}
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
