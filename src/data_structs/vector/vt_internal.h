/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vt_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:06:21 by martiper          #+#    #+#             */
/*   Updated: 2024/03/26 22:38:21 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VT_INTERNAL_H
# define VT_INTERNAL_H

# include <stdbool.h>
# include <libft.h>
# include "lxt/dst/vector.h"

typedef struct s_vt_sort_pair {
	ssize_t	high;
	ssize_t	low;
}	t_vt_sort_pair;

void		vector_call_delete_all(t_vector *self);
void		*vector_at(t_vector *self, size_t index);
bool		vector_push_back(t_vector *self, void *elem);
void		*vector_emplace_back(t_vector *self);
void		*vector_pop_back(t_vector *self);
bool		vector_insert(t_vector *self, size_t index, void *elem);
bool		vector_erase(t_vector *self, size_t index);
bool		vector_swap(t_vector *self, size_t index1, size_t index2);
void		vector_foreach(t_vector *self, t_vector_foreach_f f, void *arg);
t_vector	*vector_map(t_vector *self, t_vector_map_f f, void *arg);
void		*vector_find(t_vector *self, t_vector_find_f f, void *arg);
void		vector_sort(t_vector *self, t_vector_cmp_f cmp);
void		vector_sort2(t_vector *self, t_vector_cmp2_f cmp, void *arg);
t_vector	*vector_sort3(t_vector *self, t_vector_cmp2_f cmp, void *arg);
void		vector_clear(t_vector *self);
void		vector_destroy(t_vector *self);
bool		vector_resize(t_vector *self, size_t new_size);
bool		vector_reserve(t_vector *self, size_t new_capacity);
bool		vector_shrink_to_fit(t_vector *self);
void		vector_noop(void *elem);

#endif
