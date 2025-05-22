/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:28:31 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/22 15:29:20 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_flag(const char c, t_flag *flag)
{
	int	rtn;

	rtn = 1;
	if (c == '-')
		flag->minus = 1;
	else if (c == ' ')
		flag->blank = 1;
	else if (c == '+')
		flag->plus = 1;
	else if (c == '#')
		flag->hash = 1;
	else if (c == '0')
		flag->zero = 1;
	else
		rtn = 0;
	return (rtn);
}
