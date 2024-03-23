/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:45:12 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 19:40:05 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VFPRINTF_INTERNAL_H
# define FT_VFPRINTF_INTERNAL_H

# include "libft.h"
# include "stdlib.h"
# include <stdarg.h>
# include <stdbool.h>
# include "printf/ft_printf_int_flags.h"

typedef struct s_ft_printf_format_args
{
	int					fd;
	const char			*format;
	char				mod;
	t_ft_printf_flags	flags;
	size_t				*idx;
}	t_ft_printf_format_args;

size_t				vfpf_putaddress(\
	int fd, \
	void *n, \
	t_ft_printf_flags flags \
);
size_t				vfpf_putstr(\
	int fd, \
	const char *str, \
	t_ft_printf_flags flags \
);
size_t				vfpf_putchar(\
	int fd, \
	const char c, \
	t_ft_printf_flags flags \
);
size_t				vfpf_putnbr(\
	int fd, \
	long long n, \
	t_ft_printf_flags flags \
);
size_t				vfpf_unsigned(\
	int fd, \
	unsigned long long n, \
	t_ft_printf_flags flags \
);
size_t				vfpf_puthexadecimal(\
	int fd, \
	unsigned long long n, \
	int upper, \
	t_ft_printf_flags flags \
);
size_t				vfpf_putfloat(\
	int fd, \
	double n, \
	t_ft_printf_flags flags \
);
size_t				vfpf_putbool(\
	int fd, \
	bool n, \
	t_ft_printf_flags flags \
);

size_t				vfpf_output_padding(\
	int fd, \
	size_t to_print_count, \
	t_ft_printf_flags flags, \
	bool before_print \
);

#endif
