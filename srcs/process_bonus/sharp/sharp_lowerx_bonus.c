/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lowerx_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:27:36 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/04 23:05:44 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int	process_lowerx_sharp(va_list *ap)
{
	int				len;
	char			*str;
	unsigned int	val;

	len = 0;
	val = va_arg(*ap, unsigned int);
	str = ft_itoa_base(val, "0123456789abcdef");
	if (val != 0)
	{
		len += 2;
		write(1, "0x", 2);
	}
	ft_putstr_fd(str, 1);
	len += ft_strlen(str);
	free(str);
	return (len);
}
