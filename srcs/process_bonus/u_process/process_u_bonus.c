/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:18:11 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/22 15:50:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	output_padding(t_flag *flag, t_padding *pad)
{
	pad->llen = ft_strlen(pad->left);
	pad->mlen = ft_strlen(pad->middle);
	pad->rlen = ft_strlen(pad->right);
	if (flag->minus)
	{
		ft_putstr_fd(pad->left, 1);
		ft_putstr_fd(pad->middle, 1);
		ft_putstr_fd(pad->right, 1);
	}
	else
	{
		ft_putstr_fd(pad->left, 1);
		ft_putstr_fd(pad->right, 1);
		ft_putstr_fd(pad->middle, 1);
	}
}

static void	process_u_flag_sub(t_flag *flag, t_padding *pad)
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
		{
			ft_memset(pad->left, '0', flag->width - flag->precision);
		}
		else
			ft_memset(pad->left, ' ', flag->width - flag->precision);
	}
}

int	process_u_flag(t_flag *flag, va_list *ap)
{
	unsigned int	val;
	t_padding		pad;

	val = va_arg(*ap, unsigned int);
	if (flag->dot && val == 0 && flag->precision <= 0)
		pad.middle = ft_strdup("");
	else
		pad.middle = ft_itoa(val);
	flag->precision = ft_max(ft_strlen(pad.middle), flag->precision);
	flag->width = ft_max(flag->width, flag->precision);
	if (flag->precision != -1 && flag->dot)
		flag->zero = 0;
	process_u_flag_sub(flag, &pad);
	output_padding(flag, &pad);
	free_padding(&pad);
	return (pad.llen + pad.mlen + pad.rlen);
}
