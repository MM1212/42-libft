/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:36:39 by martiper          #+#    #+#             */
/*   Updated: 2024/03/25 18:21:43 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lxt/date.h"
#include "mods/mods.h"

static const t_date_mod	g_date_mods[] = {\
	{'Y', "d", 4, mod_handler_y_uppcase}, \
	{'m', "d", 2, mod_handler_m}, \
	{'d', "d", 2, mod_handler_d}, \
	{'H', "d", 2, mod_handler_h_uppcase}, \
	{'I', "d", 2, mod_handler_i_uppcase}, \
	{'k', "d", 2, mod_handler_k}, \
	{'l', "d", 2, mod_handler_l}, \
	{'M', "d", 2, mod_handler_m_uppcase}, \
	{'S', "d", 2, mod_handler_s_uppcase}, \
	{'P', "s", 2, mod_handler_p_uppcase}, \
	{'p', "s", 2, mod_handler_p}, \
	{'s', "d", 0, mod_handler_s}, \
	{'z', "d", 4, mod_handler_z}, \
	{'a', "s", 3, mod_handler_a}, \
	{'b', "s", 3, mod_handler_b}, \
	{'C', "d", 2, mod_handler_c_uppcase}, \
	{'j', "d", 3, mod_handler_j}, \
	{'q', "d", 1, mod_handler_q}, \
	{'u', "d", 0, mod_handler_u}, \
	{'w', "d", 0, mod_handler_w}, \
	{'y', "d", 2, mod_handler_y}, \
	{'%', "c", 0, mod_handler_modulo}, \
	{'n', "c", 0, mod_handler_newline}, \
	{'t', "c", 0, mod_handler_tab}, \
	{0, NULL, 0, NULL} \
};

static const size_t		g_mods_size = sizeof(g_date_mods) / sizeof(t_date_mod);

static void	handle_format(\
	t_handle_format_args args \
);

static const t_date_mod	*get_mod(char mod)
{
	size_t	idx;

	idx = 0;
	while (idx < g_mods_size)
	{
		if (g_date_mods[idx].mod == mod)
			return (&g_date_mods[idx]);
		idx++;
	}
	return (NULL);
}

static void	call_data_mod(
	t_check_mod_args args,
	const t_date_mod *mod,
	t_date_flags flags
)
{
	t_date_mod_handler_data	data;

	data = (t_date_mod_handler_data){\
		.date = args.date, .mod = mod, \
		.buffer = args.buffer, .size = args.size, \
		.flags = flags, .tm = args.tm \
	};
	mod->handler(&data);
}

static void	check_mod(\
	t_check_mod_args args
)
{
	const t_date_mod		*date_mod;
	t_date_flags			flags;
	char					mod;

	flags = parse_flags(args.format, args.format_idx);
	mod = args.format[(*args.format_idx)++];
	date_mod = get_mod(mod);
	if (!date_mod || !date_mod->handler)
	{
		*(*args.buffer)++ = '%';
		*(*args.buffer)++ = mod;
		return ;
	}
	if (ft_strlen(date_mod->format) > 1)
	{
		handle_format((t_handle_format_args){
			.date = args.date, .buffer = args.buffer, .buffer_size = args.size, \
			.format = date_mod->format, .tm = args.tm \
		});
		return ;
	}
	call_data_mod(args, date_mod, flags);
}

static void	handle_format(\
	t_handle_format_args args
)
{
	size_t	idx;

	idx = 0;
	while (args.format[idx])
	{
		if (args.format[idx++] != '%')
		{
			*(*args.buffer)++ = args.format[idx - 1];
			continue ;
		}
		check_mod((t_check_mod_args){
			.date = args.date, .buffer = args.buffer, .size = args.buffer_size, \
			.format = args.format, .format_idx = &idx, .tm = args.tm \
		});
	}
}

char	*date_format(time_t date, const char *format)
{
	struct tm	*tm;
	static char	buffer[4096];
	char		*cursor;

	tm = localtime(&date);
	if (!tm)
		return (NULL);
	cursor = buffer;
	ft_bzero(buffer, sizeof(buffer));
	handle_format((t_handle_format_args){
		.date = date, .buffer = &cursor, .buffer_size = sizeof(buffer), \
		.format = format, .tm = tm \
	});
	return (buffer);
}
