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

int	minus_di(va_list *ap, t_len len)
{
	int		val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, int);
	// if (val == 0 && len.width == 0)
		// return (0);
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
	write(1, res, len.width);
	free(res);
	free(val_str);
	return (len.width);
}
