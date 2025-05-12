/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_u_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:34:58 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 17:28:46 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	width_u_dot_sub(char *res, char *val_str, t_len *len, int val)
{
	int	val_len;

	val_len = ft_strlen(val_str);
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
}

static int	width_u_dot(va_list *ap, t_len *len)
{
	unsigned int	val;
	int				val_len;
	char			*res;
	char			*val_str;

	val = va_arg(*ap, unsigned int);
	val_str = ft_itoa(val);
	val_len = ft_strlen(val_str);
	len->width = ft_max(len->width, ft_max(len->precision, val_len));
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	width_u_dot_sub(res, val_str, len, val);
	free(res);
	free(val_str);
	return (len->width);
}

static int	width_u_nodot(va_list *ap, t_len *len)
{
	unsigned int	val;
	int				val_len;
	char			*res;
	char			*val_str;

	val = va_arg(*ap, unsigned int);
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

int	width_u(va_list *ap, t_len *len)
{
	int	rtn;

	if (len->dot)
		rtn = width_u_dot(ap, len);
	else
		rtn = width_u_nodot(ap, len);
	return (rtn);
}
