/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:45:12 by mm                #+#    #+#             */
/*   Updated: 2024/03/21 16:16:12 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VFPRINTF_INTERNAL_H
# define FT_VFPRINTF_INTERNAL_H

# include "libft.h"
# include "stdlib.h"
# include <stdarg.h>
# include <stdbool.h>
# include "printf/ft_printf_int_flags.h"

size_t				ft_def_vfprintf_putaddress(\
	int fd, \
	void *n, \
	t_ft_printf_flags flags \
);
size_t				ft_def_vfprintf_putstr(\
	int fd, \
	const char *str, \
	t_ft_printf_flags flags \
);
size_t				ft_def_vfprintf_putchar(\
	int fd, \
	const char c, \
	t_ft_printf_flags flags \
);
size_t				ft_def_vfprintf_putnbr(\
	int fd, \
	long long n, \
	t_ft_printf_flags flags \
);
size_t				ft_def_vfprintf_putnbr_unsigned(\
	int fd, \
	unsigned long long n, \
	t_ft_printf_flags flags \
);
size_t				ft_def_vfprintf_puthexadecimal(\
	int fd, \
	unsigned long long n, \
	int upper, \
	t_ft_printf_flags flags \
);
size_t				ft_def_vfprintf_putfloat(\
	int fd, \
	double n, \
	t_ft_printf_flags flags \
);
size_t				ft_def_vfprintf_putbool(\
	int fd, \
	bool n, \
	t_ft_printf_flags flags \
);
size_t				ft_def_vfprintf_format(\
	int fd, \
	const char mod, \
	va_list args, \
	t_ft_printf_flags flags \
);

#endif
