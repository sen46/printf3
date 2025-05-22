/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:06:59 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/22 17:50:15 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include "../srcs/libft/libft.h"

typedef struct s_flag
{
	int		width;
	int		precision;
	int		dot;
	int		hash;
	int		minus;
	int		plus;
	int		blank;
	int		zero;
	int		sign;
	char	spec;
}	t_flag;

typedef struct s_padding
{
	char	*left;
	int		llen;
	char	*middle;
	int		mlen;
	char	*right;
	int		rlen;
}	t_padding;

// base function
int		ft_printf(const char *arg1, ...);
int		main_process(va_list *ap, const char *arg1);
int		is_specifier(char c);
void	spec_judge(char c, va_list *ap, int *cnt);
int		process_c(va_list *ap);
int		process_s(va_list *ap);
int		process_d(va_list *ap);
int		process_i(va_list *ap);
int		process_u(va_list *ap);
int		process_o(va_list *ap);
int		process_lowerx(va_list *ap);
int		process_upperx(va_list *ap);
int		process_ptr(va_list *ap);
int		process_per(void);

// bonus
int		flag_check(const char *fmt, t_flag *flag);
void	spec_judge_flag(t_flag *flag, va_list *ap, int *cnt);
int		process_c_flag(t_flag *flag, va_list *ap);
int		process_s_flag(t_flag *flag, va_list *ap);
int		process_di_flag(t_flag *flag, va_list *ap);
int		process_lowerx_flag(t_flag *flag, va_list *ap);
int		process_upperx_flag(t_flag *flag, va_list *ap);
int		process_u_flag(t_flag *flag, va_list *ap);
int		process_o_flag(t_flag *flag, va_list *ap);
int		process_p_flag(t_flag *flag, va_list *ap);
int		process_per_flag(void);

// utils
char	*ft_strjoin_free(char *dest, char *src);
void	free_padding(t_padding *pad);
int		is_flag(const char c, t_flag *flag);

#endif
