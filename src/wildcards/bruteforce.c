/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:30:12 by martiper          #+#    #+#             */
/*   Updated: 2024/03/31 11:18:11 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_data(\
	t_wildcard *data, \
	const char *pattern, \
	const char *str, \
	t_wildcard_flags flags
)
{
	ft_bzero(data, sizeof(t_wildcard));
	data->flags = flags;
	data->pattern = pattern;
	data->str = str;
	data->last_wildcard_idx = -1;
	data->next_to_wildcard_idx = -1;
	data->backtrack_idx = -1;
	if (data->flags.p_len)
		data->p_len = data->flags.p_len;
	else
		data->p_len = ft_strlen(pattern);
	if (data->flags.s_len)
		data->s_len = data->flags.s_len;
	else
		data->s_len = ft_strlen(str);
}

static void	select_char(\
	t_wildcard *data, \
	char *s, \
	char *p
)
{
	if (data->flags.case_insensitive)
	{
		*s = ft_tolower(data->str[data->s_idx]);
		*p = ft_tolower(data->pattern[data->p_idx]);
	}
	else
	{
		*s = data->str[data->s_idx];
		*p = data->pattern[data->p_idx];
	}
}

static bool	algorithm(t_wildcard *data)
{
	char	s;
	char	p;

	select_char(data, &s, &p);
	if (data->p_idx < data->p_len && (p == '?' || p == s))
	{
		data->p_idx++;
		data->s_idx++;
	}
	else if (data->p_idx < data->p_len && p == '*')
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

	init_data(&data, pattern, str, (t_wildcard_flags){0});
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

bool	ft_wildcard_match2(\
	const char *pattern, const char *str, \
	t_wildcard_flags flags \
)
{
	t_wildcard	data;

	init_data(&data, pattern, str, flags);
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
