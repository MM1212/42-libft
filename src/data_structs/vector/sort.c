/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:48:01 by martiper          #+#    #+#             */
/*   Updated: 2024/03/26 21:37:05 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vt_internal.h"

ssize_t	partition(\
	t_vector *vector, \
	t_vt_sort_pair pair, \
	t_vector_cmp2_f cmp, \
	void *data \
)
{
	void	*pivot;
	ssize_t	i;
	ssize_t	j;

	pivot = vector->at(vector, pair.low);
	i = pair.low;
	j = pair.high;
	while (i < j)
	{
		while (cmp(vector->at(vector, i), pivot, data) <= 0 && \
			i <= pair.high - 1)
			i++;
		while (cmp(vector->at(vector, j), pivot, data) > 0 && \
			j >= pair.low + 1)
			j--;
		if (i < j)
			vector->swap(vector, i, j);
	}
	vector->swap(vector, pair.low, j);
	return (j);
}

void	quick_sort(\
	t_vector *vector, \
	t_vt_sort_pair pair, \
	t_vector_cmp2_f cmp, \
	void *data \
)
{
	ssize_t	partition_idx;

	if (pair.low >= pair.high)
		return ;
	partition_idx = partition(\
		vector, \
		pair, \
		cmp, data \
	);
	quick_sort(\
		vector, \
		(t_vt_sort_pair){partition_idx - 1, pair.low}, \
		cmp, data \
	);
	quick_sort(\
		vector, \
		(t_vt_sort_pair){pair.high, partition_idx + 1}, \
		cmp, data \
	);
}

void	vector_sort(t_vector *handle, t_vector_cmp_f cmp)
{
	quick_sort(\
		handle, \
		(t_vt_sort_pair){handle->size - 1, 0}, \
		(t_vector_cmp2_f)cmp, NULL \
	);
}

void	vector_sort2(t_vector *handle, t_vector_cmp2_f cmp, void *data)
{
	quick_sort(\
		handle, \
		(t_vt_sort_pair){handle->size - 1, 0}, \
		cmp, data \
	);
}
