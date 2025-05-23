/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_di_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:18:36 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/22 18:28:01 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	output_padding_sub(t_flag *flag, t_padding *pad)
{
	if (!flag->sign && flag->zero && pad->llen)
		pad->left[0] = '-';
	else if (!flag->sign && pad->rlen)
		pad->right[0] = '-';
	else if (flag->zero && flag->plus && pad->llen)
		pad->left[0] = '+';
	else if (flag->plus && pad->rlen)
		pad->right[0] = '+';
	else if (flag->zero && flag->blank && pad->llen)
		pad->left[0] = ' ';
	else if (flag->blank && pad->rlen)
		pad->right[0] = ' ';
	if (pad->right[0] == pad->left[0] && (pad->right[0] == '+' || \
pad->left[0] == '-'))
		pad->right[0] = '0';
	write(1, pad->left, pad->llen);
	write(1, pad->right, pad->rlen);
	write(1, pad->middle, pad->mlen);
}

static void	output_padding(t_flag *flag, t_padding *pad)
{
	pad->llen = ft_strlen(pad->left);
	pad->mlen = ft_strlen(pad->middle);
	pad->rlen = ft_strlen(pad->right);
	if (flag->minus)
	{
		if (!flag->sign)
			pad->left[0] = '-';
		else if (flag->plus && flag->sign)
			pad->left[0] = '+';
		else if (flag->blank && flag->sign)
			pad->left[0] = ' ';
		ft_putstr_fd(pad->left, 1);
		ft_putstr_fd(pad->middle, 1);
		ft_putstr_fd(pad->right, 1);
	}
	else
		output_padding_sub(flag, pad);
}

static void	main_process_sub(t_padding *pad, t_flag *flag)
{
	if (flag->minus)
	{
		pad->left = ft_calloc(flag->precision - ft_strlen(pad->middle) + 1, 1);
		ft_memset(pad->left, '0', flag->precision - ft_strlen(pad->middle));
		pad->right = ft_calloc(flag->width - flag->precision + 1, 1);
		ft_memset(pad->right, ' ', flag->width - flag->precision);
	}
	else
	{
		pad->right = ft_calloc(flag->precision - ft_strlen(pad->middle) + 1, 1);
		ft_memset(pad->right, '0', flag->precision - ft_strlen(pad->middle));
		pad->left = ft_calloc(flag->width - flag->precision + 1, 1);
		if (flag->zero)
			ft_memset(pad->left, '0', flag->width - flag->precision);
		else
			ft_memset(pad->left, ' ', flag->width - flag->precision);
	}
}

static void	main_process_di(long val, t_flag *flag, t_padding *pad)
{
	if (flag->dot && val == 0 && flag->precision <= 0)
		pad->middle = ft_strdup("");
	else
		pad->middle = ft_itoa(val);
	flag->precision = ft_max(ft_strlen(pad->middle), flag->precision);
	if (flag->blank || flag->plus || !flag->sign)
		flag->precision++;
	flag->width = ft_max(flag->width, flag->precision);
	if (flag->precision != -1 && flag->dot)
		flag->zero = 0;
	main_process_sub(pad, flag);
}

int	process_di_flag(t_flag *flag, va_list *ap)
{
	int			val;
	t_padding	pad;

	val = va_arg(*ap, int);
	if (val >= 0)
		flag->sign = 1;
	else
		flag->sign = 0;
	if (val >= 0)
		main_process_di(val, flag, &pad);
	else
		main_process_di(-1LL * val, flag, &pad);
	output_padding(flag, &pad);
	free_padding(&pad);
	return (pad.llen + pad.mlen + pad.rlen);
}
