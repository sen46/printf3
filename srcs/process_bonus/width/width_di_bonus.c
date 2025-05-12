/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_di_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:45:23 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 17:27:29 by ssawa            ###   ########.fr       */
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

static void	width_di_dot_sub(char *res, t_len *len, char *val_str, int val_len)
{
	if (len->precision > val_len)
	{
		ft_memset(res + len->width - len->precision, '0', len->precision);
		ft_strncpy(&res[len->precision - val_len], val_str, val_len);
	}
	else
		ft_strncpy(res + len->width - val_len, val_str, val_len);
	check(res, len->precision);
	write(1, res, len->width);
}

static int	width_di_dot(va_list *ap, t_len *len)
{
	int		val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, int);
	val_str = ft_itoa(val);
	val_len = ft_strlen(val_str);
	if (val < 0)
		len->precision++;
	len->width = ft_max(len->width, ft_max(len->precision, val_len));
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	if (val == 0 && len->precision == 0)
	{
		write(1, res, len->precision);
		len->width = 0;
	}
	else
		width_di_dot_sub(res, len, val_str, val_len);
	free(res);
	free(val_str);
	return (len->width);
}

static int	width_di_nodot(va_list *ap, t_len *len)
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
	ft_strncpy(res + len->width - val_len, val_str, val_len);
	write(1, res, len->width);
	free(res);
	free(val_str);
	return (len->width);
}

int	width_di(va_list *ap, t_len *len)
{
	int	rtn;

	if (len->dot)
		rtn = width_di_dot(ap, len);
	else
		rtn = width_di_nodot(ap, len);
	return (rtn);
}
