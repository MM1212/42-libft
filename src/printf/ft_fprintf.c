/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:09:44 by martiper          #+#    #+#             */
/*   Updated: 2023/11/15 22:09:55 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_vfprintf(fd, format, args);
	va_end(args);
	return (count);
}
