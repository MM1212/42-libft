/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_putbool.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:10:44 by mm                #+#    #+#             */
/*   Updated: 2024/03/21 16:18:42 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vsprintf_internal.h"

size_t	ft_def_sprintf_putbool(t_ft_sprintf_buffer *buffer, bool value)
{
	size_t	count;

	if (value)
		count = ft_def_sprintf_putstr(buffer, "true");
	else
		count = ft_def_sprintf_putstr(buffer, "false");
	return (count);
}
