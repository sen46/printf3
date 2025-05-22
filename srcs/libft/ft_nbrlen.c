/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:06:07 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/02 08:33:32 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen_dec(long nbr);
int	ft_nbrlen_hex(unsigned long nbr);

int	ft_nbrlen_dec(long nbr)
{
	int	cnt;

	cnt = 1;
	if (nbr < 0)
	{
		cnt++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		cnt++;
		nbr /= 10;
	}
	return (cnt);
}

int	ft_nbrlen_hex(unsigned long nbr)
{
	int	cnt;

	cnt = 1;
	while (nbr >= 16)
	{
		cnt++;
		nbr /= 16;
	}
	return (cnt);
}

int	ft_nbrlen_oct(unsigned long nbr)
{
	int	cnt;

	cnt = 1;
	while (nbr >= 8)
	{
		cnt++;
		nbr /= 8;
	}
	return (cnt);
}
