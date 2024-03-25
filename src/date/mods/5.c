/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:52:02 by martiper          #+#    #+#             */
/*   Updated: 2024/03/25 18:13:22 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mods.h"

void	mod_handler_y(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(\
		data->buffer, data->size, \
		format, (data->tm->tm_year + 1900) % 100 \
	);
}

void	mod_handler_modulo(t_date_mod_handler_data *data)
{
	*(*data->buffer)++ = '%';
}

void	mod_handler_newline(t_date_mod_handler_data *data)
{
	*(*data->buffer)++ = '\n';
}

void	mod_handler_tab(t_date_mod_handler_data *data)
{
	*(*data->buffer)++ = '\t';
}
