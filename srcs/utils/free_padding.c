/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:26:31 by ssawa             #+#    #+#             */
/*   Updated: 2025/05/18 20:27:46 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	free_padding(t_padding *pad)
{
	free(pad->left);
	free(pad->middle);
	free(pad->right);
}
