/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:06:59 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/10 09:55:59 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "../srcs/libft/libft.h"
#include <stdio.h>

typedef struct s_len
{
	int	width;
	int	precision;
} t_len;

// 基本的な処理
int		is_specifier(char c);
void	spec_judge(char c, va_list *ap, int *cnt);
int		process_c(va_list *ap);
int		process_s(va_list *ap);
int		process_d(va_list *ap);
int		process_i(va_list *ap);
int		process_u(va_list *ap);
int		process_lowerx(va_list *ap);
int		process_upperx(va_list *ap);
int		process_u(va_list *ap);
int		process_ptr(va_list *ap);
int		process_per(void);
int		run(va_list *ap, const char *arg1);
int		ft_printf(const char *arg1, ...);

// bonus
// minus
void	spec_judge_minus(char c, va_list *ap, int *cnt, t_len len);
int	minus_c(va_list *ap, t_len len);
int	minus_s(va_list *ap, t_len len);
int	minus_di(va_list *ap, t_len len);
int	minus_lowerx(va_list *ap, t_len len);
int	minus_ptr(va_list *ap, t_len len);
int	minus_u(va_list *ap, t_len len);
int	minus_upperx(va_list *ap, t_len len);



// utils
void	ft_strncpy(char *dest, const char *str, int len);

#endif
