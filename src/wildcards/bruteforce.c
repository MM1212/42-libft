/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:30:12 by martiper          #+#    #+#             */
/*   Updated: 2024/03/29 22:24:34 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_data(\
	t_wildcard *data, \
	const char *pattern, \
	const char *str, \
	size_t s_len \
)
{
	ft_bzero(data, sizeof(t_wildcard));
	data->pattern = pattern;
	data->str = str;
	data->last_wildcard_idx = -1;
	data->next_to_wildcard_idx = -1;
	data->backtrack_idx = -1;
	data->p_len = ft_strlen(pattern);
	data->s_len = s_len;
	if (data->s_len == 0)
		data->s_len = ft_strlen(str);
}

static bool	algorithm(t_wildcard *data)
{
	if (data->p_idx < data->p_len && \
		(data->pattern[data->p_idx] == '?' || \
			data->pattern[data->p_idx] == data->str[data->s_idx]))
	{
		data->p_idx++;
		data->s_idx++;
	}
	else if (data->p_idx < data->p_len && data->pattern[data->p_idx] == '*')
	{
		data->last_wildcard_idx = data->p_idx;
		data->next_to_wildcard_idx = ++data->p_idx;
		data->backtrack_idx = data->s_idx;
	}
	else if (data->last_wildcard_idx != -1)
	{
		data->p_idx = data->next_to_wildcard_idx;
		data->s_idx = ++data->backtrack_idx;
	}
	else
		return (false);
	return (true);
}

bool	ft_wildcard_match(const char *pattern, const char *str)
{
	t_wildcard	data;

	init_data(&data, pattern, str, 0);
	while (data.s_idx < data.s_len)
	{
		if (!algorithm(&data))
			return (false);
	}
	while (data.p_idx < data.p_len)
	{
		if (pattern[data.p_idx++] != '*')
			return (false);
	}
	return (true);
}

bool	ft_wildcard_match_n(const char *pattern, const char *str, size_t s_len)
{
	t_wildcard	data;

	init_data(&data, pattern, str, s_len);
	while (data.s_idx < data.s_len)
	{
		if (!algorithm(&data))
			return (false);
	}
	while (data.p_idx < data.p_len)
	{
		if (pattern[data.p_idx++] != '*')
			return (false);
	}
	return (true);
}
