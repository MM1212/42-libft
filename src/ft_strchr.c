/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:27:33 by mm                #+#    #+#             */
/*   Updated: 2023/06/08 12:09:04 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && (const unsigned char)*s != (const unsigned char)c)
		s++;
	if ((const unsigned char)*s == (const unsigned char)c)
		return ((char *)s);
	return (NULL);
}

/*
	Compares each str char with every char from the set.
	Returns a boolean value if it found a match.
 */
bool	ft_strchr_set(const char *str, const char *set)
{
	size_t	i;

	if (!str || !set)
		return (false);
	i = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i++]))
			return (true);
	}
	return (false);
}
