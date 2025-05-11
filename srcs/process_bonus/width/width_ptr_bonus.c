/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:46:28 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 17:24:50 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int	width_ptr(va_list *ap, t_len *len)
{
	void	*val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, void *);
	// if (val == NULL)
	// {
		// write(1, "(nil)", 5);
		// return (5);
	// }
	val_str = ft_itoa_base((unsigned long)val, "0123456789abcdef");
	val_len = ft_strlen(val_str);
	if (len->precision == 0)
		len->precision = ft_strlen(val_str);
	len->precision = ft_min(len->precision, ft_strlen(val_str));
	len->width = ft_max(len->precision, len->width - 2);
	len->width += 2;
	// printf("=%d= ", len->width);
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	if (val == NULL)
	{
		free(res);
		len->width = ft_max(5, len->width);
		res = ft_calloc(len->width + 1, sizeof(char));
		ft_memset(res, ' ', len->width);
		ft_strncpy(&res[len->width - 5], "(nil)", 5);
	}
	else if (len->precision > val_len)
	{
		ft_memset(res, '0', len->precision);
		ft_strncpy(&res[len->precision - val_len], val_str, val_len);
		ft_strncpy(&res[len->precision - val_len - 2], "0x", 2);
	}
	else
	{
		ft_strncpy(&res[len->width - val_len - 2], "0x", 2);
		ft_strncpy(&res[len->width - val_len], val_str, val_len);
	}
	write(1, res, len->width);
	free(res);
	free(val_str);
	return (len->width);
}

/*
static int	width_ptr_dot(va_list *ap, t_len len)
{
	unsigned long		val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, unsigned long);
	val_str = ft_itoa_base(val, "0123456789abcdef");
	val_len = ft_strlen(val_str);
	// 出力の幅は精度、幅、数の長さの最大値
	len->width = ft_max(len->width, ft_max(len->precision, val_len));
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	if (val == 0 && len->precision == 0)
	{
		write(1, res, len->precision);
		len->width = 0;
	}
	else
	{
		if (len->precision > val_len)
		{
			ft_memset(res + len->width - len->precision, '0', len->precision);
			ft_strncpy(&res[len->precision - val_len], val_str, val_len);
		}
		else
			ft_strncpy(res + len->width - val_len, val_str, val_len);
		write(1, res, len->width);
	}
	free(res);
	free(val_str);
	return (len->width);
}

static int	width_ptr_nodot(va_list *ap, t_len len)
{
	unsigned long		val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, unsigned long);
	val_str = ft_itoa_base(val, "0123456789abcdef");
	val_len = ft_strlen(val_str);
	len->width = ft_max(len->width, ft_max(len->precision, val_len));
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	ft_strncpy(res + len->width - val_len, val_str, val_len);
	write(1, res, len->width);
	free(res);
	free(val_str);
	return (len->width);
}



int	width_ptr(va_list *ap, t_len len)
{
	int	rtn;

	if (len->dot != 0)
	{
		rtn = width_ptr_nodot(ap, len);
	}
	else
	{
		rtn = width_ptr_dot(ap, len);
	}
	return (rtn);
}
*/
