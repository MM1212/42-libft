/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:44 by mm                #+#    #+#             */
/*   Updated: 2023/11/15 22:18:00 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"

size_t	ft_def_sprintf_putstr(t_ft_sprintf_buffer *buffer, const char *str)
{
	size_t	count;

	if (!str)
		return (ft_def_sprintf_putstr(buffer, "(null)"));
	count = ft_strlen(str);
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
