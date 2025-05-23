/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:37:24 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/23 22:41:11 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_process.h"

static void	process_p_flag_null(t_flag *flag, t_padding *pad)
{
	int	len;

	len = ft_max(flag->width - 5, 0);
	pad->middle = ft_strdup("(nil)");
	if (flag->minus)
	{
		pad->right = ft_calloc(len + 1, sizeof(char));
		ft_memset(pad->right, ' ', len);
		pad->left = ft_strdup("");
	}
	else
	{
		pad->left = ft_calloc(len + 1, sizeof(char));
		ft_memset(pad->left, ' ', len);
		pad->right = ft_strdup("");
	}
	output_padding_nil(pad);
}

static void	process_sub(t_flag *flag, t_padding *pad, const int len)
{
	if (flag->blank || flag->plus)
		flag->precision++;
	flag->width = ft_max(flag->width, flag->precision);
	if (flag->precision != -1 && flag->dot)
		flag->zero = 0;
	if (flag->minus)
	{
		pad->left = ft_calloc(flag->precision - len + 1, sizeof(char));
		ft_memset(pad->left, '0', flag->precision - len);
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

int	process_p_flag(t_flag *flag, va_list *ap)
{
	void		*val;
	int			len;
	t_padding	pad;

	val = va_arg(*ap, void *);
	if (val == NULL)
		process_p_flag_null(flag, &pad);
	else
	{
		pad.middle = ft_itoa_base((unsigned long)val, "0123456789abcdef");
		len = ft_strlen(pad.middle);
		flag->precision = ft_max(len, flag->precision);
		flag->precision += 2;
		process_sub(flag, &pad, len);
		output_padding(flag, &pad);
	}
	free_padding(&pad);
	return (pad.llen + pad.rlen + pad.mlen);
}
