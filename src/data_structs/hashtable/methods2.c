/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:47:27 by martiper          #+#    #+#             */
/*   Updated: 2024/03/25 17:58:16 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht_internal.h"
#include <libft.h>

bool	hashtable_remove_item(\
	t_hashtable *ht, \
	const char *key
)
{
	size_t		hash;
	t_ht_item	*cell;
	t_ht_item	*prev;

	hash = ht->hash(key) % ht->size;
	cell = ht->items[hash];
	prev = NULL;
	while (cell)
	{
		if (ft_strcmp(cell->key, key) == 0)
		{
			if (prev)
				prev->next = cell->next;
			else
				ht->items[hash] = cell->next;
			ht->deletef(cell->value);
			free((void *)cell->key);
			free(cell);
			ht->count--;
			return (true);
		}
		prev = cell;
		cell = cell->next;
	}
	return (false);
}

void	hashtable_destroy(t_hashtable *ht)
{
	size_t		i;
	t_ht_item	*cell;
	t_ht_item	*tmp;

	i = 0;
	while (i < ht->size)
	{
		cell = ht->items[i];
		while (cell)
		{
			tmp = cell;
			cell = cell->next;
			ht->deletef(tmp->value);
			free((void *)tmp->key);
			free(tmp);
		}
		i++;
	}
	free(ht->items);
	free(ht);
}

t_ht_item	*hashtable_find(\
	t_ht *ht, \
	t_hashtable_find f, \
	void *data
)
{
	size_t		i;
	t_ht_item	*cell;

	i = 0;
	while (i < ht->size)
	{
		cell = ht->items[i];
		while (cell)
		{
			if (f(cell->key, cell->value, data))
				return (cell);
			cell = cell->next;
		}
		i++;
	}
	return (NULL);
}
