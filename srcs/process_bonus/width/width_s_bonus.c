/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:56:11 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/09 22:37:11 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

/*
int	width_s(va_list *ap, t_len len)
{
	int		str_len;
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
	str_len = ft_strlen(str);
	if (len.precision == 0)
	{
		len.precision = str_len;
	}
	len.precision = ft_min(len.precision, str_len);
	len.width = ft_max(len.precision, len.width);
	res = ft_calloc(len.width + 1, sizeof(char));
	ft_memset(res, ' ', len.width);
	ft_strncpy((res + len.width - len.precision), str, len.precision);
	write(1, res, len.width);
	free(res);
	if (flag)
		free(str);
	return (len.width);
}
*/


/*
static int	width_s_dot(va_list *ap, t_len len)
{
	char	*str;
	int		str_len;
	char	*res;
	int		flag;

	str = va_arg(*ap, char *);
	flag = 0;
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		flag = 1;
	}
	str_len = ft_strlen(str);
	// 出力の幅は精度、幅、数の長さの最大値
	len.precision = ft_min(len.precision, str_len);
	len.width = ft_max(len.precision, len.width);
	res = ft_calloc(len.width + 1, sizeof(char));
	ft_memset(res, ' ', len.width);
	ft_strncpy(res + len.width - len.precision, str, str_len);
	write(1, res, len.precision);
	free(res);
	if (flag)
		free(str);
	return (len.width);
}
*/
int	width_s_dot(va_list *ap, t_len *len)
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
	len->precision = ft_min(len->precision, ft_strlen(str));
	len->width = ft_max(len->precision, len->width);
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	ft_strncpy(res + len->width - len->precision, str, len->precision);
	if (flag && len->precision >= 6)
		write(1, res, len->width);
	else if (flag == 0)
		write(1, res, len->width);
	else
		len->width = 0;
	free(res);
	if (flag)
		free(str);
	return (len->width);
}

static int	width_s_nodot(va_list *ap, t_len *len)
{
	char *str;
	int		str_len;
	char	*res;
	int		flag;

	str = va_arg(*ap, char *);
	flag = 0;
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		flag = 1;
	}
	str_len = ft_strlen(str);
	len->precision = ft_max(len->precision, str_len);
	len->width = ft_max(len->width, len->precision);
	res = ft_calloc(len->width + 1, sizeof(char));
	ft_memset(res, ' ', len->width);
	ft_strncpy(res + len->width - len->precision, str, len->precision);
	write(1, res, len->width);
	free(res);
	if (flag)
		free(str);
	return (len->width);
}

int	width_s(va_list *ap, t_len *len)
{
	int	rtn;

	if (len->dot)
		rtn = width_s_dot(ap, len);
	else
		rtn = width_s_nodot(ap, len);
	return (rtn);
}
