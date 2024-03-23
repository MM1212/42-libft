/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:50:19 by martiper          #+#    #+#             */
/*   Updated: 2024/03/23 22:19:03 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf_int_flags.h"

static void	parse_flags(\
	const char *format, \
	size_t *idx, \
	t_ft_printf_flags *flags \
)
{
	if (format[*idx] == '#')
	{
		flags->hex_prefix = true;
		(*idx)++;
	}
	else if (format[*idx] == ' ')
	{
		flags->space = true;
		(*idx)++;
	}
	else if (format[*idx] == '+')
	{
		flags->positive = true;
		(*idx)++;
	}
	else if (format[*idx] == '-')
	{
		flags->justify = FT_PRINTF_JUSTIFY_LEFT;
		(*idx)++;
	}
	else if (format[*idx] == '0')
	{
		flags->pad_char = '0';
		(*idx)++;
	}
}

static void	parse_width(\
	const char *format, \
	size_t *idx, \
	t_ft_printf_flags *flags, \
	va_list args \
)
{
	if (format[*idx] != '.')
		return ;
	(*idx)++;
	if (format[*idx] == '*')
	{
		flags->precision = va_arg(args, int);
		(*idx)++;
	}
	else
	{
		flags->precision = ft_atoi(&format[*idx]);
		while (format[*idx] && ft_isdigit(format[*idx]))
			(*idx)++;
	}
}

t_ft_printf_flags	ft_def_printf_flags(\
	const char *format, \
	size_t *idx, \
	va_list args \
)
{
	t_ft_printf_flags	flags;

	ft_bzero(&flags, sizeof(flags));
	flags.precision = -1;
	flags.pad_char = ' ';
	flags.justify = FT_PRINTF_JUSTIFY_RIGHT;
	parse_flags(format, idx, &flags);
	if (format[*idx] == '*')
	{
		flags.padding = va_arg(args, int);
		(*idx)++;
	}
	else
	{
		flags.padding = ft_atoi(&format[*idx]);
		while (format[*idx] && ft_isdigit(format[*idx]))
			(*idx)++;
	}
	parse_width(format, idx, &flags, args);
	return (flags);
}

size_t	ft_def_printf_count_digits(long long n, bool signed_value)
{
	size_t	count;

	count = 0;
	if (signed_value && n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

size_t	ft_def_printf_count_float_digits(double n)
{
	long long	dec;
	size_t		count;

	count = 0;
	dec = (long long)n;
	while (dec)
	{
		dec /= 10;
		count++;
	}
	n -= (long long)n;
	if (n < 0)
		n *= -1;
	if (n == 0)
		return (count);
	while (n - (long long)n)
	{
		n *= 10;
		count++;
	}
	return (count);
}
