/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:44 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 18:48:58 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

size_t	vfpf_putstr(int fd, const char *str, t_ft_printf_flags flags)
{
	size_t	count;

	if (!str)
		return (vfpf_putstr(fd, "(null)", flags));
	vfpf_output_padding(fd, ft_strlen(str), flags, true);
	count = write(fd, str, ft_strlen(str));
	return (count);
}
