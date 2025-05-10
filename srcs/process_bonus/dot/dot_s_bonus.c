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

int	dot_s(va_list *ap, t_len len)
{
	int		flag;
	char	*str;
	char	*res;

	str = va_arg(*ap, char *);
	flag = 0;
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		flag = 1;
	}
	len.precision = ft_min(len.precision, ft_strlen(str));
	len.width = ft_max(len.precision, len.width);
	res = ft_calloc(len.width + 1, sizeof(char));
	ft_memset(res, ' ', len.width);
	// printf("\nstr=%s=\n", str);
	ft_strncpy(res, str, len.precision);
	//printf("\nstr=%s=\n", res);
	
	if (flag && len.precision >= 6)
		write(1, res, len.width);
	else if (flag == 0)
		write(1, res, len.width);
	else
		len.width = 0;
	free(res);
	if (flag)
		free(str);
	return (len.width);
}


