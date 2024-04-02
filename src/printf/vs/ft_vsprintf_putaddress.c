/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putaddress.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:13:07 by mm                #+#    #+#             */
/*   Updated: 2024/04/02 16:49:21 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"

#define HEXA_CHARS "0123456789abcdef"

size_t	spf_putaddress(\
	t_ft_sprintf_buffer *buffer, \
	void *addr, \
	t_ft_printf_flags flags \
)
{
	if (!addr)
		return (spf_putstr(buffer, "(nil)", flags));
	flags.hex_prefix = true;
	return (spf_puthexadecimal(\
		buffer, \
		(unsigned long long)addr, \
		false, \
		flags \
	));
}
