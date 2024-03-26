/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:52:10 by martiper          #+#    #+#             */
/*   Updated: 2024/03/26 20:00:56 by martiper         ###   ########.fr       */
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

static t_list	*partition(\
	t_list *low, \
	t_list *high, \
	t_lst_cmp2 cmp, \
	void *data \
)
{
	t_list	*i;
	t_list	*j;

	i = low->prev;
	j = low;
	while (j != high)
	{
		if (cmp(j->content, high->content, data) < 0)
		{
			if (!i)
				i = low;
			else
				i = i->next;
			swap(&(i->content), &(j->content));
		}
		j = j->next;
	}
	if (!i)
		i = low;
	else
		i = i->next;
	swap(&(i->content), &(high->content));
	return (i);
}

static void	quick_sort(\
	t_list *low, \
	t_list *high, \
	t_lst_cmp2 cmp, \
	void *data \
)
{
	t_list	*pivot;

	if (high == NULL || low == high || low == high->next)
		return ;
	pivot = partition(low, high, cmp, data);
	quick_sort(low, pivot->prev, cmp, data);
	quick_sort(pivot->next, high, cmp, data);
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
