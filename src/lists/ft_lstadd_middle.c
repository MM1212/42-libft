/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_middle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:05:02 by martiper          #+#    #+#             */
/*   Updated: 2023/12/21 18:52:13 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_after(t_list **list, t_list *ref, t_list *node)
{
	t_list	*after_ref;

	if (!list || !node || !ref)
		return ;
	after_ref = ref->next;
	if (after_ref)
		after_ref->prev = node;
	node->next = after_ref;
	node->prev = ref;
	ref->next = node;
}

void	ft_lstadd_before(t_list **list, t_list *ref, t_list *node)
{
	t_list	*before_ref;

	if (!list || !node || !ref)
		return ;
	before_ref = ref->prev;
	if (before_ref)
		before_ref->next = node;
	node->prev = before_ref;
	node->next = ref;
	ref->prev = node;
	if (ref == *list)
		*list = node;
}
