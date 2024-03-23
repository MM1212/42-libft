/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:24 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 19:42:46 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"
#include "printf/ft_printf.h"

#include <stdio.h>

static size_t	ft_format(\
	t_ft_sprintf_format_args *data, \
	va_list args \
);

static size_t	ft_create_format_args(
	t_ft_sprintf_buffer *buffer, \
	const char *format, \
	va_list args, \
	size_t *idx \
)
{
	t_ft_sprintf_format_args	data;
	size_t						count;

	data.buffer = buffer;
	data.format = format;
	data.idx = idx;
	data.flags = ft_def_printf_flags(format, idx, args);
	data.mod = format[(*idx)++];
	count = (ft_format(&data, args));
	count += spf_output_padding(buffer, count, data.flags, false);
	return (count);
}

static size_t	ft_format(\
	t_ft_sprintf_format_args *data, \
	va_list args \
)
{
	if (data->mod == 'c')
		return (spf_putchar(data->buffer, va_arg(args, int), data->flags));
	else if (data->mod == 's')
		return (spf_putstr(data->buffer, va_arg(args, char *), data->flags));
	else if (data->mod == 'd' || data->mod == 'i')
		return (spf_putnbr(data->buffer,
				va_arg(args, int), data->flags));
	else if (data->mod == 'u')
		return (spf_putnbr_unsigned(data->buffer,
				va_arg(args, unsigned int), data->flags));
	else if (data->mod == 'x' || data->mod == 'X')
		return (spf_puthexadecimal(data->buffer,
				va_arg(args, unsigned int), data->mod == 'X', data->flags));
	else if (data->mod == 'p')
		return (spf_putaddress(data->buffer,
				va_arg(args, void *), data->flags));
	else if (data->mod == 'f')
		return (spf_putfloat(data->buffer,
				va_arg(args, double), data->flags));
	else if (data->mod == 'b')
		return (spf_putbool(data->buffer, va_arg(args, int), data->flags));
	else if (data->mod == '%')
		return (spf_putchar(data->buffer, '%', data->flags));
	return (0);
}

static size_t	output_char(\
	t_ft_sprintf_buffer *buffer, \
	const char c, \
	size_t	*idx
)
{
	if (buffer->size > 0)
	{
		*buffer->buffer++ = c;
		buffer->size--;
		(*idx)++;
		return (1);
	}
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
			if (buffer.size > 0)
				count += output_char(&buffer, format[idx], &idx);
			continue ;
		}
		idx++;
		count += ft_create_format_args(&buffer, format, args, &idx);
	}
	if (count < size)
		str[count] = '\0';
	return (count);
}
