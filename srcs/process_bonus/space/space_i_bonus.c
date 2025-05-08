/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_i_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:56:32 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/05 21:36:00 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	sub_process(char **res, char *val_str, int len, int is_negative)
{
	int	i;
	int	j;
	int	val_len;

	val_len = ft_strlen(val_str);
	i = len - val_len;
	if (is_negative)
		(*res)[i - 1] = '-';
	j = 0;
	while (i < len && val_str[j])
		(*res)[i++] = val_str[j++];
}

int	process_i_width(va_list *ap, int len)
{
	long	val;
	char	*val_str;
	char	*res;
	int		is_negative;

	val = va_arg(*ap, int);
	printf("ok");
	is_negative = (val < 0);
	if (is_negative)
		val = -val;
	val_str = ft_itoa(val);
	if (!val_str)
		return (-1);
	if ((int)ft_strlen(val_str) + is_negative > len)
		len = ft_strlen(val_str) + is_negative;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (free(val_str), -1);
	ft_memset(res, ' ', len);
	sub_process(&res, val_str, len, is_negative);
	ft_putstr_fd(res, 1);
	free(val_str);
	free(res);
	return (len);
}
