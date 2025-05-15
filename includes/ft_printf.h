/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:06:59 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/12 20:16:33 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "../srcs/libft/libft.h"

typedef struct s_len
{
	int	width;
	int	precision;
	int	dot;
	int	hash;
	int	minus;
	int	plus;
	int	blank;
	int	zero;
}	t_len;

// base function
int		ft_printf(const char *arg1, ...);
int		run(va_list *ap, const char *arg1);
int		is_specifier(char c);
void	spec_judge(char c, va_list *ap, int *cnt);
int		process_c(va_list *ap);
int		process_s(va_list *ap);
int		process_d(va_list *ap);
int		process_i(va_list *ap);
int		process_u(va_list *ap);
int		process_lowerx(va_list *ap);
int		process_upperx(va_list *ap);
int		process_ptr(va_list *ap);
int		process_per(void);

// utils
void	ft_strncpy(char *dest, const char *str, int len);
void	spec_judge_with_flag(char flag, char spec, va_list *ap, int *printed_chars, t_len len);
int		set_len_info(t_len *len, const char *fmt, int i);

// flag handler
void	minus(const char *fmt, int *printed_chars, va_list *ap, int *idx);
void	plus(const char *fmt, int *printed_chars, va_list *ap, int *idx);
void	hash(const char *fmt, int *printed_chars, va_list *ap, int *idx);
void	zero(const char *fmt, int *printed_chars, va_list *ap, int *idx);
void	blank(const char *fmt, int *printed_chars, va_list *ap, int *idx);
void	width(const char *fmt, int *printed_chars, va_list *ap, int *idx);

// minus
void	spec_judge_minus(char c, va_list *ap, int *cnt, t_len *len);
int		minus_c(va_list *ap, t_len len);
int		minus_s(va_list *ap, t_len *len);
int		minus_di(va_list *ap, t_len *len);
int		minus_u(va_list *ap, t_len *len);
int		minus_ptr(va_list *ap, t_len *len);
int		minus_lowerx(va_list *ap, t_len *len);
int		minus_upperx(va_list *ap, t_len *len);

// plus
void	spec_judge_plus(char c, va_list *ap, int *cnt, t_len len);
int		plus_di(va_list *ap, t_len len);

// blank
void	spec_judge_blank(char c, va_list *ap, int *cnt, t_len len);
int		blank_di(va_list *ap, t_len len);

// hash
void	spec_judge_hash(char c, va_list *ap, int *cnt, t_len len);
int		hash_lowerx(va_list *ap, t_len len);
int		hash_upperx(va_list *ap, t_len len);

// zero
void	spec_judge_zero(char c, va_list *ap, int *cnt, t_len *len);
int		zero_di(va_list *ap, t_len *len);
int		zero_u(va_list *ap, t_len *len);
int		zero_upperx(va_list *ap, t_len *len);
int		zero_lowerx(va_list *ap, t_len *len);

// dot
void	spec_judge_dot(char c, va_list *ap, int *cnt, t_len len);
int		dot_di(va_list *ap, t_len len);
int		dot_u(va_list *ap, t_len len);
int		dot_s(va_list *ap, t_len len);
int		dot_upperx(va_list *ap, t_len len);
int		dot_lowerx(va_list *ap, t_len len);

// width
void	spec_judge_width(char c, va_list *ap, int *cnt, t_len *len);
int		width_s(va_list *ap, t_len *len);
int		width_c(va_list *ap, t_len *len);
int		width_ptr(va_list *ap, t_len *len);
int		width_di(va_list *ap, t_len *len);
int		width_u(va_list *ap, t_len *len);
int		width_upperx(va_list *ap, t_len *len);
int		width_lowerx(va_list *ap, t_len *len);

#endif
