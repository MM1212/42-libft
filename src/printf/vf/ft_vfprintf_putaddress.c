/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putaddress.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:13:07 by mm                #+#    #+#             */
/*   Updated: 2024/04/02 16:46:30 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

size_t	vfpf_putaddress(\
	int fd, \
	void *address, \
	t_ft_printf_flags flags \
)
{
	if (!address)
		return (vfpf_putstr(fd, "(nil)", flags));
	flags.hex_prefix = true;
	return (vfpf_puthexadecimal(\
		fd, \
		(unsigned long long)address, \
		0, \
		flags \
	));
}
