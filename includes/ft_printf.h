/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:06:59 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/07 22:17:22 by ssawa            ###   ########.fr       */
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

// 基本的な処理
int		is_specifier(char c);
void	is_ox(va_list *ap, char c, int *cnt);
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
int		process_upperx_sharp(va_list *ap);
int		process_lowerx_sharp(va_list *ap);
int		process_o_sharp(va_list *ap);
int	process_d_flag0(va_list *ap, int len);
int	process_i_flag0(va_list *ap, int len);
int	process_u_flag0(va_list *ap, int len);
int	process_upperx_flag0(va_list *ap, int len);
int	process_lowerx_flag0(va_list *ap, int len);
int	process_s_flag0(va_list *ap, int len);

int	process_c_width(va_list *ap, int len);
int	process_s_width(va_list *ap, int len);
int	process_ptr_width(va_list *ap, int len);
int	process_d_width(va_list *ap, int len);
int	process_i_width(va_list *ap, int len);
int	process_u_width(va_list *ap, int len);
int	process_upperx_width(va_list *ap, int len);
int	process_lowerx_width(va_list *ap, int len);

int	process_c_minus(va_list *ap, int len);
int	process_s_minus(va_list *ap, int len);

void	spec_judge_zero(char c, va_list *ap, int *cnt, int len);
void	spec_judge_width(char c, va_list *ap, int *cnt, int len);
void	spec_judge_minus(char c, va_list *ap, int *cnt, int len);
void	is_ox(va_list *ap, char c, int *cnt);

#endif
