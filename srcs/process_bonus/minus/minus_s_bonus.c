/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:12:36 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/07 22:31:57 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

int	process_s_minus(va_list *ap, int len)
{
	size_t	i;
	char	*res;
	char	*str;

	str = va_arg(*ap, char *);
	if (len < (int)ft_strlen(str))
		len = ft_strlen(str);
	res = ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (-1);
	ft_memset(res, ' ', len);
	i = 0;
	while (i < ft_strlen(str))
	{
		res[i] = str[i];
		i++;
	}
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}
