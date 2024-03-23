/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putnbrs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:15:07 by mm                #+#    #+#             */
/*   Updated: 2023/11/15 21:58:06 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"
#include <limits.h>

#define NUMERIC_CHARS "0123456789"
#define HEXA_CHARS_LOWER "0123456789abcdef"
#define HEXA_CHARS_UPPER "0123456789ABCDEF"
#define LONG_MAX_2 147483647

size_t	ft_def_vfprintf_putnbr(int fd, long long n, t_ft_printf_flags flags)
{
	char	*ptr;
	size_t	count;

	ptr = ft_itoa(n);
	if (!ptr)
		return (0);
	count = 0;
	if (flags.space)
		count += ft_def_vfprintf_putchar(fd, ' ', flags);
	else if (n > 0 && flags.positive)
		count += ft_def_vfprintf_putchar(fd, '+', flags);
	count += ft_def_vfprintf_putstr(fd, ptr, flags);
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
		count += ft_def_vfprintf_putnbr_unsigned(fd, n / 10, flags);
	count += ft_def_vfprintf_putchar(fd, NUMERIC_CHARS[n % 10], flags);
	return (count);
}

size_t	ft_def_vfprintf_putnbr_unsigned(\
	int fd, \
	unsigned long long n, \
	t_ft_printf_flags flags \
)
{
	int	count;

	count = 0;
	if (flags.space)
		count += ft_def_vfprintf_putchar(fd, ' ', flags);
	else if (flags.positive)
		count += ft_def_vfprintf_putchar(fd, '+', flags);
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

size_t	ft_def_vfprintf_puthexadecimal(\
	int fd, \
	unsigned long long n, \
	int upper, \
	t_ft_printf_flags flags \
)
{
	size_t	count;

	count = 0;
	if (flags.hex_prefix)
	{
		if (upper)
			count += ft_def_vfprintf_putstr(fd, "0X", flags);
		else
			count += ft_def_vfprintf_putstr(fd, "0x", flags);
	}
	return (puthexadecimal(fd, n, upper) + count);
}