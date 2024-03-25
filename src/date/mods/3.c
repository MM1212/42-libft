/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:52:02 by martiper          #+#    #+#             */
/*   Updated: 2024/03/25 18:08:21 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mods.h"

void	mod_handler_s(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, data->tm->tm_sec);
}

void	mod_handler_s_uppcase(t_date_mod_handler_data *data)
{
	char	*format;

	format = build_format_buffer(data->flags, data->mod);
	printf_mod(data->buffer, data->size, format, data->tm->tm_sec);
}

void	mod_handler_z(t_date_mod_handler_data *data)
{
	int		offset;
	char	sign;

	offset = data->tm->tm_gmtoff / 60;
	if (offset < 0)
		sign = '-';
	else
		sign = '+';
	offset = ft_abs(offset);
	printf_mod(\
		data->buffer, data->size, \
		"%c%02d%02d", sign, \
		offset / 60, offset % 60 \
	);
}

void	mod_handler_a(t_date_mod_handler_data *data)
{
	char	*buff;

	buff = ctime(&data->date);
	if (!buff)
		return ;
	printf_mod(data->buffer, data->size, "%.3s", buff);
}

void	mod_handler_b(t_date_mod_handler_data *data)
{
	char	*buff;

	buff = ctime(&data->date);
	if (!buff)
		return ;
	printf_mod(data->buffer, data->size, "%.3s", buff + 4);
}
