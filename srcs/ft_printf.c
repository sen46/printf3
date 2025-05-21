/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 23:01:07 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/02 09:43:22 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		printed_chars;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	printed_chars = run(&ap, fmt);
	va_end(ap);
	return (printed_chars);
}
