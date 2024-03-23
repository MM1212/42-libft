/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:10:38 by martiper          #+#    #+#             */
/*   Updated: 2024/03/21 16:19:27 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include <unistd.h>

int	ft_vprintf(const char *format, va_list args)
{
	return (ft_vfprintf(STDOUT_FILENO, format, args));
}
