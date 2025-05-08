/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:26:12 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/02 09:35:30 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	process_u(va_list *ap)
{
	int				len;
	char			*str;
	unsigned int	val;

	val = va_arg(*ap, unsigned int);
	str = ft_itoa(val);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
