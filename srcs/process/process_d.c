/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:25:36 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/02 09:33:32 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	process_d(va_list *ap)
{
	int		len;
	int		val;
	char	*str;

	val = va_arg(*ap, int);
	str = ft_itoa(val);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
