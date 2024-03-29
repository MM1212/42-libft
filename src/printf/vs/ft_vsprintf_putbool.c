/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putbool.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:44 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 19:34:58 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"

size_t	spf_putbool(\
	t_ft_sprintf_buffer *buffer, \
	bool value, \
	t_ft_printf_flags flags \
)
{
	size_t	count;

	if (value)
		count = spf_putstr(buffer, "true", flags);
	else
		count = spf_putstr(buffer, "false", flags);
	return (count);
}
