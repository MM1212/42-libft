/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:48:35 by martiper          #+#    #+#             */
/*   Updated: 2024/03/25 18:12:02 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mods.h"

void	mod_handler_y_uppcase(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, data->tm->tm_year + 1900);
}

void	mod_handler_m(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, data->tm->tm_mon + 1);
}

void	mod_handler_d(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, data->tm->tm_mday);
}

void	mod_handler_h_uppcase(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, data->tm->tm_hour);
}

void	mod_handler_i_uppcase(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, (data->tm->tm_hour + 1) % 12);
}
