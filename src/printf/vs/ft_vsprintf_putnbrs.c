/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putnbrs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:07 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 19:37:05 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"
#include <limits.h>
#include <stdbool.h>

#define NUMERIC_CHARS "0123456789"
#define HEXA_CHARS_LOWER "0123456789abcdef"
#define HEXA_CHARS_UPPER "0123456789ABCDEF"
#define LONG_MAX_2 147483647

size_t	spf_putnbr(\
	t_ft_sprintf_buffer *buffer, \
	long long n, \
	t_ft_printf_flags flags \
)
{
	char	*ptr;
	size_t	count;
	size_t	len;

	count = 0;
	ptr = ft_itoa(n);
	if (!ptr)
		return (0);
	len = ft_strlen(ptr);
	if (flags.space)
		len++;
	if (flags.positive && n > 0)
		len++;
	count += spf_output_padding(buffer, len, flags, true);
	flags.disabled = true;
	if (flags.space && buffer->size > 0)
		count += spf_putchar(buffer, ' ', flags);
	if (flags.positive && n > 0 && buffer->size > 0)
		count += spf_putchar(buffer, '+', flags);
	count += spf_putstr(buffer, ptr, flags);
	free(ptr);
	return (count);
}

static size_t	putnbr_unsigned(\
	t_ft_sprintf_buffer *buffer, \
	unsigned long long n, \
	t_ft_printf_flags flags \
)
{
	size_t	count;

	count = 1;
	if (n >= 10)
		count += spf_putnbr_unsigned(buffer, n / 10, flags);
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
	len = ft_def_printf_count_digits(n, false);
	if (flags.space)
		len++;
	if (flags.positive)
		len++;
	count += spf_output_padding(buffer, len, flags, true);
	if (flags.space)
		count += spf_putchar(buffer, ' ', flags);
	else if (flags.positive)
		count += spf_putchar(buffer, '+', flags);
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
	if (n >= 10)
		count += puthexadecimal(buffer, n / 10, upper, flags);
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
	len = ft_def_printf_count_digits(n, false);
	if (flags.space)
		len++;
	if (flags.positive)
		len++;
	count += spf_output_padding(buffer, len, flags, true);
	flags.disabled = true;
	if (flags.hex_prefix)
	{
		if (upper)
			count += spf_putstr(buffer, "0X", flags);
		else
			count += spf_putstr(buffer, "0x", flags);
	}
	return (puthexadecimal(buffer, n, upper, flags) + count);
}
