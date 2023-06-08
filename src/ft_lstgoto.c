/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgoto.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:54:35 by martiper          #+#    #+#             */
/*   Updated: 2023/06/08 12:00:31 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	*Moves the list pointer to the top of the list.
 */
t_list	*ft_lstgoto_top(t_list **lst)
{
	if (!lst || !*lst)
		return (NULL);
	while ((*lst)->prev)
		*lst = (*lst)->prev;
	return (*lst);
}

/*
	*Moves the list pointer to the end of the list.
 */
t_list	*ft_lstgoto_end(t_list **lst)
{
	if (!lst || !*lst)
		return (NULL);
	while ((*lst)->next)
		*lst = (*lst)->next;
	return (*lst);
}

/*
	*Moves the list pointer to the index of the list.
	*If the index is negative, it will move the pointer to the end of the list.
 */
t_list	*ft_lstgoto(t_list **lst, int index)
{
	int		i;

	if (!lst || !*lst)
		return (NULL);
	if (index < 0)
		return (ft_lstgoto_end(lst));
	i = 0;
	while (i < index && (*lst)->next)
	{
		*lst = (*lst)->next;
		i++;
	}
	return (*lst);
}
