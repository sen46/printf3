/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:46:28 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 09:48:56 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	fill_res_ptr(char *res, char *val_str, int val_len, t_len *len)
{
	if (len->precision > val_len)
	{
		ft_memset(res, '0', len->precision);
		ft_strncpy(&res[len->precision - val_len], val_str, val_len);
	}
	else
		ft_strncpy(res, val_str, val_len);
}

int	minus_ptr(va_list *ap, t_len *len)
{
	void	*val;
	char	*val_str;
	char	*res;
	int		val_len;

	val = va_arg(*ap, void *);
	if (val == NULL)
		return (write(1, "(nil)", 5), 5);
	val_str = ft_itoa_base((unsigned long)val, "0123456789abcdef");
	val_len = ft_strlen(val_str);
	if (len->precision == 0)
		len->precision = val_len;
	len->precision = ft_min(len->precision, val_len);
	len->width = ft_max(len->precision, len->width - 2);
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	fill_res_ptr(res, val_str, val_len, len);
	write(1, "0x", 2);
	write(1, res, len->width);
	free(res);
	free(val_str);
	return (len->width + 2);
}
