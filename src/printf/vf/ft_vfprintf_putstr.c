/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:44 by mm                #+#    #+#             */
/*   Updated: 2023/11/15 22:15:44 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

size_t	ft_def_vfprintf_putstr(int fd, const char *str, t_ft_printf_flags flags)
{
	size_t	count;

	if (!str)
		return (ft_def_vfprintf_putstr(fd, "(null)", flags));
	(void)flags;
	count = write(fd, str, ft_strlen(str));
	return (count);
}
