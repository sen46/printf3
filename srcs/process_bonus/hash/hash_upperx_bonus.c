/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_upperx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:44:32 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 14:03:18 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int	hash_upperx(va_list *ap, t_len len)
{
	unsigned int	val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, unsigned int);
	val_str = ft_itoa_base((unsigned long)val, "0123456789ABCDEF");
	val_len = ft_strlen(val_str);
	if (len.precision == 0)
		len.precision = ft_strlen(val_str);
	len.precision = ft_min(len.precision, ft_strlen(val_str));
	len.width = ft_max(len.precision, len.width - 2);
	res = ft_calloc(len.width + 1, sizeof(char));
	ft_memset(res, ' ', len.width);
	if (len.precision > val_len)
	{
		ft_memset(res, '0', len.precision);
		ft_strncpy(&res[len.precision - val_len], val_str, val_len);
	}
	else
		ft_strncpy(res, val_str, val_len);
	if (val != 0)
		write(1, "0X", 2);
	write(1, res, len.width);
	free(res);
	free(val_str);
	if (val != 0)
		return (len.width + 2);
	return (len.width);
}
