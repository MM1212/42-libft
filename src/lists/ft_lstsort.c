/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:52:10 by martiper          #+#    #+#             */
/*   Updated: 2024/03/26 17:28:06 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(void **a, void **b)
{
	void	*t;

	t = *a;
	*a = *b;
	*b = t;
}

static t_list	*partition(t_list *l, t_list *h, t_lst_cmp2 cmp, void *data)
{
	t_list	*i;
	t_list	*j;

	i = l->prev;
	j = l;
	while (j != h)
	{
		if (cmp(j->content, h->content, data) < 0)
		{
			if (!i)
				i = l;
			else
				i = i->next;
			swap(&(i->content), &(j->content));
		}
		j = j->next;
	}
	if (!i)
		i = l;
	else
		i = i->next;
	swap(&(i->content), &(h->content));
	return (i);
}

static void	quick_sort(\
	t_list *left, \
	t_list *right, \
	t_lst_cmp2 cmp, \
	void *data \
)
{
	t_list	*pivot;

	if (right == NULL || left == right || left == right->next)
		return ;
	pivot = partition(left, right, cmp, data);
	quick_sort(left, pivot->prev, cmp, data);
	quick_sort(pivot->next, right, cmp, data);
}

void	ft_lstsort2(t_list *lst, t_lst_cmp2 cmp, void *data)
{
	t_list	*last;

	last = ft_lstlast(lst);
	quick_sort(lst, last, cmp, data);
}

void	ft_lstsort(t_list *lst, t_lst_cmp fn)
{
	ft_lstsort2(lst, (t_lst_cmp2)fn, NULL);
}
