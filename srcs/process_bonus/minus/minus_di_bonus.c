/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_di_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:45:23 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/09 22:37:15 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	check(char *res, int len)
{
	int	i;
	int	flag;

	i = len - 1;
	flag = 0;
	while (i > 0)
	{
		if (res[i] == '-')
		{
			res[i] = '0';
			flag = 1;
		}
		i--;
	}
	if (flag)
		res[i] = '-';
}

static void	fill_res_di(char *res, char *val_str, int val, int precision)
{
	int	val_len;

	val_len = ft_strlen(val_str);
	if (precision > val_len)
	{
		ft_memset(res, '0', precision);
		ft_strncpy(&res[precision - val_len], val_str, val_len);
	}
	else
		ft_strncpy(res, val_str, val_len);
	if (val < 0)
		check(res, precision);
}

int	minus_di_dot(va_list *ap, t_len *len)
{
	int		val;
	char	*val_str;
	int		val_len;
	char	*res;

	val = va_arg(*ap, int);
	if (len->width == 0 && len->precision == 0 && val == 0)
		return (0);
	val_str = ft_itoa(val);
	val_len = ft_strlen(val_str);
	if (val < 0)
		len->precision++;
	len->width = ft_max(len->width, ft_max(len->precision, val_len));
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	if (val == 0 && len->precision == 0)
		write(1, res, len->width);
	else
	{
		fill_res_di(res, val_str, val, len->precision);
		write(1, res, len->width);
	}
	free(res);
	free(val_str);
	return (len->width);
}

static int	minus_di_nodot(va_list *ap, t_len *len)
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
	ft_memset(res, ' ', len->width);
	ft_strncpy(res, val_str, val_len);
	write(1, res, len->width);
	free(res);
	free(val_str);
	return (len->width);
}

int	minus_di(va_list *ap, t_len *len)
{
	int	rtn;

	if (len->dot)
		rtn = minus_di_dot(ap, len);
	else
		rtn = minus_di_nodot(ap, len);
	return (rtn);
}
