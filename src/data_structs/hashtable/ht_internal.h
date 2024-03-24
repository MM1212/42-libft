/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_internal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:29:54 by martiper          #+#    #+#             */
/*   Updated: 2024/03/24 17:26:11 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HT_INTERNAL_H
# define HT_INTERNAL_H

# include <stdbool.h>
# include "lxt/dst/hashtable.h"

typedef t_hashtable			t_ht;
typedef t_hashtable_item	t_ht_item;

t_ht_item	*hashtable_create_item(const char *key, void *value);
void		hashtable_foreach_item(\
	t_hashtable *table, \
	t_hashtable_foreach f, \
	void *data);
void		*hashtable_get_item(t_hashtable *table, const char *key);
bool		hashtable_add_item(\
	t_hashtable *table, \
	const char *key, \
	void *value \
);
bool		hashtable_set_item(\
	t_hashtable *table, \
	const char *key, \
	void *value \
);
bool		hashtable_remove_item(t_hashtable *table, const char *key);
void		hashtable_destroy(t_hashtable *table);
t_ht_item	*hashtable_find(\
	t_hashtable *table, \
	t_hashtable_find f, \
	void *data \
);
#endif
