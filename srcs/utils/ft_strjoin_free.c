/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:33:07 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/17 15:35:50 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_strjoin_free(char *dest, char *src)
{
	char	*res;

	res = ft_strjoin(dest, src);
	free(src);
	return (res);
}
