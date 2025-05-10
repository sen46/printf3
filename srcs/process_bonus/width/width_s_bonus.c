/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:56:11 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/09 22:37:11 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int	width_s(va_list *ap, t_len len)
{
	int		str_len;
	int		flag;
	char	*str;
	char	*res;
	

	str = va_arg(*ap, char *);
	flag = 0;
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		flag = 1;
	}
	str_len = ft_strlen(str);
	if (len.precision == 0)
	{
		len.precision = str_len;
	}
	len.precision = ft_min(len.precision, str_len);
	len.width = ft_max(len.precision, len.width);
	res = ft_calloc(len.width + 1, sizeof(char));
	ft_memset(res, ' ', len.width);
	ft_strncpy((res + len.width - len.precision), str, len.precision);
	write(1, res, len.width);
	free(res);
	if (flag)
		free(str);
	return (len.width);
}
