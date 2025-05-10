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

int	minus_s(va_list *ap, t_len len)
{
	char	*str;
	char	*res;

	str = va_arg(*ap, char *);
	if (len.precision == 0)
		len.precision = ft_strlen(str);
	len.precision = ft_min(len.precision, ft_strlen(str));
	len.width = ft_max(len.precision, len.width);
	res = ft_calloc(len.width + 1, sizeof(char));
	ft_memset(res, ' ', len.width);
	// printf("\nstr=%s=\n", str);
	ft_strncpy(res, str, len.precision);
	//printf("\nstr=%s=\n", res);
	write(1, res, len.width);
	free(res);
	return (len.width);
}

