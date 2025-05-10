/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_lowerx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:45:23 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 15:23:51 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int	zero_lowerx(va_list *ap, t_len len)
{
	unsigned int	val;
	int				val_len;
	char			*res;
	char			*val_str;

	val = va_arg(*ap, unsigned int);
	val_str = ft_itoa_base(val, "0123456789abcdef");
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
	write(1, res, len.width);
	free(res);
	free(val_str);
	return (len.width);
}

