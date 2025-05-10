/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_c_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:56:11 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/09 22:37:19 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int	minus_c(va_list *ap, t_len len)
{
	
	unsigned char	c;
	char	*res;

	c = (unsigned char)va_arg(*ap, int);
	res = ft_calloc(len.width + 1, sizeof(char));
	ft_memset(res, ' ', len.width);
	res[0] = c;
	write(1, res, len.width);
	free(res);
	return (len.width);
}
