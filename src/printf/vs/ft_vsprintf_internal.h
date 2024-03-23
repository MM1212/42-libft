/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:45:12 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 19:43:01 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VSPRINTF_INTERNAL_H
# define FT_VSPRINTF_INTERNAL_H

# include "libft.h"
# include "stdlib.h"
# include <stdarg.h>
# include <stdbool.h>
# include "printf/ft_printf_int_flags.h"

typedef struct s_ft_sprintf_buffer
{
	char	*buffer;
	size_t	size;
}			t_ft_sprintf_buffer;

typedef struct s_ft_sprintf_format_args
{
	t_ft_sprintf_buffer	*buffer;
	const char			*format;
	char				mod;
	t_ft_printf_flags	flags;
	size_t				*idx;
}	t_ft_sprintf_format_args;

size_t	spf_putchar(\
	t_ft_sprintf_buffer *buffer, \
	const char c, \
	t_ft_printf_flags flags \
);
size_t	spf_putstr(\
	t_ft_sprintf_buffer *buffer, \
	const char *str, \
	t_ft_printf_flags flags \
);
size_t	spf_putnbr(\
	t_ft_sprintf_buffer *buffer, \
	long long n, \
	t_ft_printf_flags flags \
);
size_t	spf_putnbr_unsigned(\
	t_ft_sprintf_buffer *buffer, \
	unsigned long long n, \
	t_ft_printf_flags flags \
);
size_t	spf_puthexadecimal(\
	t_ft_sprintf_buffer *buffer, \
	unsigned long long n, \
	int upper, \
	t_ft_printf_flags flags \
);
size_t	spf_putaddress(\
	t_ft_sprintf_buffer *buffer, \
	void *addr, \
	t_ft_printf_flags flags \
);
size_t	spf_putfloat(\
	t_ft_sprintf_buffer *buffer, \
	double n, \
	t_ft_printf_flags flags \
);
size_t	spf_putbool(\
	t_ft_sprintf_buffer *buffer, \
	bool n, \
	t_ft_printf_flags flags \
);

size_t	spf_output_padding(\
	t_ft_sprintf_buffer *buffer, \
	size_t to_print_count, \
	t_ft_printf_flags flags, \
	bool before_print \
);

#endif
