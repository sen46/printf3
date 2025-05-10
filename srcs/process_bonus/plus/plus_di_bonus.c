/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_di_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:44:09 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 13:27:59 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static char	*ft_itoa_sign(long n)
{
	long	num;
	int		len;
	char	*res;
	int		idx;

	num = n;
	len = ft_nbrlen_dec(num);
	if (num >= 0)
		len++;
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	else
		res[0] = '+';
	if (num == 0)
		res[1] = '0';
	idx = len - 1;
	while (num > 0)
	{
		res[idx--] = '0' + (num % 10);
		num /= 10;
	}
	return (res);
}

int	plus_di(va_list *ap, t_len len)
{
	int		val;
	int		val_len;
	char	*res;
	char	*val_str;

	val = va_arg(*ap, int);
	val_str = ft_itoa_sign(val);
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
