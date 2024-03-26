/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:00:21 by martiper          #+#    #+#             */
/*   Updated: 2024/03/26 22:46:20 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_vector	t_vector;
typedef void			(*t_vector_delete_f)(void *elem);
typedef void			(*t_vector_foreach_f)(\
	void *elem, \
	size_t index, \
	void *arg \
);
typedef void			(*t_vector_map_f)(\
	void *elem, \
	void *new_elem, \
	size_t index, \
	void *arg \
);
typedef bool			(*t_vector_find_f)(\
	void *elem, \
	size_t index, \
	void *arg \
);
typedef int				(*t_vector_cmp_f)(\
	void *elem1, \
	void *elem2 \
);
typedef int				(*t_vector_cmp2_f)(\
	void *elem1, \
	void *elem2, \
	void *arg \
);

typedef void			*(*t_vector_at)(\
	t_vector *self, \
	size_t index \
);
typedef bool			(*t_vector_push_back)(\
	t_vector *self, \
	void *elem \
);
typedef void			*(*t_vector_emplace_back)(\
	t_vector *self \
);
typedef void			*(*t_vector_pop_back)(\
	t_vector *self \
);
typedef bool			(*t_vector_insert)(\
	t_vector *self, \
	size_t index, \
	void *elem \
);
typedef bool			(*t_vector_erase)(\
	t_vector *self, \
	size_t index \
);
typedef bool			(*t_vector_swap)(\
	t_vector *self, \
	size_t index1, \
	size_t index2 \
);
typedef void			(*t_vector_foreach)(\
	t_vector *self, \
	t_vector_foreach_f f, \
	void *arg \
);
typedef t_vector		*(*t_vector_map)(\
	t_vector *self, \
	t_vector_map_f f, \
	void *arg \
);
typedef void			*(*t_vector_find)(\
	t_vector *self, \
	t_vector_find_f f, \
	void *arg \
);
typedef void			(*t_vector_sort)(\
	t_vector *self, \
	t_vector_cmp_f cmp \
);
typedef void			(*t_vector_sort2)(\
	t_vector *self, \
	t_vector_cmp2_f cmp, \
	void *arg \
);
// populate pointer array buffer with elements from vector
// and sort the array using cmp function
typedef t_vector		*(*t_vector_sort3)(\
	t_vector *self, \
	t_vector_cmp2_f cmp, \
	void *arg, \
	t_vector *buffer \
);
typedef void			(*t_vector_clear)(\
	t_vector *self \
);
typedef void			(*t_vector_destroy)(\
	t_vector *self \
);
typedef bool			(*t_vector_resize)(\
	t_vector *self, \
	size_t new_size \
);
typedef bool			(*t_vector_reserve)(\
	t_vector *self, \
	size_t new_capacity \
);
typedef bool			(*t_vector_shrink_to_fit)(\
	t_vector *self \
);

struct s_vector
{
	void					*data;
	size_t					size;
	size_t					capacity;
	size_t					elem_size;
	t_vector_delete_f		deletef;
	t_vector_at				at;
	t_vector_push_back		push_back;
	t_vector_emplace_back	emplace_back;
	t_vector_pop_back		pop_back;
	t_vector_insert			insert;
	t_vector_erase			erase;
	t_vector_swap			swap;
	t_vector_foreach		foreach;
	t_vector_map			map;
	t_vector_find			find;
	t_vector_sort			sort;
	t_vector_sort2			sort2;
	t_vector_sort3			sort3;
	t_vector_clear			clear;
	t_vector_destroy		destroy;
	t_vector_resize			resize;
	t_vector_reserve		reserve;
	t_vector_shrink_to_fit	shrink_to_fit;
};

void		vector_noop(void *elem);
t_vector	*vector_create(size_t elem_size);
t_vector	*vector_create2(size_t elem_size, \
size_t capacity);
t_vector	*vector_create3(size_t elem_size, \
size_t capacity, \
t_vector_delete_f deletef);

#endif
