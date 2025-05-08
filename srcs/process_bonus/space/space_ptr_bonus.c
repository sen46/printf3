/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:10:00 by assistant         #+#    #+#             */
/*   Updated: 2025/05/06 19:58:53 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static char *create_ptr_str(void *val)
{
    char    *hex;
    char    *ptr_str;

    if (val == NULL)
        return (ft_strdup("(nil)"));
    hex = ft_itoa_base((unsigned long)val, "0123456789abcdef");
    if (!hex)
        return (NULL);
    ptr_str = ft_strjoin("0x", hex);
    free(hex);
    return (ptr_str);
}

static char *pad_left(const char *str, int len)
{
    int     str_len;
    int     pad_start;
    int     i;
    char    *res;

    str_len = ft_strlen(str);
    if (len < str_len)
        len = str_len;
    res = ft_calloc(len + 1, sizeof(char));
    if (!res)
        return (NULL);
    ft_memset(res, ' ', len);
    pad_start = len - str_len;
    i = 0;
    while (i < str_len)
    {
        res[pad_start + i] = str[i];
        i++;
    }
    return (res);
}

int process_ptr_width(va_list *ap, int width)
{
    void    *val;
    char    *ptr_str;
    char    *output;
    int     out_len;

    val = va_arg(*ap, void *);
    ptr_str = create_ptr_str(val);
    if (!ptr_str)
        return (-1);
    output = pad_left(ptr_str, width);
    free(ptr_str);
    if (!output)
        return (-1);
    out_len = ft_strlen(output);
    ft_putstr_fd(output, 1);
    free(output);
    return (out_len);
}

