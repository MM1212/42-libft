/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:56:02 by martiper          #+#    #+#             */
/*   Updated: 2024/03/31 13:56:57 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ft_ld	ft_ceil(t_ft_ld n)
{
	if (n - (long)n < 0)
		return ((long)n + 1);
	return ((long)n);
}
