/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:54:44 by martiper          #+#    #+#             */
/*   Updated: 2024/03/26 20:04:35 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vt_internal.h"

bool	vector_insert(t_vector *handle, size_t index, void *elem)
{
	bool	ok;

	if (index >= handle->size)
		return (false);
	if (handle->size == handle->capacity)
	{
		if (handle->capacity)
			ok = handle->reserve(handle, handle->capacity * 2);
		else
			ok = handle->reserve(handle, 1);
		if (!ok)
			return (false);
	}
	ft_memmove(\
		handle->data + (index + 1) * handle->elem_size, \
		handle->data + index * handle->elem_size, \
		(handle->size - index) * handle->elem_size \
	);
	ft_memmove(\
		handle->data + index * handle->elem_size, \
		elem, handle->elem_size \
	);
	handle->size++;
	return (true);
}

bool	vector_erase(t_vector *handle, size_t index)
{
	if (index >= handle->size)
		return (false);
	if (handle->deletef)
		handle->deletef(vector_at(handle, index));
	ft_memmove(\
		handle->data + index * handle->elem_size, \
		handle->data + (index + 1) * handle->elem_size, \
		(handle->size - index - 1) * handle->elem_size \
	);
	handle->size--;
	return (true);
}

bool	vector_swap(t_vector *handle, size_t i, size_t j)
{
	void	*tmp;

	if (i >= handle->size || j >= handle->size || i == j)
		return (false);
	tmp = ft_calloc(1, handle->elem_size);
	if (!tmp)
		return (false);
	ft_memmove(tmp, handle->data + i * handle->elem_size, \
		handle->elem_size);
	ft_memmove(\
		handle->data + i * handle->elem_size, \
		handle->data + j * handle->elem_size, \
		handle->elem_size \
	);
	ft_memmove(\
		handle->data + j * handle->elem_size, \
		tmp, \
		handle->elem_size \
	);
	free(tmp);
	return (true);
}

void	vector_foreach(t_vector *handle, t_vector_foreach_f f, void *data)
{
	size_t	i;

	i = 0;
	while (i < handle->size)
	{
		f(vector_at(handle, i), i, data);
		i++;
	}
}

t_vector	*vector_map(t_vector *handle, t_vector_map_f f, void *data)
{
	t_vector	*new_handle;
	size_t		i;

	new_handle = vector_create3(\
		handle->elem_size, handle->size, handle->deletef);
	if (!new_handle)
		return (NULL);
	i = 0;
	while (i < handle->size)
	{
		f(vector_at(handle, i), vector_at(new_handle, i), i, data);
		i++;
	}
	return (new_handle);
}
