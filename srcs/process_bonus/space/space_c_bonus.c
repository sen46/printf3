/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_c_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:14:28 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/05 22:18:32 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int	process_c_width(va_list *ap, int len)
{
	char	*res;
	char	c;

	c = (char)va_arg(*ap, int);
	res = ft_calloc(len, sizeof(char));
	if (res == NULL)
		return (0);
	ft_memset(res, ' ', len - 1);
	ft_putstr_fd(res, 1);
	write(1, &c, 1);
	free(res);
	return (len);
}
