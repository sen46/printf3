/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_s_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:26:04 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/06 20:26:07 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"
#include <string.h>

int process_s_flag0(va_list *ap, int len)
{
    char    *str;
    char    *dup;
    size_t  print_len;

    str = va_arg(*ap, char *);
    dup = NULL;
    if (str == NULL)
    {
        dup = ft_strdup("(null)");
        if (dup == NULL)
            return (-1);
        str = dup;
    }
    print_len = ft_strlen(str);
    if (len >= 0 && print_len > (size_t)len)
		print_len = len;
	if (!strcmp(str, "(null)") && print_len < 6)
		print_len = 0;
	else if (print_len > 0)
        write(1, str, print_len);
    if (dup)
        free(dup);
    return ((int)print_len);
}
