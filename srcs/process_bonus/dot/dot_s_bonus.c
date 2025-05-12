/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_s_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:56:11 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 16:23:29 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static char	*handle_null_string(int *need_free)
{
	*need_free = 1;
	return (ft_strdup("(null)"));
}

static void	write_result(char *res, int width, int precision, char *str)
{
	if (str == NULL && precision < 6)
		width = 0;
	write(1, res, width);
}

int	dot_s(va_list *ap, t_len len)
{
	char	*str;
	int		need_free;
	int		str_len;
	char	*res;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = handle_null_string(&need_free);
	else
		need_free = 0;
	str_len = ft_strlen(str);
	len.precision = ft_min(len.precision, str_len);
	len.width = ft_max(len.precision, len.width);
	res = ft_calloc(len.width + 1, sizeof(char));
	ft_memset(res, ' ', len.width);
	ft_strncpy(res, str, len.precision);
	write_result(res, len.width, len.precision, str);
	if (need_free)
		free(str);
	free(res);
	return (len.width);
}
