/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 02:38:01 by martiper          #+#    #+#             */
/*   Updated: 2023/06/12 02:38:42 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_absi(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	ft_absf(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
