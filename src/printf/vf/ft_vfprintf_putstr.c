/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:44 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 22:04:45 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

size_t	vfpf_putstr(int fd, const char *str, t_ft_printf_flags flags)
{
	size_t	count;
	size_t	len;

	if (!str)
		return (vfpf_putstr(fd, "(null)", flags));
	count = vfpf_output_padding(fd, ft_strlen(str), flags, true);
	len = ft_strlen(str);
	if (flags.precision >= 0 && (size_t)flags.precision < len)
		len = flags.precision;
	count += write(fd, str, len);
	return (count);
}
