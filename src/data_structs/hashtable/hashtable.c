/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:53:58 by martiper          #+#    #+#             */
/*   Updated: 2024/03/26 23:28:23 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht_internal.h"
#include <libft.h>
#include <stdlib.h>

t_hashtable	*hashtable_create(\
	size_t size, \
	t_hashtable_hash hash, \
	t_hashtable_cmp cmp, \
	t_hashtable_delete delete_fn \
)
{
	t_hashtable	*ht;

	ht = ft_calloc(1, sizeof(t_hashtable));
	if (!ht)
		return (NULL);
	ht->size = size;
	ht->hash = hash;
	ht->deletef = delete_fn;
	ht->cmp = cmp;
	ht->items = ft_calloc(size, sizeof(t_ht_item *));
	if (!ht->items)
	{
		free(ht);
		return (NULL);
	}
	ht->add = hashtable_add_item;
	ht->set = hashtable_set_item;
	ht->get = hashtable_get_item;
	ht->remove = hashtable_remove_item;
	ht->destroy = hashtable_destroy;
	ht->foreach = hashtable_foreach_item;
	ht->find = hashtable_find;
	ht->clear = hashtable_clear;
	return (ht);
}
