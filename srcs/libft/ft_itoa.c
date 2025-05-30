/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:30:37 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 12:07:46 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long n)
{
	long	num;
	int		len;
	char	*res;
	int		idx;

	num = n;
	len = ft_nbrlen_dec(num);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	if (num == 0)
		res[0] = '0';
	idx = len - 1;
	while (num > 0)
	{
		res[idx--] = '0' + (num % 10);
		num /= 10;
	}
	return (res);
}

char	*ft_itoa_base(unsigned long num, char *base)
{
	int		len;
	char	*res;
	int		idx;
	int		base_len;

	base_len = ft_strlen(base);
	if (base_len == 16)
		len = ft_nbrlen_hex(num);
	else if (base_len == 8)
		len = ft_nbrlen_oct(num);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (num == 0)
		res[0] = '0';
	idx = len - 1;
	while (num > 0)
	{
		res[idx--] = base[num % base_len];
		num /= base_len;
	}
	return (res);
}
