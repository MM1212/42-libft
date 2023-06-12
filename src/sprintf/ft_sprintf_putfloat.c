/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_putfloat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:07:03 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 03:29:52 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf_internal.h"

/*
	Output a float number with the given precision.
 */
size_t	ft_def_sprintf_putfloat(t_ft_sprintf_buffer *buffer, double n,
			t_ft_sprintf_flags flags)
{
	size_t		count;
	double		dec;
	int			i;

	count = 0;
	if (n < 0 && (long)n == 0)
		count += ft_def_sprintf_putchar(buffer, '-');
	count += ft_def_sprintf_putnbr(buffer, (long)n, flags);
	if (flags.precision > 0)
	{
		count += ft_def_sprintf_putchar(buffer, '.');
		dec = ft_absf(n - ft_abs((long)n));
		i = 0;
		while (i < flags.precision)
			i++;
		while (i-- > 0)
		{
			dec *= 10;
			count += ft_def_sprintf_putnbr(buffer, (long)dec, flags);
			dec -= (long)dec;
		}
	}
	return (count);
}
