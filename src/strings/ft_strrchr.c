/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:30:38 by mm                #+#    #+#             */
/*   Updated: 2024/03/27 18:19:17 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*orig;

	if (!s)
		return (NULL);
	orig = s;
	while (*s++)
		;
	s--;
	while (s != orig && *s != (unsigned char)c)
		s--;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strnrchr(const char *s, int c, size_t n)
{
	const char	*orig;
	size_t		len;

	if (!s)
		return (NULL);
	len = n;
	orig = s;
	while (*s && n--)
		s++;
	while (s != orig && *s != (unsigned char)c)
		s--;
	if ((size_t)(s - orig) >= len)
		return (NULL);
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
