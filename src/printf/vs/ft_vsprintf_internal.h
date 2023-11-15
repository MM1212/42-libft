/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:45:12 by mm                #+#    #+#             */
/*   Updated: 2023/11/15 22:08:16 by martiper         ###   ########.fr       */
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

size_t	ft_def_sprintf_putchar(t_ft_sprintf_buffer *buffer, const char c);
size_t	ft_def_sprintf_putstr(t_ft_sprintf_buffer *buffer, const char *str);
size_t	ft_def_sprintf_putnbr(\
	t_ft_sprintf_buffer *buffer, \
	long long n, \
	t_ft_printf_flags flags \
);
size_t	ft_def_sprintf_putnbr_unsigned(\
	t_ft_sprintf_buffer *buffer, \
	unsigned long long n, \
	t_ft_printf_flags flags \
);
size_t	ft_def_sprintf_puthexadecimal(\
	t_ft_sprintf_buffer *buffer, \
	unsigned long long n, \
	int upper, \
	t_ft_printf_flags flags \
);
size_t	ft_def_sprintf_putaddress(\
	t_ft_sprintf_buffer *buffer, \
	void *addr, \
	t_ft_printf_flags flags \
);
size_t	ft_def_sprintf_putfloat(\
	t_ft_sprintf_buffer *buffer, \
	double n, \
	t_ft_printf_flags flags \
);

#endif
