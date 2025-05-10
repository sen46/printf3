/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:36:41 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 09:48:24 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	process_ptr(va_list *ap)
{
	void	*ptr;
	int		len;
	char	*str;

	ptr = va_arg(*ap, void *);
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	str = ft_itoa_base((unsigned long)ptr, "0123456789abcdef");
	ft_putstr_fd(str, 1);
	len = 2 + ft_strlen(str);
	free(str);
	return (len);
}
