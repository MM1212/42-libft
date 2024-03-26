/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:10:09 by martiper          #+#    #+#             */
/*   Updated: 2024/03/26 20:02:07 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vt_internal.h"
#include <libft.h>

static void	bind_methods(t_vector *handle)
{
	handle->at = vector_at;
	handle->push_back = vector_push_back;
	handle->emplace_back = vector_emplace_back;
	handle->pop_back = vector_pop_back;
	handle->insert = vector_insert;
	handle->erase = vector_erase;
	handle->swap = vector_swap;
	handle->foreach = vector_foreach;
	handle->map = vector_map;
	handle->find = vector_find;
	handle->sort = vector_sort;
	handle->sort2 = vector_sort2;
	handle->clear = vector_clear;
	handle->destroy = vector_destroy;
	handle->resize = vector_resize;
	handle->reserve = vector_reserve;
	handle->shrink_to_fit = vector_shrink_to_fit;
}

t_vector	*vector_create3(\
	size_t elem_size, \
	size_t capacity, \
	t_vector_delete_f delete_fn \
)
{
	t_vector	*handle;

	handle = ft_calloc(1, sizeof(t_vector));
	if (!handle)
		return (NULL);
	handle->elem_size = elem_size;
	handle->capacity = capacity;
	handle->deletef = delete_fn;
	handle->data = ft_calloc(capacity, elem_size);
	if (!handle->data)
	{
		free(handle);
		return (NULL);
	}
	bind_methods(handle);
	return (handle);
}

t_vector	*vector_create2(\
	size_t elem_size, \
	size_t capacity \
)
{
	return (vector_create3(elem_size, capacity, NULL));
}

t_vector	*vector_create(\
	size_t elem_size \
)
{
	return (vector_create2(elem_size, 0));
}

void	vector_noop(void *value)
{
	(void)value;
}
