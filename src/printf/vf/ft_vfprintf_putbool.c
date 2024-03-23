/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putbool.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:44 by mm                #+#    #+#             */
/*   Updated: 2024/03/21 16:17:24 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

size_t	ft_def_vfprintf_putbool(int fd, bool value, t_ft_printf_flags flags)
{
	size_t	count;

	if (value)
		count = ft_def_vfprintf_putstr(fd, "true", flags);
	else
		count = ft_def_vfprintf_putstr(fd, "false", flags);
	return (count);
}
