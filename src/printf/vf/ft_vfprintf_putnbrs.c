/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putnbrs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:07 by mm                #+#    #+#             */
/*   Updated: 2024/04/02 22:23:45 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"
#include <limits.h>
#include <stdbool.h>

#define NUMERIC_CHARS "0123456789"
#define HEXA_CHARS_LOWER "0123456789abcdef"
#define HEXA_CHARS_UPPER "0123456789ABCDEF"
#define LONG_MAX_2 147483647

// size_t	vfpf_putnbr(int fd, long long n, t_ft_printf_flags flags)
// {
// 	char	*ptr;
// 	size_t	count;
// 	size_t	len;

// 	ptr = ft_itoa(n);
// 	if (!ptr)
// 		return (0);
// 	count = 0;
// 	len = ft_strlen(ptr);
// 	if (flags.space)
// 		len++;
// 	if (flags.positive && n > 0)
// 		len++;
// 	count += vfpf_output_padding(fd, len, flags, true);
// 	flags.disabled = true;
// 	if (flags.space)
// 		count += vfpf_putchar(fd, ' ', flags);
// 	else if (n > 0 && flags.positive)
// 		count += vfpf_putchar(fd, '+', flags);
// 	count += vfpf_putstr(fd, ptr, flags);
// 	free(ptr);
// 	return (count);
// }

static size_t	putnbr_signed(\
	int fd, \
	signed long long n, \
	t_ft_printf_flags flags \
)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count += putnbr_signed(fd, n / 10, flags);
	count += vfpf_putchar(fd, NUMERIC_CHARS[n % 10], flags);
	return (count);
}

size_t	vfpf_putnbr(\
	int fd, \
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
	count += vfpf_output_padding(fd, len, flags, true);
	flags.disabled = true;
	if (flags.space)
		count += vfpf_putchar(fd, ' ', flags);
	else if (flags.positive && n > 0)
		count += vfpf_putchar(fd, '+', flags);
	if (n < 0)
	{
		count += vfpf_putchar(fd, '-', flags);
		n = -n;
	}
	return (putnbr_signed(fd, n, flags) + count);
}

static size_t	putnbr_unsigned(\
	int fd, \
	unsigned long long n, \
	t_ft_printf_flags flags \
)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count += putnbr_unsigned(fd, n / 10, flags);
	count += vfpf_putchar(fd, NUMERIC_CHARS[n % 10], flags);
	return (count);
}

size_t	vfpf_unsigned(\
	int fd, \
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
	count += vfpf_output_padding(fd, len, flags, true);
	flags.disabled = true;
	if (flags.space)
		count += vfpf_putchar(fd, ' ', flags);
	return (putnbr_unsigned(fd, n, flags) + count);
}

static size_t	puthexadecimal(\
	int fd,
	unsigned long long n, \
	int upper, \
	t_ft_printf_flags flags
)
{
	size_t	count;

	count = 0;
	if (n >= 16)
		count += puthexadecimal(fd, n / 16, upper, flags);
	if (upper)
		count += vfpf_putchar(fd, HEXA_CHARS_UPPER[n % 16], flags);
	else
		count += vfpf_putchar(fd, HEXA_CHARS_LOWER[n % 16], flags);
	return (count);
}

size_t	vfpf_puthexadecimal(\
	int fd, \
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
	if (flags.pad_char == ' ' || !flags.hex_prefix)
		count += vfpf_output_padding(fd, len, flags, true);
	flags.disabled = true;
	if (flags.hex_prefix)
	{
		if (upper)
			count += vfpf_putstr(fd, "0X", flags);
		else
			count += vfpf_putstr(fd, "0x", flags);
		if (flags.pad_char == '0')
		{
			flags.disabled = false;
			count += vfpf_output_padding(fd, len, flags, true);
			flags.disabled = true;
		}
	}
	return (puthexadecimal(fd, n, upper, flags) + count);
}
