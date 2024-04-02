/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putnbrs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:07 by mm                #+#    #+#             */
/*   Updated: 2024/04/02 22:23:50 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"
#include <limits.h>
#include <stdbool.h>

#define NUMERIC_CHARS "0123456789"
#define HEXA_CHARS_LOWER "0123456789abcdef"
#define HEXA_CHARS_UPPER "0123456789ABCDEF"
#define LONG_MAX_2 147483647

static size_t	putnbr_signed(\
	t_ft_sprintf_buffer *buffer, \
	signed long long n, \
	t_ft_printf_flags flags \
)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count += putnbr_signed(buffer, n / 10, flags);
	if (buffer->size > 0)
		count += spf_putchar(buffer, NUMERIC_CHARS[n % 10], flags);
	return (count);
}

size_t	spf_putnbr(\
	t_ft_sprintf_buffer *buffer, \
	signed long long n, \
	t_ft_printf_flags flags \
)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = ft_def_printf_count_digits(n, true, 10);
	if (flags.space)
		len++;
	if ((flags.positive && n > 0))
		len++;
	count += spf_output_padding(buffer, len, flags, true);
	flags.disabled = true;
	if (flags.space)
		count += spf_putchar(buffer, ' ', flags);
	else if (flags.positive && n > 0)
		count += spf_putchar(buffer, '+', flags);
	if (n < 0)
	{
		count += spf_putchar(buffer, '-', flags);
		n = -n;
	}
	return (putnbr_signed(buffer, n, flags) + count);
}

static size_t	putnbr_unsigned(\
	t_ft_sprintf_buffer *buffer, \
	unsigned long long n, \
	t_ft_printf_flags flags \
)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count += putnbr_unsigned(buffer, n / 10, flags);
	if (buffer->size > 0)
		count += spf_putchar(buffer, NUMERIC_CHARS[n % 10], flags);
	return (count);
}

size_t	spf_putnbr_unsigned(\
	t_ft_sprintf_buffer *buffer, \
	unsigned long long n, \
	t_ft_printf_flags flags \
)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = ft_def_printf_count_digits(n, false, 10);
	if (flags.space)
		len++;
	count += spf_output_padding(buffer, len, flags, true);
	flags.disabled = true;
	if (flags.space)
		count += spf_putchar(buffer, ' ', flags);
	return (putnbr_unsigned(buffer, n, flags) + count);
}

static size_t	puthexadecimal(\
	t_ft_sprintf_buffer *buffer, \
	unsigned long long n, \
	int upper, \
	t_ft_printf_flags flags
)
{
	size_t	count;

	count = 0;
	if (n >= 16)
		count += puthexadecimal(buffer, n / 16, upper, flags);
	if (upper)
		count += spf_putchar(buffer, HEXA_CHARS_UPPER[n % 16], flags);
	else
		count += spf_putchar(buffer, HEXA_CHARS_LOWER[n % 16], flags);
	return (count);
}

size_t	spf_puthexadecimal(\
	t_ft_sprintf_buffer *buffer, \
	unsigned long long n, \
	int upper, \
	t_ft_printf_flags flags \
)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = ft_def_printf_count_digits(n, false, 16);
	if (flags.hex_prefix)
		len += 2;
	if (!flags.hex_prefix || flags.pad_char == ' ')
		count += spf_output_padding(buffer, len, flags, true);
	flags.disabled = true;
	if (flags.hex_prefix)
	{
		if (upper)
			count += spf_putstr(buffer, "0X", flags);
		else
			count += spf_putstr(buffer, "0x", flags);
		if (flags.pad_char == '0')
		{
			flags.disabled = false;
			count += spf_output_padding(buffer, len, flags, true);
			flags.disabled = true;
		}
	}
	return (puthexadecimal(buffer, n, upper, flags) + count);
}
