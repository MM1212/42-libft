/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:53:49 by martiper          #+#    #+#             */
/*   Updated: 2024/03/31 13:57:27 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ft_ld	ft_pow(t_ft_ld x, t_ft_ld y)
{
	t_ft_ld	res;

	res = 1;
	while (y > 0)
	{
		res *= x;
		y--;
	}
	return (res);
}
