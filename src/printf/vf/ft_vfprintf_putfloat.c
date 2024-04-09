/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putfloat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:07:03 by martiper          #+#    #+#             */
/*   Updated: 2024/04/09 11:26:38 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"
#include <math.h>
#include <stdio.h>

static void	manage_padding(\
	int fd, \
	double n, \
	t_ft_printf_flags *flags, \
	size_t *len \
)
{
	*len = 0;
	if (flags->precision == -1)
		flags->precision = 6;
	*len += ft_def_printf_count_float_digits(n);
	if (n < 0 && (long)n == 0)
		(*len)++;
	*len = vfpf_output_padding(fd, *len, *flags, true);
	flags->disabled = true;
}

/*
	Output a float number with the given precision.
 */
size_t	vfpf_putfloat(int fd, double n, t_ft_printf_flags flags)
{
	size_t		len;
	long double	dec;
	size_t		precision;

	manage_padding(fd, n, &flags, &len);
	if (n < 0 && (long)n == 0)
		len += vfpf_putchar(fd, '-', flags);
	precision = ft_pow(10, flags.precision);
	dec = (n - (long)n) * precision;
	if ((long)(dec * 10) % 10 >= 5)
		dec += 1;
	if (dec >= precision)
	{
		n += 1 / (double)precision;
		dec = 0;
	}
	len += vfpf_putnbr(fd, (long)n, flags);
	if (n < 0)
		n = -n;
	if (flags.precision > 0)
	{
		len += vfpf_putchar(fd, '.', flags);
		len += ft_printf("%0*d", flags.precision, (long)dec % precision);
	}
	return (len);
}
