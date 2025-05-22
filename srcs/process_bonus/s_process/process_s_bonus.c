/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:37:48 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/22 15:47:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	output_padding(t_flag *flag, t_padding *pad)
{
	pad->llen = ft_strlen(pad->left);
	pad->mlen = ft_min(flag->precision, ft_strlen(pad->middle));
	pad->rlen = ft_strlen(pad->right);
	write(1, pad->left, pad->llen);
	write(1, pad->middle, pad->mlen);
	write(1, pad->right, pad->rlen);
}

static void	process_s_flag_sub2(t_flag *flag, t_padding *pad)
{
	if (flag->minus)
	{
		pad->left = ft_strdup("");
		pad->right = ft_calloc(flag->width - flag->precision + 1, sizeof(char));
		ft_memset(pad->right, ' ', flag->width - flag->precision);
	}
	else
	{
		pad->right = ft_strdup("");
		pad->left = ft_calloc(flag->width - flag->precision + 1, sizeof(char));
		ft_memset(pad->left, ' ', flag->width - flag->precision);
	}
}

static void	process_s_flag_sub1(const char *str, t_flag *flag, t_padding *pad)
{
	if (str == NULL && flag->precision < 6)
	{
		free(pad->middle);
		if (flag->width >= flag->precision)
		{
			pad->middle = ft_calloc(flag->precision + 1, sizeof(char));
			ft_memset(pad->middle, ' ', flag->precision);
		}
		else
		{
			pad->middle = ft_calloc(ft_max(flag->width, 0) + 1, sizeof(char));
			ft_memset(pad->middle, ' ', ft_max(flag->width, 0));
		}
	}
	flag->width = ft_max(flag->width, flag->precision);
}

int	process_s_flag(t_flag *flag, va_list *ap)
{
	char		*str;
	t_padding	pad;

	str = va_arg(*ap, char *);
	if (str == NULL)
		pad.middle = ft_strdup("(null)");
	else
		pad.middle = ft_strdup(str);
	pad.mlen = ft_strlen(pad.middle);
	if (!flag->dot)
		flag->precision = ft_strlen(pad.middle);
	else
		flag->precision = ft_max(0, ft_min(flag->precision, pad.mlen));
	process_s_flag_sub1(str, flag, &pad);
	process_s_flag_sub2(flag, &pad);
	output_padding(flag, &pad);
	free_padding(&pad);
	return (pad.llen + pad.mlen + pad.rlen);
}
