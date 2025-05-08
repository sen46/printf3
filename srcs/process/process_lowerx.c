/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lowerx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:27:36 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/04 23:03:07 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	process_lowerx(va_list *ap)
{
	int				len;
	char			*str;
	unsigned int	val;

	val = va_arg(*ap, unsigned int);
	str = ft_itoa_base(val, "0123456789abcdef");
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
