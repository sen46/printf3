/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec2_judge_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:09:54 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/12 20:09:58 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	spec_judge_plus(char c, va_list *ap, int *cnt, t_len len)
{
	if (c == 'd' || c == 'i')
		*cnt += plus_di(ap, len);
}

void	spec_judge_blank(char c, va_list *ap, int *cnt, t_len len)
{
	if (c == 'd' || c == 'i')
		*cnt += blank_di(ap, len);
	else if (c == 's')
		*cnt += minus_s(ap, &len);
}

void	spec_judge_hash(char c, va_list *ap, int *cnt, t_len len)
{
	if (c == 'x')
		*cnt += hash_lowerx(ap, len);
	else if (c == 'X')
		*cnt += hash_upperx(ap, len);
}
