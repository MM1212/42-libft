/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:10:08 by martiper          #+#    #+#             */
/*   Updated: 2023/11/15 22:18:28 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

int	ft_sprintf(char *str, size_t size, const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_vsprintf(str, size, format, args);
	va_end(args);
	return (count);
}
