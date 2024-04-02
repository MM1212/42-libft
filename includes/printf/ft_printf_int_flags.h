/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_flags.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:48:09 by martiper          #+#    #+#             */
/*   Updated: 2024/04/02 22:13:41 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INT_FLAGS_H
# define FT_PRINTF_INT_FLAGS_H

# include <stddef.h>
# include <stdbool.h>
# include <libft.h>

typedef enum e_ft_printf_justify
{
	FT_PRINTF_JUSTIFY_LEFT,
	FT_PRINTF_JUSTIFY_RIGHT
}			t_ft_printf_justify;

typedef struct s_ft_printf_flags
{
	bool	disabled;
	bool	space;
	bool	positive;
	bool	hex_prefix;
	int		precision;
	size_t	padding;
	char	pad_char;
	int		justify;
}			t_ft_printf_flags;

t_ft_printf_flags	ft_def_printf_flags(\
	const char *format, \
	size_t *idx, \
	va_list args \
);
size_t				ft_def_printf_count_digits(long long n, bool signed_value, int base);
size_t				ft_def_printf_count_float_digits(double n);

#endif
