/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:54:10 by martiper          #+#    #+#             */
/*   Updated: 2023/06/09 13:01:05 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countchar(const char *str, char c)
{
	size_t	i;
	int		count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == c)
			count++;
	if (str[i] == c)
		count++;
	return (count);
}
