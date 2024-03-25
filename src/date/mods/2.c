/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:51:39 by martiper          #+#    #+#             */
/*   Updated: 2024/03/25 18:10:55 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mods.h"

void	mod_handler_k(t_date_mod_handler_data *data)
{
	char	*format;

	ft_bzero(&data->flags, sizeof(t_date_flags));
	data->flags.space = true;
	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, data->tm->tm_hour);
}

void	mod_handler_l(t_date_mod_handler_data *data)
{
	char	*format;

	ft_bzero(&data->flags, sizeof(t_date_flags));
	data->flags.space = true;
	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, (data->tm->tm_hour + 1) % 12);
}

void	mod_handler_m_uppcase(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, data->tm->tm_min);
}

void	mod_handler_p_uppcase(t_date_mod_handler_data *data)
{
	char	*format;
	char	*am_pm;

	format = build_format_buffer(data->flags, data->mod);
	if (data->tm->tm_hour < 12)
		am_pm = "am";
	else
		am_pm = "pm";
	printf_mod(data->buffer, data->size, format, am_pm);
}

void	mod_handler_p(t_date_mod_handler_data *data)
{
	char	*format;
	char	*am_pm;

	format = build_format_buffer(data->flags, data->mod);
	if (data->tm->tm_hour < 12)
		am_pm = "AM";
	else
		am_pm = "PM";
	printf_mod(data->buffer, data->size, format, am_pm);
}
