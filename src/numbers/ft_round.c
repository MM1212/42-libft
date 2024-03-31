/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:54:08 by martiper          #+#    #+#             */
/*   Updated: 2024/03/31 13:57:55 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ft_ld	ft_round(t_ft_ld n, int precision)
{
	t_ft_ld	dec;
	t_ft_ld	round;

	dec = n - (long)n;
	round = precision / 2;
	if (n < 0)
		round = -round;
	if (dec < -round || (dec == -round && (long)n % 2 != 0))
		return ((long)n - 1);
	return ((long)n);
}
