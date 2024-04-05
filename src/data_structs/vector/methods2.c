/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:54:23 by martiper          #+#    #+#             */
/*   Updated: 2024/04/05 10:18:55 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vt_internal.h"

bool	vector_reserve(t_vector *handle, size_t new_capacity)
{
	void	*new_data;

	if (new_capacity <= handle->capacity)
		return (true);
	new_data = ft_calloc(new_capacity, handle->elem_size);
	if (!new_data)
		return (false);
	if (handle->copy_after_resize)
		ft_memmove(new_data, handle->data, handle->size * handle->elem_size);
	free(handle->data);
	handle->data = new_data;
	handle->capacity = new_capacity;
	return (true);
}

bool	vector_shrink_to_fit(t_vector *handle)
{
	void	*new_data;

	if (handle->capacity == handle->size)
		return (true);
	new_data = ft_calloc(handle->size, handle->elem_size);
	if (!new_data)
		return (false);
	if (handle->copy_after_resize)
		ft_memmove(new_data, handle->data, handle->size * handle->elem_size);
	free(handle->data);
	handle->data = new_data;
	handle->capacity = handle->size;
	return (true);
}

bool	vector_push_back(t_vector *handle, void *elem)
{
	bool	ok;

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
		handle->data + (handle->size++) * handle->elem_size, \
		elem, handle->elem_size \
	);
	return (true);
}

void	*vector_pop_back(t_vector *handle)
{
	void	*elem;

	if (!handle->size)
		return (NULL);
	elem = ft_calloc(1, handle->elem_size);
	if (!elem)
		return (NULL);
	ft_memmove(\
		elem, \
		handle->data + (handle->size - 1) * handle->elem_size, \
		handle->elem_size \
	);
	handle->size--;
	return (elem);
}

void	*vector_emplace_back(t_vector *handle)
{
	void	*elem;
	bool	ok;

	if (handle->size == handle->capacity)
	{
		if (handle->capacity)
			ok = handle->reserve(handle, handle->capacity * 2);
		else
			ok = handle->reserve(handle, 1);
		if (!ok)
			return (NULL);
	}
	elem = handle->data + (handle->size++) * handle->elem_size;
	return (elem);
}
