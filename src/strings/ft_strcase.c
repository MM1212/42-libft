/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:14:02 by martiper          #+#    #+#             */
/*   Updated: 2024/03/25 13:15:42 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_struppercase(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		str[idx] = ft_toupper(str[idx]);
		idx++;
	}
	return (str);
}

char	*ft_strlowercase(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		str[idx] = ft_tolower(str[idx]);
		idx++;
	}
	return (str);
}

char	*ft_str_revcase(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		if (ft_islower(str[idx]))
			str[idx] = ft_toupper(str[idx]);
		else if (ft_isupper(str[idx]))
			str[idx] = ft_tolower(str[idx]);
		idx++;
	}
	return (str);
}
