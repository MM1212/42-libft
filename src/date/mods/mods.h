/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:50:28 by martiper          #+#    #+#             */
/*   Updated: 2024/03/25 18:22:56 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODS_H
# define MODS_H

# include "lxt/date.h"
# include <libft.h>

typedef struct s_date_flags
{
	bool	zero;
	bool	space;
	bool	plus;
}				t_date_flags;

typedef struct s_date_mod	t_date_mod;

typedef struct s_date_mod_handler_data
{
	time_t				date;
	const t_date_mod	*mod;
	char				**buffer;
	size_t				size;
	t_date_flags		flags;
	struct tm			*tm;
}							t_date_mod_handler_data;

typedef void				(*t_date_mod_handler)(\
	t_date_mod_handler_data *data \
);
struct s_date_mod
{
	char				mod;
	const char			*format;
	int					padding;
	t_date_mod_handler	handler;
};

typedef struct s_check_mod_args
{
	time_t		date;
	char		**buffer;
	size_t		size;
	const char	*format;
	size_t		*format_idx;
	struct tm	*tm;
}	t_check_mod_args;

typedef struct s_handle_format_args
{
	time_t		date;
	char		**buffer;
	size_t		buffer_size;
	const char	*format;
	struct tm	*tm;
}	t_handle_format_args;

t_date_flags	parse_flags(const char *format, size_t *idx);
char			*build_format_buffer(\
	t_date_flags flags, \
	const t_date_mod *mod \
);
void			printf_mod(\
	char **buffer, \
	size_t size, \
	const char *format, \
	...\
);
void			mod_handler_y_uppcase(t_date_mod_handler_data *data);
void			mod_handler_m(t_date_mod_handler_data *data);
void			mod_handler_d(t_date_mod_handler_data *data);
void			mod_handler_h_uppcase(t_date_mod_handler_data *data);
void			mod_handler_i_uppcase(t_date_mod_handler_data *data);
void			mod_handler_k(t_date_mod_handler_data *data);
void			mod_handler_l(t_date_mod_handler_data *data);
void			mod_handler_m_uppcase(t_date_mod_handler_data *data);
void			mod_handler_p_uppcase(t_date_mod_handler_data *data);
void			mod_handler_p(t_date_mod_handler_data *data);
void			mod_handler_s(t_date_mod_handler_data *data);
void			mod_handler_s_uppcase(t_date_mod_handler_data *data);
void			mod_handler_z(t_date_mod_handler_data *data);
void			mod_handler_a(t_date_mod_handler_data *data);
void			mod_handler_b(t_date_mod_handler_data *data);
void			mod_handler_c_uppcase(t_date_mod_handler_data *data);
void			mod_handler_j(t_date_mod_handler_data *data);
void			mod_handler_q(t_date_mod_handler_data *data);
void			mod_handler_u(t_date_mod_handler_data *data);
void			mod_handler_w(t_date_mod_handler_data *data);
void			mod_handler_y(t_date_mod_handler_data *data);
void			mod_handler_modulo(t_date_mod_handler_data *data);
void			mod_handler_newline(t_date_mod_handler_data *data);
void			mod_handler_tab(t_date_mod_handler_data *data);
#endif
