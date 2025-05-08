/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_c_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:51:58 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/07 22:11:46 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int	process_c_minus(va_list *ap, int len)
{
	char	c;
	char	*res;

	c = (char)va_arg(*ap, int);
	write(1, &c, 1);
	res = ft_calloc(len, sizeof(char));
	ft_memset(res, ' ', len - 1);
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}
