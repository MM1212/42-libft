/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:12:26 by mm                #+#    #+#             */
/*   Updated: 2023/11/15 22:16:36 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"

size_t	ft_def_sprintf_putchar(\
	t_ft_sprintf_buffer *buffer, \
	const char c \
)
{
	if (buffer->size <= 0)
		return (0);
	*buffer->buffer++ = c;
	buffer->size--;
	return (1);
}
