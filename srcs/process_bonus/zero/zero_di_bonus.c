/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_di_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:45:23 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 15:47:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	check(char *str, t_len len)
{
	int	i;
	int	sign;

	i = len.width - 1;
	sign = 0;
	while (i > 0)
	{
		if(str[i] == '-')
		{
			str[i] = '0';
			sign = 1;
			break;
		}
		i--;
	}
	while (i >= 0 && str[i] == '0')
		i--;
	if (sign)
		str[i+1] = '-';
}

/*
int	zero_di(va_list *ap, t_len len)
{
	int		val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, int);
	val_str = ft_itoa(val);
	val_len = ft_strlen(val_str);
	len.width = ft_max(len.width, ft_max(len.precision, val_len));
	res = ft_calloc(len.width + 1, sizeof(char));
	ft_memset(res, ' ', len.width);
	if (len.precision > val_len)
	{
		ft_memset(res, '0', len.precision);
		ft_strncpy(&res[len.precision - val_len], val_str, val_len);
	}
	else
		ft_strncpy(res, val_str, val_len);
	check(res, len.width);
	write(1, res, len.width);
	free(res);
	free(val_str);
	return (len.width);
}
*/

static int	zero_di_dot(va_list *ap, t_len *len)
{
	int		val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, int);
	if (len->width == 0 && len->precision == 0 && val == 0)
		return (0);
	val_str = ft_itoa(val);
	val_len = ft_strlen(val_str);
	// 出力の幅は精度、幅、数の長さの最大値
	if (val < 0)
	{
		// val_len++;
		len->precision++;
	}
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
			ft_memset(&res[len->width - len->precision], '0', len->precision);
			ft_strncpy(&res[len->width - val_len], val_str, val_len);
		}
		else
			ft_strncpy(&res[len->width - val_len], val_str, val_len);
		check(res, *len);
		write(1, res, len->width);
	}
	free(res);
	free(val_str);
	return (len->width);
}

static int	zero_di_nodot(va_list *ap, t_len *len)
{
	int		val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, int);
	val_str = ft_itoa(val);
	val_len = ft_strlen(val_str);
	len->width = ft_max(len->width, ft_max(len->precision, val_len));
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, '0', len->width);
	ft_strncpy(res + len->width - val_len, val_str, val_len);
	check(res, *len);
	write(1, res, len->width);
	free(res);
	free(val_str);
	return (len->width);
}

int	zero_di(va_list *ap, t_len *len)
{
	int	rtn;

	if (len->dot)
	{
		rtn = zero_di_dot(ap, len);
	}
	else
	{
		rtn = zero_di_nodot(ap, len);
	}
	return (rtn);
}
