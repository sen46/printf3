/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:00:24 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/18 18:47:01 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "libft/libft.h"
// 動作確認OK

static t_flag	flag_init(void)
{
	t_flag	flag;

	flag.minus = 0;
	flag.blank = 0;
	flag.dot = 0;
	flag.hash = 0;
	flag.plus = 0;
	flag.zero = 0;
	flag.precision = -1;
	// flag.precision = 0;
	flag.width = -1;
	// flag.width = 0;
	return (flag);
}

static int	flag_exist(t_flag *flag)
{
	if (flag->minus || flag->dot || flag->plus || \
flag->zero || flag->hash || flag->blank || \
flag->precision || flag->width)
		return (1);
	else
		return (0);
}

static int	is_flag(const char c, t_flag *flag)
{
	int	rtn;

	rtn = 1;
	if (c == '-')
		flag->minus = 1;
	else if (c == ' ')
		flag->blank = 1;
	else if (c == '+')
		flag->plus = 1;
	else if (c == '#')
		flag->hash = 1;
	else if (c == '0')
		flag->zero = 1;
	else
		rtn = 0;
	return (rtn);
}

static void	flag_check_sub(const char *fmt, t_flag *flag, int *idx)
{
	if (is_flag(fmt[*idx], flag))
	{
	}
	else if (ft_isdigit(fmt[*idx]))
	{
		if (!flag->dot)
			flag->width = ft_atoi(&fmt[*idx]);
		else
			flag->precision = ft_atoi(&fmt[*idx]);
		// (*idx) += ft_nbrlen_dec(flag->width);
		if (!flag->dot)
			(*idx) += ft_nbrlen_dec(flag->width) - 1;
		else
			(*idx) += ft_nbrlen_dec(flag->precision) - 1;
	}
	else if (fmt[*idx] == '.')
	{
		flag->dot = 1;
		if (fmt[++(*idx)] == '0')
			flag->zero = 1;
		else if (ft_isdigit(fmt[*idx]))
		{
			flag->precision = ft_atoi(&fmt[*idx]);
			(*idx) += ft_nbrlen_dec(flag->precision) - 1;
			// (*idx) += ft_nbrlen_dec(flag->precision);
		}
		else
			(*idx)--;
	}
}

// どのようなflagが立っているかを調べる
// 立ったflagを構造体で管理する
int	flag_check(const char *fmt, t_flag *flag)
{
	int	idx;

	*flag = flag_init();
	idx = 0;
	while (fmt[idx] && !is_specifier(fmt[idx]))
	{
		flag_check_sub(fmt, flag, &idx);
		idx++;
	}
	if (flag_exist(flag))
		return (idx);
	else
		return (0);
}

