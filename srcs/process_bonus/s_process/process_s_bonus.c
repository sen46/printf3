/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:37:48 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/20 21:10:23 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"
#include <stdlib.h>
// va_arg()の返り値がNULLの時をまだ実装していない

static void	output_padding(t_flag *flag, t_padding *pad)
{
	// pad->llen = ft_max(0, ft_strlen(pad->left));
	// pad->mlen = ft_max(0, ft_min(flag->precision, ft_strlen(pad->middle)));
	// pad->rlen = ft_max(0, ft_strlen(pad->right));
	pad->llen = ft_strlen(pad->left);
	pad->mlen = ft_min(flag->precision, ft_strlen(pad->middle));
	pad->rlen = ft_strlen(pad->right);
	// write(1, "\n", 1);
	// ft_putnbr_fd(pad->llen, 1);
	// write(1, "\n", 1);
	// ft_putnbr_fd(pad->mlen, 1);
	// write(1, "\n", 1);
	// ft_putnbr_fd(pad->rlen, 1);
	write(1, pad->left, pad->llen);
	write(1, pad->middle, pad->mlen);
	write(1, pad->right, pad->rlen);
}

int	process_s_flag(t_flag *flag, va_list *ap)
{
	char	*str;
	t_padding	pad;

	str = va_arg(*ap, char *);
	if (str == NULL)
		pad.middle = ft_strdup("(null)");
	else
		pad.middle = ft_strdup(str);
	if (!flag->dot)
		flag->precision = ft_strlen(pad.middle);
	else
		flag->precision = ft_max(0, ft_min(flag->precision, ft_strlen(pad.middle)));
	// flag->width = ft_max(flag->width, flag->precision);
	// if (str == NULL && flag->width < 6)
	if (str == NULL && flag->precision < 6)
	{
		free(pad.middle);
		// pad.middle = ft_strdup("");
		if (flag->width >= flag->precision)
		{
			pad.middle = ft_calloc(flag->precision + 1, sizeof(char));
			ft_memset(pad.middle, ' ', flag->precision);
		}
		else
		{
			pad.middle = ft_calloc(ft_max(flag->width, 0) + 1, sizeof(char));
			ft_memset(pad.middle, ' ', ft_max(flag->width, 0));
			// pad.middle = ft_strdup("");
		}
	}
	flag->width = ft_max(flag->width, flag->precision);
	if (flag->minus)
	{
		pad.left = ft_strdup("");
		pad.right = ft_calloc(flag->width - flag->precision + 1, sizeof(char));
		ft_memset(pad.right, ' ', flag->width - flag->precision);
	}
	else
	{
		pad.right = ft_strdup("");
		pad.left = ft_calloc(flag->width - flag->precision + 1, sizeof(char));
		ft_memset(pad.left, ' ', flag->width - flag->precision);
	}
	output_padding(flag, &pad);
	free_padding(&pad);
	// printf("pad.llen = %d, pad.mlen = %d, pad.rlen = %d\n", pad.llen, pad.mlen, pad.rlen);
	// printf("%d\n", pad.llen+ pad.mlen+ pad.rlen);
	return (pad.llen + pad.mlen + pad.rlen);
}
