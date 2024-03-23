/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_putchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:12:26 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 18:48:36 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

size_t	vfpf_putchar(int fd, const char c, t_ft_printf_flags flags)
{
	vfpf_output_padding(fd, 1, flags, true);
	return (write(fd, &c, 1));
}
