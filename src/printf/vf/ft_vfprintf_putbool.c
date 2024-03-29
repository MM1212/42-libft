/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putbool.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:44 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 14:33:56 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

size_t	vfpf_putbool(int fd, bool value, t_ft_printf_flags flags)
{
	size_t	count;

	if (value)
		count = vfpf_putstr(fd, "true", flags);
	else
		count = vfpf_putstr(fd, "false", flags);
	return (count);
}
