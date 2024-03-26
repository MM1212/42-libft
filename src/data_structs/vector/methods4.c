/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:55:00 by martiper          #+#    #+#             */
/*   Updated: 2024/03/26 19:55:08 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vt_internal.h"

void	*vector_find(t_vector *handle, t_vector_find_f f, void *data)
{
	size_t	i;

	i = 0;
	while (i < handle->size)
	{
		if (f(vector_at(handle, i), i, data))
			return (vector_at(handle, i));
		i++;
	}
	return (NULL);
}
