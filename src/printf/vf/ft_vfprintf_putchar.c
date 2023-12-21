/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:12:26 by mm                #+#    #+#             */
/*   Updated: 2023/11/15 21:58:50 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

size_t	ft_def_vfprintf_putchar(int fd, const char c, t_ft_printf_flags flags)
{
	(void)flags;
	return (write(fd, &c, 1));
}
