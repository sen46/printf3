/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_u_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:56:32 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/05 20:32:28 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	sub_process(char **res, char *val_str, int len)
{
	int	i;
	int	j;
	int	val_len;

	val_len = ft_strlen(val_str);
	i = len - val_len;
	j = 0;
	while (i < len && val_str[j])
		(*res)[i++] = val_str[j++];
}

int	process_u_flag0(va_list *ap, int len)
{
	unsigned int	val;
	char			*val_str;
	char			*res;

	val = va_arg(*ap, unsigned int);
	if (len == 0 && val == 0)
		return (0);
	val_str = ft_itoa(val);
	if (!val_str)
		return (-1);
	if ((int)ft_strlen(val_str) > len)
		len = ft_strlen(val_str);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (free(val_str), -1);
	ft_memset(res, '0', len);
	sub_process(&res, val_str, len);
	ft_putstr_fd(res, 1);
	free(val_str);
	free(res);
	return (len);
}

