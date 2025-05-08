/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:56:32 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/05 22:38:32 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void	sub_process(char **res, char *val_str, int len)
{
	int	i;
	int	j;
	int	val_len;

	val_len = ft_strlen(val_str);
	i = len - val_len;
	j = 0;
	while (i < len && val_str[j])
		(*res)[i++] = val_str[j++];
}

int	process_s_width(va_list *ap, int len)
{
	char	*str;
	char	*res;

	str = va_arg(*ap, char *);
	if ((int)ft_strlen(str) > len)
		len = ft_strlen(str);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (free(str), -1);
	ft_memset(res, ' ', len);
	sub_process(&res, str, len);
	ft_putstr_fd(res, 1);
	free(res);
	return (len);
}
