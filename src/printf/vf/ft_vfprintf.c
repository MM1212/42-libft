/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:24 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 19:39:52 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"
#include "printf/ft_printf.h"

static size_t	ft_format(\
	t_ft_printf_format_args *data, \
	va_list args \
);

static size_t	ft_create_format_args(
	int fd, \
	const char *format, \
	va_list args, \
	size_t *idx \
)
{
	t_ft_printf_format_args	data;
	size_t					count;

	data.fd = fd;
	data.format = format;
	data.idx = idx;
	data.flags = ft_def_printf_flags(format, idx, args);
	data.mod = format[(*idx)++];
	count = (ft_format(&data, args));
	count += vfpf_output_padding(fd, count, data.flags, false);
	return (count);
}

static size_t	ft_format(\
	t_ft_printf_format_args *data, \
	va_list args \
)
{
	if (data->mod == 'c')
		return (vfpf_putchar(data->fd, va_arg(args, int), data->flags));
	else if (data->mod == 's')
		return (vfpf_putstr(data->fd, va_arg(args, char *), data->flags));
	else if (data->mod == 'p')
		return (vfpf_putaddress(data->fd, va_arg(args, void *), data->flags));
	else if (data->mod == 'd' || data->mod == 'i')
		return (vfpf_putnbr(data->fd, va_arg(args, int), data->flags));
	else if (data->mod == 'u')
		return (vfpf_unsigned(data->fd, va_arg(args, unsigned int),
				data->flags));
	else if (data->mod == 'x')
		return (vfpf_puthexadecimal(data->fd,
				va_arg(args, unsigned int), 0, data->flags));
	else if (data->mod == 'X')
		return (vfpf_puthexadecimal(data->fd,
				va_arg(args, unsigned int), 1, data->flags));
	else if (data->mod == 'f')
		return (vfpf_putfloat(data->fd, va_arg(args, double), data->flags));
	else if (data->mod == 'b')
		return (vfpf_putbool(data->fd, va_arg(args, int), data->flags));
	else if (data->mod == '%')
		return (vfpf_putchar(data->fd, '%', data->flags));
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
		idx++;
		count += ft_create_format_args(fd, format, args, &idx);
	}
	return (count);
}
