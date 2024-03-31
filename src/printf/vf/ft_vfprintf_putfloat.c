/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putfloat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:07:03 by martiper          #+#    #+#             */
/*   Updated: 2024/03/31 13:38:21 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

static void	manage_padding(\
	int fd, \
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
	*len = vfpf_output_padding(fd, *len, flags, true);
	flags.disabled = true;
}

/*
	Output a float number with the given precision.
 */
size_t	vfpf_putfloat(int fd, double n, t_ft_printf_flags flags)
{
	size_t		len;
	double		dec;
	int			i;

	manage_padding(fd, n, flags, &len);
	if (n < 0 && (long)n == 0)
		len += vfpf_putchar(fd, '-', flags);
	len += vfpf_putnbr(fd, (long)n, flags);
	if (flags.precision > 0)
	{
		vfpf_putchar(fd, '.', flags);
		len++;
		dec = ft_absf(n - ft_abs((long)n));
		i = flags.precision;
		while (i-- > 0)
		{
			dec *= 10;
			if (i == 0 && (long)(dec * 10) % 10 >= 5)
				dec += 10;
			len += vfpf_putnbr(fd, (long)dec, flags);
			dec -= (long)dec;
		}
	}
	return (len);
}
