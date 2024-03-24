/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putnbrs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:07 by mm                #+#    #+#             */
/*   Updated: 2024/03/24 21:36:29 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"
#include <limits.h>
#include <stdbool.h>

#define NUMERIC_CHARS "0123456789"
#define HEXA_CHARS_LOWER "0123456789abcdef"
#define HEXA_CHARS_UPPER "0123456789ABCDEF"
#define LONG_MAX_2 147483647

size_t	vfpf_putnbr(int fd, long long n, t_ft_printf_flags flags)
{
	char	*ptr;
	size_t	count;
	size_t	len;

	ptr = ft_itoa(n);
	if (!ptr)
		return (0);
	count = 0;
	len = ft_strlen(ptr);
	if (flags.space)
		len++;
	if (flags.positive && n > 0)
		len++;
	count += vfpf_output_padding(fd, len, flags, true);
	flags.disabled = true;
	if (flags.space)
		count += vfpf_putchar(fd, ' ', flags);
	else if (n > 0 && flags.positive)
		count += vfpf_putchar(fd, '+', flags);
	count += vfpf_putstr(fd, ptr, flags);
	free(ptr);
	return (count);
}

static size_t	putnbr_unsigned(\
	int fd, \
	unsigned long long n, \
	t_ft_printf_flags flags \
)
{
	size_t	count;

	count = 0;
	if (n > 9)
		count += vfpf_unsigned(fd, n / 10, flags);
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
	len = ft_def_printf_count_digits(n, false);
	if (flags.space)
		len++;
	if (flags.positive)
		len++;
	count += vfpf_output_padding(fd, len, flags, true);
	flags.disabled = true;
	if (flags.space)
		count += vfpf_putchar(fd, ' ', flags);
	else if (flags.positive)
		count += vfpf_putchar(fd, '+', flags);
	return (putnbr_unsigned(fd, n, flags) + count);
}

static size_t	puthexadecimal(\
	int fd,
	unsigned long long n, \
	int upper \
)
{
	size_t	count;

	count = 0;
	if (n >= 16)
		count += puthexadecimal(fd, n / 16, upper);
	if (upper)
		count += write(1, &HEXA_CHARS_UPPER[n % 16], 1);
	else
		count += write(1, &HEXA_CHARS_LOWER[n % 16], 1);
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
	len = ft_def_printf_count_digits(n, false);
	if (flags.hex_prefix)
		len += 2;
	count += vfpf_output_padding(fd, len, flags, true);
	flags.disabled = true;
	if (flags.hex_prefix)
	{
		if (upper)
			count += vfpf_putstr(fd, "0X", flags);
		else
			count += vfpf_putstr(fd, "0x", flags);
	}
	return (puthexadecimal(fd, n, upper) + count);
}
