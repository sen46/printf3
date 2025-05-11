/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_u_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:34:58 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/09 22:39:16 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

/*
int	minus_u(va_list *ap, t_len *len)
{
	unsigned int	val;
	char			*val_str;
	int				val_len;
	char			*res;

	val = va_arg(*ap, unsigned int);
	if (val == 0 && len->width == 0)
		return (0);
	val_str = ft_itoa(val);
	val_len = ft_strlen(val_str);
	len->width = ft_max(len->width, ft_max(len->precision, val_len));
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	if (len->precision > val_len)
	{
		ft_memset(res, '0', len->precision);
		ft_strncpy(&res[len->precision - val_len], val_str, val_len);
	}
	else
		ft_strncpy(res, val_str, val_len);
	write(1, res, len->width);
	free(res);
	free(val_str);
	return (len->width);
}
*/

static int	minus_u_dot(va_list *ap, t_len *len)
{
	unsigned int		val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, unsigned int);
	if (len->width == 0 && len->precision == 0 && val == 0)
		return (0);
	val_str = ft_itoa(val);
	val_len = ft_strlen(val_str);
	// 出力の幅は精度、幅、数の長さの最大値
	len->width = ft_max(len->width, ft_max(len->precision, val_len));
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	if (val == 0 && len->precision == 0)
	{
		write(1, res, len->width);
	}
	else
	{
		if (len->precision > val_len)
		{
			ft_memset(res, '0', len->precision);
			ft_strncpy(&res[len->precision - val_len], val_str, val_len);
		}
		else
			ft_strncpy(res, val_str, val_len);
		write(1, res, len->width);
	}
	free(res);
	free(val_str);
	return (len->width);
}

static int	minus_u_nodot(va_list *ap, t_len *len)
{
	unsigned int		val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, unsigned int);
	val_str = ft_itoa(val);
	val_len = ft_strlen(val_str);
	len->width = ft_max(len->width, ft_max(len->precision, val_len));
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	ft_strncpy(res, val_str, val_len);
	// ft_strncpy(res + len->width - val_len, val_str, val_len);
	write(1, res, len->width);
	free(res);
	free(val_str);
	return (len->width);
}

int	minus_u(va_list *ap, t_len *len)
{
	int	rtn;

	if (len->dot)
	{
		rtn = minus_u_dot(ap, len);
	}
	else
	{
		rtn = minus_u_nodot(ap, len);
	}
	return (rtn);
}
