/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:52:02 by martiper          #+#    #+#             */
/*   Updated: 2024/03/25 18:12:57 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mods.h"

void	mod_handler_c_uppcase(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(\
		data->buffer, data->size, \
		format, (data->tm->tm_year + 1900) / 100 \
	);
}

void	mod_handler_j(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, data->tm->tm_yday + 1);
}

void	mod_handler_q(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, (data->tm->tm_mon + 1) / 4);
}

void	mod_handler_u(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, data->tm->tm_wday + 1);
}

void	mod_handler_w(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, data->tm->tm_wday);
}
