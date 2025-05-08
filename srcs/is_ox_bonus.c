/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_xd_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:07:08 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/04 23:10:06 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	is_ox(va_list *ap, char c, int *cnt)
{
	if (c == 'x')
	{
		*cnt += process_lowerx_sharp(ap);
	}
	else if (c == 'X')
	{
		*cnt += process_upperx_sharp(ap);
	}
	else if (c == 'o')
	{
		(*cnt)++;
		write(1, "0", 1);
		*cnt += process_o_sharp(ap);
	}
	else
	{
		*cnt = -1;
	}
}
