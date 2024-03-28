/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:02:12 by martiper          #+#    #+#             */
/*   Updated: 2024/03/28 15:02:05 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	symbols_check(char c, int i, bool *has_dot, bool *has_sign)
{
	if (c == '-' || c == '+')
	{
		if (*has_sign || i > 0)
			return (false);
		*has_sign = true;
	}
	else if (c == '.')
	{
		if (*has_dot)
			return (false);
		*has_dot = true;
	}
	else if (!ft_isdigit(c))
		return (false);
	return (true);
}

/*
	*Checks if the string is a number.
	*Will correctly check positive, negative, zero, and/or floating point numbers.
	*Doesn't support hexadecimal numbers.
 */
bool	ft_isnbr(char *str, bool has_sign, bool floating)
{
	int		i;
	bool	has_dot;
	bool	has_sign;

	if (!str || !*str)
		return (false);
	i = 0;
	has_dot = !floating;
	has_sign = !has_sign;
	while (str[i])
	{
		if (!symbols_check(str[i], i, &has_dot, &has_sign))
			return (false);
		i++;
	}
	return (true);
}
