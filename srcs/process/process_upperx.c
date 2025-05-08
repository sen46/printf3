/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_upperx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:24:25 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/04 23:03:01 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	process_upperx(va_list *ap)
{
	int				len;
	unsigned int	val;
	char			*str;

	val = va_arg(*ap, unsigned int);
	str = ft_itoa_base(val, "0123456789ABCDEF");
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
