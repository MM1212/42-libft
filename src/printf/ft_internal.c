/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_internal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:50:19 by martiper          #+#    #+#             */
/*   Updated: 2024/03/23 14:29:45 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf_int_flags.h"

t_ft_printf_flags	ft_def_printf_flags(const char *format, size_t *idx)
{
	t_ft_printf_flags	flags;

	ft_bzero(&flags, sizeof(flags));
	flags.precision = 6;
	if (format[*idx] == '#' && format[*idx + 1] != '\0' && \
		(format[*idx + 1] == 'x' || format[*idx + 1] == 'X'))
	{
		flags.hex_prefix = true;
		(*idx)++;
	}
	else if (format[*idx] == ' ' && format[*idx + 1] != '\0' && \
		(format[*idx + 1] == 'd' || format[*idx + 1] == 'i'))
	{
		flags.space = true;
		(*idx)++;
	}
	else if (format[*idx] == '.')
	{
		(*idx)++;
		flags.precision = ft_atoi(&format[*idx + 1]);
		while (ft_isdigit(format[*idx + 1]))
			(*idx)++;
	}
	return (flags);
}
