/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:24:21 by martiper          #+#    #+#             */
/*   Updated: 2024/03/27 23:29:38 by martiper         ###   ########.fr       */
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

size_t	ft_floatlen(double n)
{
	size_t	len;

	len = ft_nbrlen_base((long)n, 10);
	if (n < 0)
		n = -n;
	if (n - (long)n > 0)
		len += 1 + ft_unbrlen_base((unsigned long)((n - (long)n) * 1000000000), 10);
	return (len);
}
