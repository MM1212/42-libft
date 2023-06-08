/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:06:02 by mm                #+#    #+#             */
/*   Updated: 2023/06/08 11:59:50 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	*Free's up all the nodes in the list.
	*If the del function is provided, it will be called for each node's content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	if (!lst)
		return ;
	node = *lst;
	while (node)
	{
		if (del)
			del(node->content);
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*lst = NULL;
}

/*
	*It will try to go to the top of the list before clearing it.
 */
void	ft_lstfclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	node = ft_lstgoto_top(lst);
	while (node)
	{
		if (del)
			del(node->content);
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*lst = NULL;
}
