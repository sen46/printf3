/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 22:28:27 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/23 22:43:16 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_process.h"

void	output_padding_nil(t_padding *pad)
{
	pad->llen = ft_strlen(pad->left);
	pad->mlen = ft_strlen(pad->middle);
	pad->rlen = ft_strlen(pad->right);
	write(1, pad->left, pad->llen);
	write(1, pad->middle, pad->mlen);
	write(1, pad->right, pad->rlen);
}

static void	output_padding_nil_sub(t_flag *flag, t_padding *pad)
{
	char	*tmp;

	if (flag->blank || flag->plus)
	{
		if (flag->minus)
			tmp = ft_strnstr(pad->left, "000", pad->llen);
		else
			tmp = ft_strnstr(pad->right, "000", pad->rlen);
		if (flag->plus)
			*(tmp) = '+';
		else if (flag->blank)
			*(tmp) = ' ';
		*(tmp + 2) = 'x';
	}
	else
	{
		if (flag->minus)
			tmp = ft_strnstr(pad->left, "00", pad->llen);
		else
			tmp = ft_strnstr(pad->right, "00", pad->rlen);
		*(tmp + 1) = 'x';
	}
}

void	output_padding(t_flag *flag, t_padding *pad)
{
	if (!flag->minus)
		pad->right = ft_strjoin_free(pad->left, pad->right);
	pad->llen = ft_strlen(pad->left);
	pad->mlen = ft_strlen(pad->middle);
	pad->rlen = ft_strlen(pad->right);
	output_padding_nil_sub(flag, pad);
	if (flag->minus)
	{
		write(1, pad->left, pad->llen);
		write(1, pad->middle, pad->mlen);
		write(1, pad->right, pad->rlen);
	}
	else
	{
		pad->llen = 0;
		write(1, pad->right, pad->rlen);
		write(1, pad->middle, pad->mlen);
	}
}
