/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_lowerx_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:45:23 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 17:32:22 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	fill_zero(char *res, char *val_str, int val_len, t_len len)
{
	ft_memset(res + len.width - len.precision, '0', len.precision);
	ft_strncpy(&res[len.precision - val_len], val_str, val_len);
}

static void	format_value(char *res, char *val_str, int val_len, t_len *len)
{
	if (len->precision > val_len)
		fill_zero(res, val_str, val_len, *len);
	else
		ft_strncpy(res + len->width - val_len, val_str, val_len);
	write(1, res, len->width);
}

int	width_lowerx_dot(va_list *ap, t_len *len)
{
	unsigned int	val;
	char			*val_str;
	char			*res;
	int				val_len;

	val = va_arg(*ap, unsigned int);
	val_str = ft_itoa_base(val, "0123456789abcdef");
	val_len = ft_strlen(val_str);
	len->width = ft_max(len->width, ft_max(len->precision, val_len));
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	if (val == 0 && len->precision == 0)
	{
		write(1, res, len->precision);
		len->width = 0;
	}
	else
		format_value(res, val_str, val_len, len);
	free(res);
	free(val_str);
	return (len->width);
}

int	width_lowerx_nodot(va_list *ap, t_len *len)
{
	unsigned int	val;
	int				val_len;
	char			*val_str;
	char			*res;

	val = va_arg(*ap, unsigned int);
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

int	width_lowerx(va_list *ap, t_len *len)
{
	if (len->dot)
		return (width_lowerx_dot(ap, len));
	else
		return (width_lowerx_nodot(ap, len));
}
