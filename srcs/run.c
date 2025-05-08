/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assistant <assistant@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:30:00 by assistant         #+#    #+#             */
/*   Updated: 2025/05/07 22:09:40 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * Parse a positive integer from format string starting at fmt[*i].
 * Advances *i until non-digit.
 */
static int	parse_number(const char *fmt, int *i)
{
	int	n;

	n = 0;
	while (fmt[*i] >= '0' && fmt[*i] <= '9')
	{
		n = n * 10 + (fmt[*i] - '0');
		(*i)++;
	}
	return (n);
}

static void	handle_minus(const char *fmt, int *i, va_list *ap, int *cnt)
{
	int	len;
	// char	spec;

	while (fmt[*i] == '-')
		(*i)++;
	if (is_specifier(fmt[*i]))
		len = 1;
	else
		len = parse_number(fmt, i);
	// printf("len = %d", len);
	spec_judge_minus(fmt[*i], ap, cnt, len);
	(*i)++;
}
/**
 * Handle "#" flag: calls is_ox for specifier
 */
static void	handle_hash(const char *fmt, int *i, va_list *ap, int *cnt)
{
	char spec;

	(*i)++;
	spec = fmt[*i];
	if (is_specifier(spec))
	{
		is_ox(ap, spec, cnt);
		(*i)++;
	}
}

/**
 * Handle '0' or '.' prefix: calls spec_judge_zero with parsed width
 */
static void	handle_zero_dot(const char *fmt, int *i, va_list *ap, int *cnt)
{
	int	len;

	len = 0;
	while (fmt[++(*i)])
	{
		if (is_specifier(fmt[*i]))
		{
			spec_judge_zero(fmt[*i], ap, cnt, len);
			(*i)++;
			break;
		}
		len = len * 10 + (fmt[*i] - '0');
	}
}

/**
 * Handle width (numeric) prefix: calls spec_judge_space with parsed width
 */
static void	handle_width(const char *fmt, int *i, va_list *ap, int *cnt)
{
	int	len;

	len = parse_number(fmt, i);
	if (is_specifier(fmt[*i]))
	{
		spec_judge_width(fmt[*i], ap, cnt, len);
		(*i)++;
	}
}

// void	handle_space(const char *fmt, int *i, va_list *ap, int *cnt)
// {
	// while (fmt[*i] == ' ')
		// (*i)++;
	// spec_judge_space(fmt[*i], ap, cnt, jkkkkkkkkkkkkkk)
// }

/**
 * Main run loop: iterates format string and dispatches on '%'
 */
int		run(va_list *ap, const char *fmt)
{
	int	i;
	int cnt;

	i = 0;
	cnt = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (is_specifier(fmt[i]))
				spec_judge(fmt[i++], ap, &cnt);
			else if (fmt[i] == '-')
				handle_minus(fmt, &i, ap, &cnt);
			else if (fmt[i] == '#')
				handle_hash(fmt, &i, ap, &cnt);
			else if (fmt[i] == '0' || fmt[i] == '.')
				handle_zero_dot(fmt, &i, ap, &cnt);
			else if (fmt[i] >= '1' && fmt[i] <= '9')
				handle_width(fmt, &i, ap, &cnt);
			else if (fmt[i] == ' ');
				// handle_space(fmt, &i, ap, &cnt);
			else
				return (-1);
		}
		else
		{
			write(1, &fmt[i++], 1);
			cnt++;
		}
	}
	return (cnt);
}

