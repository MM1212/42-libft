/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:44 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 19:34:25 by martiper         ###   ########.fr       */
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

	if (!str)
		return (spf_putstr(buffer, "(null)", flags));
	count = spf_output_padding(buffer, ft_strlen(str), flags, true);
	count += ft_strlen(str);
	if (count > buffer->size)
		count = buffer->size;
	if (buffer->size > 0)
	{
		ft_memmove(buffer->buffer, str, count);
		buffer->buffer += count;
		buffer->size -= count;
	}
	return (count);
}
