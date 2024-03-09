/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:41:36 by martiper          #+#    #+#             */
/*   Updated: 2024/03/09 12:37:42 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strjoin(size_t count, ...)
{
	char	*join;
	va_list	args;
	size_t	len;
	size_t	i;

	va_start(args, count);
	len = 0;
	i = count;
	while (i--)
		len += ft_strlen(va_arg(args, char *));
	va_end(args);
	va_start(args, count);
	join = ft_calloc(len + 1, sizeof(char));
	if (!join)
		return (NULL);
	i = count;
	while (i--)
		ft_strlcat(join, va_arg(args, char *), len + 1);
	va_end(args);
	return (join);
}

char	*ft_strjoin2(char **strs)
{
	char	*join;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (strs[i])
		len += ft_strlen(strs[i++]);
	join = ft_calloc(len + 1, sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (strs[i])
		ft_strlcat(join, strs[i++], len + 1);
	return (join);
}
