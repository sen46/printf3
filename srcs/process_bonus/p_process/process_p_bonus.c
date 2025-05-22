/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:37:24 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/22 18:57:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "../../../includes/ft_printf.h"

static void	run(char *str, int len, t_flag *flag)
{
	int	i;

	i = 0;
	while (i < len && str[i] == ' ')
		i++;
	if (flag->plus)
		str[i] = '+';
	else if (flag->blank)
		str[i] = ' ';
	str[i + 2] = 'x';
}

static void	output_padding(t_flag *flag, t_padding *pad, unsigned long val)
{
	pad->llen = ft_strlen(pad->left);
	pad->mlen = ft_strlen(pad->middle);
	pad->rlen = ft_strlen(pad->right);
	if (flag->minus)
	{
		if (flag->hash && val != 0)
			run(pad->left, pad->llen, flag);
		ft_putstr_fd(pad->left, 1);
		ft_putstr_fd(pad->middle, 1);
		ft_putstr_fd(pad->right, 1);
	}
	else
	{
		if (flag->hash && val != 0)
		{
		pad->right = ft_strjoin_free(pad->left, pad->right);
		run(pad->right, pad->llen + pad->rlen, flag);
		}
		// ft_putstr_fd(pad->left, 1);
		// ft_putstr_fd(pad->right, 1);
		write(1, pad->right, pad->llen + pad->rlen);
		ft_putstr_fd(pad->middle, 1);
	}
}

static void	process_p_flag_sub(t_flag *flag, t_padding *pad)
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
		ft_memset(pad->left, ' ', flag->width - flag->precision);
	}
}

int	process_p_flag(t_flag *flag, va_list *ap)
{
	void		*val;
	t_padding	pad;

	val = va_arg(*ap, void *);
	if (val != 0)
	{
		flag->hash = 1;
		pad.middle = ft_itoa_base((unsigned long)val, "0123456789abcdef");
	}
	else
	{
		pad.middle = ft_strdup("(nil)");
		flag->zero = 0;
	}
	flag->precision = ft_max(ft_strlen(pad.middle), flag->precision);
	if (flag->hash && val != 0)
		flag->precision += 2;
	if (flag->blank || flag->plus)
		flag->precision++;
	flag->width = ft_max(flag->width, flag->precision);
	process_p_flag_sub(flag, &pad);
	output_padding(flag, &pad, (unsigned long)val);
	free_padding(&pad);
	return (pad.llen + pad.mlen + pad.rlen);
}
*/


#include "../../../includes/ft_printf.h"



static void	add_prefix(char **str)
{
	char	*tmp = ft_strjoin("0x", *str);
	free(*str);
	*str = tmp;
}

static void	output_padding(t_flag *flag, t_padding *pad)
{
	if (flag->minus)
	{
		ft_putstr_fd(pad->middle, 1);
		write(1, pad->right, pad->rlen);
	}
	else
	{
		write(1, pad->left, pad->llen);
		ft_putstr_fd(pad->middle, 1);
	}
}

static void	process_p_flag_sub(t_flag *flag, t_padding *pad)
{
	size_t	mid_len = ft_strlen(pad->middle);

	if (flag->minus)
	{
		pad->right = ft_calloc(flag->width - mid_len + 1, 1);
		ft_memset(pad->right, ' ', flag->width - mid_len);
		pad->rlen = flag->width - mid_len;
		pad->llen = 0;
	}
	else
	{
		char c = (flag->zero) ? '0' : ' ';
		pad->left = ft_calloc(flag->width - mid_len + 1, 1);
		ft_memset(pad->left, c, flag->width - mid_len);
		pad->llen = flag->width - mid_len;
		pad->rlen = 0;
	}
}

int	process_p_flag(t_flag *flag, va_list *ap)
{
	void		*val;
	t_padding	pad;

	// 禁止フラグ強制オフ
	flag->plus = 0;
	flag->blank = 0;
	flag->hash = 0;

	val = va_arg(*ap, void *);
	if (val)
		pad.middle = ft_itoa_base((unsigned long)val, "0123456789abcdef");
	else
		pad.middle = ft_strdup("(nil)");

	if (val)
		add_prefix(&pad.middle);

	flag->width = ft_max(flag->width, (int)ft_strlen(pad.middle));
	process_p_flag_sub(flag, &pad);
	output_padding(flag, &pad);

	size_t ret = ft_strlen(pad.middle) + pad.llen + pad.rlen;
	free_padding(&pad);
	return (ret);
}

