/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:28:47 by martiper          #+#    #+#             */
/*   Updated: 2024/03/24 14:25:29 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht_internal.h"

size_t	hashtable_joaat_hash(const char *key)
{
	size_t	hash;
	size_t	i;

	hash = 0;
	i = 0;
	while (key[i])
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
		i++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}

size_t	hashtable_djb2_hash(const char *key)
{
	size_t	hash;
	size_t	i;

	hash = 5381;
	i = 0;
	while (key[i])
	{
		hash = ((hash << 5) + hash) + key[i];
		i++;
	}
	return (hash);
}

void	hashtable_noop(void *data)
{
	(void)data;
}
