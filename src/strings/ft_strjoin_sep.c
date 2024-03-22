/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:22:10 by martiper          #+#    #+#             */
/*   Updated: 2024/03/22 15:17:18 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	count_args(char *sep, va_list args, size_t *len, size_t *count)
{
	char	*arg;

	*len = 0;
	*count = 0;
	while (1)
	{
		arg = va_arg(args, char *);
		if (!arg)
			break ;
		*len += ft_strlen(arg);
		(*count)++;
	}
	*len += ft_strlen(sep) * (*count - 1);
}

char	*ft_strjoin_sep(char *sep, ...)
{
	char	*join;
	char	*arg;
	va_list	args;
	size_t	len;
	size_t	count;

	if (!sep)
		return (NULL);
	va_start(args, sep);
	count_args(sep, args, &len, &count);
	va_end(args);
	va_start(args, sep);
	join = ft_calloc(len + 1, sizeof(char));
	if (!join)
		return (NULL);
	while (count--)
	{
		arg = va_arg(args, char *);
		ft_strlcat(join, arg, len + 1);
		if (count)
			ft_strlcat(join, sep, len + 1);
	}
	va_end(args);
	return (join);
}

char	*ft_strjoin_sep2(char *sep, char **strs)
{
	char	*join;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!strs)
		return (NULL);
	while (strs[i])
		len += ft_strlen(strs[i++]);
	len += ft_strlen(sep) * (i - 1);
	join = ft_calloc(len + 1, sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		ft_strlcat(join, strs[i], len + 1);
		if (strs[i + 1])
			ft_strlcat(join, sep, len + 1);
		i++;
	}
	return (join);
}
