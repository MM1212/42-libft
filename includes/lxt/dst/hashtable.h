/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:01:27 by martiper          #+#    #+#             */
/*   Updated: 2024/03/24 14:26:02 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_hashtable_item	t_hashtable_item;
typedef struct s_hashtable		t_hashtable;

typedef void					(*t_hashtable_foreach)(\
	const char *key, \
	void *value, \
	void *data \
);
typedef void					(*t_hashtable_delete)(\
	void *value \
);
typedef size_t					(*t_hashtable_hash)(\
	const char *key \
);
typedef bool					(*t_hashtable_add)(\
	t_hashtable *table, \
	const char *key, \
	void *value \
);
typedef bool					(*t_hashtable_set)(\
	t_hashtable *table, \
	const char *key, \
	void *value \
);
typedef void					*(*t_hashtable_get)(\
	t_hashtable *table, \
	const char *key \
);
typedef bool					(*t_hashtable_remove)(\
	t_hashtable *table, \
	const char *key \
);
typedef void					(*t_hashtable_destroy)(\
	t_hashtable *table \
);
typedef void					(*t_hashtable_foreach_m)(\
	t_hashtable *table, \
	t_hashtable_foreach f, \
	void *data \
);

struct s_hashtable_item
{
	const char			*key;
	void				*value;
	t_hashtable_item	*next;
	t_hashtable			*table;
};

struct s_hashtable
{
	t_hashtable_item		**items;
	size_t					size;
	size_t					count;
	size_t					item_size;
	t_hashtable_hash		hash;
	t_hashtable_delete		deletef;
	t_hashtable_foreach_m	foreach;
	t_hashtable_get			get;
	t_hashtable_add			add;
	t_hashtable_set			set;
	t_hashtable_remove		remove;
	t_hashtable_destroy		destroy;
};

# define HASHTABLE_DEFAULT_SIZE 61

void		hashtable_noop(void *value);
size_t		hashtable_joaat_hash(const char *key);
size_t		hashtable_djb2_hash(const char *key);

/*
** Create a new hashtable
** @param size: the size of the hashtable (should be a prime number)
** @param item_size: the size of the value to store
	(used for mem alloc in emplace method,
		needs to be a multiple of sizeof(int))
** @param hash: the hash function to use
** @param delete: the function to call when deleting an item
 */
t_hashtable	*hashtable_create(\
	size_t size, \
	t_hashtable_hash hash, \
	t_hashtable_delete delete_fn \
);

#endif
