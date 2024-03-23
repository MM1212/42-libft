/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:12:26 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 19:34:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"

size_t	spf_putchar(\
	t_ft_sprintf_buffer *buffer, \
	const char c, \
	t_ft_printf_flags flags \
)
{
	size_t	count;

	count = spf_output_padding(buffer, 1, flags, true);
	if (buffer->size <= 0)
		return (count);
	*buffer->buffer++ = c;
	count++;
	buffer->size--;
	return (count);
}
