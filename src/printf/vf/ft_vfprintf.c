/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:24 by mm                #+#    #+#             */
/*   Updated: 2023/11/15 22:11:17 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"
#include "printf/ft_printf.h"

size_t	ft_def_vfprintf_format(\
	int fd, \
	const char mod, \
	va_list args, \
	t_ft_printf_flags flags \
)
{
	if (mod == 'c')
		return (ft_def_vfprintf_putchar(fd, va_arg(args, int), flags));
	else if (mod == 's')
		return (ft_def_vfprintf_putstr(fd, va_arg(args, char *), flags));
	else if (mod == 'p')
		return (ft_def_vfprintf_putaddress(fd, va_arg(args, void *), flags));
	else if (mod == 'd' || mod == 'i')
		return (ft_def_vfprintf_putnbr(fd, va_arg(args, int), flags));
	else if (mod == 'u')
		return (ft_def_vfprintf_putnbr_unsigned(fd, va_arg(args, unsigned int),
				flags));
	else if (mod == 'x')
		return (ft_def_vfprintf_puthexadecimal(fd,
				va_arg(args, unsigned int), 0, flags));
	else if (mod == 'X')
		return (ft_def_vfprintf_puthexadecimal(fd,
				va_arg(args, unsigned int), 1, flags));
	else if (mod == 'f')
		return (ft_def_vfprintf_putfloat(fd, va_arg(args, double), flags));
	else if (mod == '%')
		return (ft_def_vfprintf_putchar(fd, '%', flags));
	else
		return (0);
}

int	ft_vfprintf(int fd, const char *format, va_list args)
{
	size_t	idx;
	size_t	count;

	if (!format)
		return (-1);
	idx = 0;
	count = 0;
	while (format[idx])
	{
		if (format[idx] != '%')
		{
			ft_putchar_fd(format[idx++], fd);
			count++;
			continue ;
		}
		count += ft_def_vfprintf_format(fd, format[++idx], args, \
			ft_def_printf_flags(format, &idx));
		idx++;
	}
	return (count);
}
