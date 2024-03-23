/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:44 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 22:19:32 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"

size_t	spf_putstr(\
	t_ft_sprintf_buffer *buffer, \
	const char *str, \
	t_ft_printf_flags flags
)
{
	size_t	count;
	size_t	len;

	if (!str)
		return (spf_putstr(buffer, "(null)", flags));
	count = spf_output_padding(buffer, ft_strlen(str), flags, true);
	len = ft_strlen(str);
	if (flags.precision > 0 && (size_t)flags.precision < len)
		len = flags.precision;
	if (buffer->size > 0)
	{
		ft_memmove(buffer->buffer, str, len);
		buffer->buffer += len;
		buffer->size -= len;
		count += len;
	}
	return (count);
}
