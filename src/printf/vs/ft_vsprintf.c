/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:24 by mm                #+#    #+#             */
/*   Updated: 2024/03/21 16:21:13 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"
#include "printf/ft_printf.h"

static size_t	ft_format(\
	t_ft_sprintf_buffer *buffer, \
	const char *format, \
	va_list args, \
	size_t *idx \
)
{
	t_ft_printf_flags	flags;
	char				mod;

	flags = ft_def_printf_flags(format, idx);
	mod = format[++(*idx)];
	if (mod == 'c')
		return (ft_def_sprintf_putchar(buffer, va_arg(args, int)));
	else if (mod == 's')
		return (ft_def_sprintf_putstr(buffer, va_arg(args, char *)));
	else if (mod == 'd' || mod == 'i')
		return (ft_def_sprintf_putnbr(buffer, va_arg(args, int), flags));
	else if (mod == 'u')
		return (ft_def_sprintf_putnbr_unsigned(buffer,
				va_arg(args, unsigned int), flags));
	else if (mod == 'x' || mod == 'X')
		return (ft_def_sprintf_puthexadecimal(buffer,
				va_arg(args, unsigned int), mod == 'X', flags));
	else if (mod == 'p')
		return (ft_def_sprintf_putaddress(buffer,
				va_arg(args, void *), flags));
	else if (mod == 'f')
		return (ft_def_sprintf_putfloat(buffer, va_arg(args, double), flags));
	else if (mod == 'b')
		return (ft_def_sprintf_putbool(buffer, va_arg(args, int)));
	else if (mod == '%')
		return (ft_def_sprintf_putchar(buffer, '%'));
	return (0);
}

int	ft_vsprintf(char *str, size_t size, const char *format, va_list args)
{
	size_t				idx;
	size_t				count;
	t_ft_sprintf_buffer	buffer;

	idx = 0;
	count = 0;
	if (!str || !format)
		return (-1);
	buffer = (t_ft_sprintf_buffer){.size = size, .buffer = str};
	while (format[idx] && count < size - 1)
	{
		if (format[idx] != '%')
		{
			count += ft_def_sprintf_putchar(&buffer, format[idx++]);
			continue ;
		}
		count += ft_format(&buffer, format, args, &idx);
		idx++;
	}
	if (count < size)
		str[count] = '\0';
	return (count);
}
