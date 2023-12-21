/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putaddress.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:13:07 by mm                #+#    #+#             */
/*   Updated: 2023/11/15 22:14:15 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

size_t	ft_def_vfprintf_putaddress(\
	int fd, \
	void *address, \
	t_ft_printf_flags flags \
)
{
	if (!address)
		return (ft_def_vfprintf_putstr(fd, "(nil)", flags));
	return (ft_def_vfprintf_puthexadecimal(\
		fd, \
		(unsigned long long)address, \
		0, \
		flags \
	));
}
