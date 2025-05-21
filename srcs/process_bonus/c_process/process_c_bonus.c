/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:35:45 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/18 20:53:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	output_padding(t_padding *pad)
{
	write(1, pad->left, pad->llen);
	write(1, pad->middle, pad->mlen);
	write(1, pad->right, pad->rlen);
}

static void	pad_len_init(t_padding *pad)
{
	pad->llen = ft_strlen(pad->left);
	pad->mlen = 1;
	pad->rlen = ft_strlen(pad->right);
}

int	process_c_flag(t_flag *flag, va_list *ap)
{
	char	c;
	t_padding	pad;

	c = (unsigned char)va_arg(*ap, int);
	pad.middle = ft_calloc(2, sizeof(char));
	pad.middle[0] = c;
	flag->width = ft_max(flag->width - 1, 0);
	if (flag->minus)
	{
		pad.left = ft_strdup("");
		pad.right = ft_calloc(ft_max(1, flag->width + 1), sizeof(char));
		ft_memset(pad.right, ' ', ft_max(0, flag->width));
	}
	else
	{
		pad.right = ft_strdup("");
		pad.left = ft_calloc(ft_max(1, flag->width + 1), sizeof(char));
		ft_memset(pad.left, ' ', ft_max(0, flag->width));
	}
	pad_len_init(&pad);
	output_padding(&pad);
	free_padding(&pad);
	return (pad.llen + pad.mlen + pad.rlen);
}
