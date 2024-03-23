/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putfloat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:07:03 by martiper          #+#    #+#             */
/*   Updated: 2024/03/23 19:41:03 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"

static void	manage_padding(\
	t_ft_sprintf_buffer *buffer, \
	double n, \
	t_ft_printf_flags flags, \
	size_t *len \
)
{
	*len = 0;
	if (flags.precision == -1)
		flags.precision = 6;
	*len += ft_def_printf_count_float_digits(n);
	if (n < 0 && (long)n == 0)
		(*len)++;
	*len = spf_output_padding(buffer, *len, flags, true);
	flags.disabled = true;
}

/*
	Output a float number with the given precision.
 */
size_t	spf_putfloat(\
	t_ft_sprintf_buffer *buffer, \
	double n, \
	t_ft_printf_flags flags \
)
{
	size_t		count;
	double		dec;
	int			i;

	manage_padding(buffer, n, flags, &count);
	if (n < 0 && (long)n == 0)
		count += spf_putchar(buffer, '-', flags);
	count += spf_putnbr(buffer, (long)n, flags);
	if (flags.precision > 0)
	{
		count += spf_putchar(buffer, '.', flags);
		dec = ft_absf(n - ft_abs((long)n));
		i = 0;
		while (i < flags.precision)
			i++;
		while (i-- > 0)
		{
			dec *= 10;
			count += spf_putnbr(buffer, (long)dec, flags);
			dec -= (long)dec;
		}
	}
	return (count);
}
