/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:10:32 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/02 09:34:07 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	process_s(va_list *ap)
{
	int		len;
	char	*str;

	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		len = 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	return (len);
}
