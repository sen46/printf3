/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:16:39 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/04 22:17:52 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int	process_o_sharp(va_list *ap)
{
	int				len;
	char			*str;
	unsigned int	val;

	val = va_arg(*ap, unsigned int);
	str = ft_itoa_base(val, "01234567");
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
