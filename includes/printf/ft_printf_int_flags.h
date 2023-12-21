/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_flags.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:48:09 by martiper          #+#    #+#             */
/*   Updated: 2023/11/15 22:47:49 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INT_FLAGS_H
# define FT_PRINTF_INT_FLAGS_H

# include <stddef.h>
# include <stdbool.h>
# include <libft.h>

typedef struct s_ft_printf_flags
{
	bool	space;
	bool	positive;
	bool	hex_prefix;
	int		precision;
}			t_ft_printf_flags;

t_ft_printf_flags	ft_def_printf_flags(const char *format, size_t *idx);

#endif
