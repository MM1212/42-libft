/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putfloat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:07:03 by martiper          #+#    #+#             */
/*   Updated: 2024/04/09 11:27:51 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"

static void	manage_padding(\
	t_ft_sprintf_buffer *buffer, \
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
	*len = spf_output_padding(buffer, *len, *flags, true);
	flags->disabled = true;
}

static size_t	put_decimal_part(\
	t_ft_sprintf_buffer *buffer,
	double dec,
	t_ft_printf_flags flags
)
{
	size_t	count;
	size_t	i;

	count = spf_putchar(buffer, '.', flags);
	i = ft_sprintf(\
		buffer->buffer, buffer->size, \
		"%0*d", flags.precision, (long)dec \
	);
	buffer->buffer += i;
	buffer->size -= i;
	count += i;
	return (count);
}

size_t	spf_putfloat(\
	t_ft_sprintf_buffer *buffer, \
	double n, \
	t_ft_printf_flags flags \
)
{
	size_t		count;
	double		dec;
	size_t		precision;

	manage_padding(buffer, n, &flags, &count);
	if (n < 0 && (long)n == 0)
		count += spf_putchar(buffer, '-', flags);
	precision = ft_pow(10, flags.precision);
	dec = (n - (long)n) * ft_pow(10, flags.precision);
	if ((long)(dec * 10) % 10 >= 5)
		dec += 1;
	if (dec >= precision)
	{
		n += 1 / (double)precision;
		dec = 0;
	}
	count += spf_putnbr(buffer, (long)n, flags);
	if (n < 0)
		n = -n;
	if (flags.precision > 0)
		count += put_decimal_part(buffer, dec, flags);
	return (count);
}
