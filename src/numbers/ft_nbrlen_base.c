/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:24:21 by martiper          #+#    #+#             */
/*   Updated: 2024/03/24 18:27:07 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen_base(long n, uint32_t base)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= (long)base)
	{
		len++;
		n /= base;
	}
	return (len);
}

size_t	ft_unbrlen_base(unsigned long n, uint32_t base)
{
	size_t	len;

	len = 1;
	while (n >= base)
	{
		len++;
		n /= base;
	}
	return (len);
}
