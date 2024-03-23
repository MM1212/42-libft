/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_modifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:44:35 by martiper          #+#    #+#             */
/*   Updated: 2024/03/23 19:38:04 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_internal.h"

size_t	vfpf_output_padding(\
	int fd, \
	size_t to_print_count, \
	t_ft_printf_flags flags, \
	bool before_print
) {
	size_t	count;

	count = 0;
	if (flags.disabled)
		return (0);
	if (before_print && flags.justify != FT_PRINTF_JUSTIFY_RIGHT)
		return (0);
	if (!before_print && flags.justify != FT_PRINTF_JUSTIFY_LEFT)
		return (0);
	if (to_print_count < flags.padding)
	{
		flags.padding -= to_print_count;
		flags.disabled = true;
		while (flags.padding--)
			count += vfpf_putchar(fd, flags.pad_char, flags);
	}
	return (count);
}
