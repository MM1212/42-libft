/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:50:19 by martiper          #+#    #+#             */
/*   Updated: 2024/03/21 17:22:30 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf_int_flags.h"

t_ft_printf_flags	ft_def_printf_flags(const char *format, size_t *idx)
{
	t_ft_printf_flags	flags;

	flags.hex_prefix = false;
	flags.positive = false;
	flags.space = false;
	flags.precision = 6;
	if (format[*idx + 1] == '#')
	{
		flags.hex_prefix = (format[*idx + 2] == 'x' || format[*idx + 2] == 'X');
		(*idx)++;
	}
	else if ((format[*idx] == 'd' || format[*idx] == 'i') && \
		format[*idx + 1] == ' ')
	{
		flags.space = true;
		(*idx)++;
	}
	else if (format[*idx + 1] == '.')
	{
		(*idx)++;
		flags.precision = ft_atoi(&format[*idx + 1]);
		while (ft_isdigit(format[*idx + 1]))
			(*idx)++;
	}
	return (flags);
}
