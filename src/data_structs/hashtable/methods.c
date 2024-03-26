/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:31:10 by martiper          #+#    #+#             */
/*   Updated: 2024/03/26 23:06:19 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht_internal.h"
#include <libft.h>

t_ht_item	*hashtable_create_item(const void *key, void *value)
{
	t_ht_item	*item;

	item = ft_calloc(1, sizeof(t_ht_item));
	if (!item)
		return (NULL);
	item->key = key;
	item->value = value;
	return (item);
}

void	hashtable_foreach_item(\
	t_hashtable *ht, \
	t_hashtable_foreach fn, \
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
			fn(cell->key, cell->value, data);
			cell = cell->next;
		}
		i++;
	}
}

void	*hashtable_get_item(\
	t_hashtable *ht, \
	const void *key
)
{
	size_t		hash;
	t_ht_item	*cell;

	hash = ht->hash(key) % ht->size;
	cell = ht->items[hash];
	while (cell)
	{
		if (ht->cmp(cell->key, key) == 0)
			return (cell->value);
		cell = cell->next;
	}
	return (NULL);
}

bool	hashtable_add_item(\
	t_hashtable *ht, \
	const void *key, \
	void *value
)
{
	size_t		hash;
	t_ht_item	*cell;
	t_ht_item	*new;

	hash = ht->hash(key) % ht->size;
	cell = ht->items[hash];
	while (cell)
	{
		if (ht->cmp(cell->key, key) == 0)
			return (false);
		cell = cell->next;
	}
	cell = ht->items[hash];
	while (cell && cell->next)
		cell = cell->next;
	new = hashtable_create_item(key, value);
	if (!new)
		return (false);
	new->table = ht;
	if (!cell)
		ht->items[hash] = new;
	else
		cell->next = new;
	ht->count++;
	return (true);
}

bool	hashtable_set_item(\
	t_hashtable *ht, \
	const void *key, \
	void *value
)
{
	t_ht_item	*cell;
	size_t		hash;

	hash = ht->hash(key) % ht->size;
	cell = ht->items[hash];
	while (cell)
	{
		if (ht->cmp(cell->key, key) == 0)
		{
			if (ht->deletef)
				ht->deletef(cell->value, NULL);
			cell->value = value;
			return (true);
		}
		cell = cell->next;
	}
	return (hashtable_add_item(ht, key, value));
}
