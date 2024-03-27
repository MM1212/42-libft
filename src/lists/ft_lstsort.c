/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:52:10 by martiper          #+#    #+#             */
/*   Updated: 2024/03/27 18:22:27 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_mid_node(t_list *node)
{
	t_list	*slow;
	t_list	*fast;

	slow = node;
	fast = node;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow);
}

static t_list	*merge(\
	t_list *left, \
	t_list *right, \
	t_lst_cmp2 cmp, \
	void *data \
)
{
	if (!left)
		return (right);
	if (!right)
		return (left);
	if (cmp(left->content, right->content, data) <= 0)
	{
		left->next = merge(left->next, right, cmp, data);
		left->next->prev = left;
		left->prev = NULL;
		return (left);
	}
	else
	{
		right->next = merge(left, right->next, cmp, data);
		right->next->prev = right;
		right->prev = NULL;
		return (right);
	}
}

static t_list	*merge_sort(t_list *node, t_lst_cmp2 cmp, void *data)
{
	t_list	*mid;
	t_list	*next;
	t_list	*left;
	t_list	*right;

	if (!node || !node->next)
		return (node);
	mid = get_mid_node(node);
	next = mid->next;
	mid->next = NULL;
	next->prev = NULL;
	left = merge_sort(node, cmp, data);
	right = merge_sort(next, cmp, data);
	return (merge(left, right, cmp, data));
}

t_list	*ft_lstsort2(t_list *lst, t_lst_cmp2 cmp, void *data)
{
	if (!lst || !lst->next)
		return (lst);
	return (merge_sort(lst, cmp, data));
}

t_list	*ft_lstsort(t_list *lst, t_lst_cmp fn)
{
	return (ft_lstsort2(lst, (t_lst_cmp2)fn, NULL));
}
