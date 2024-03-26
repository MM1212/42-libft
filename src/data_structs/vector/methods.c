/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:18:34 by martiper          #+#    #+#             */
/*   Updated: 2024/03/26 19:58:23 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vt_internal.h"
#include <libft.h>

void	vector_call_delete_all(t_vector *handle)
{
	size_t	i;

	if (!handle->deletef)
		return ;
	i = 0;
	while (i < handle->size)
		handle->deletef(vector_at(handle, i++));
}

void	vector_destroy(t_vector *handle)
{
	vector_call_delete_all(handle);
	free(handle->data);
	free(handle);
}

void	vector_clear(t_vector *handle)
{
	vector_call_delete_all(handle);
	handle->size = 0;
	handle->capacity = 0;
	handle->shrink_to_fit(handle);
}

void	*vector_at(t_vector *handle, size_t index)
{
	if (index >= handle->size)
		return (NULL);
	return (handle->data + index * handle->elem_size);
}

bool	vector_resize(t_vector *handle, size_t new_size)
{
	void	*new_data;
	size_t	idx;

	if (new_size == handle->size)
		return (true);
	else if (new_size < handle->size)
	{
		idx = 0;
		while (idx < handle->size - new_size)
			handle->deletef(vector_at(handle, new_size + idx++));
		handle->size = new_size;
		return (true);
	}
	new_data = ft_calloc(new_size, handle->elem_size);
	if (!new_data)
		return (false);
	ft_memmove(\
		new_data, handle->data, \
		handle->size * handle->elem_size \
	);
	free(handle->data);
	handle->data = new_data;
	handle->size = new_size;
	handle->capacity = new_size;
	return (true);
}
