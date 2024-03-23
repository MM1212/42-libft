/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:19:32 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 21:29:57 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, t_lst_find f, void* data)
{
	if (!f)
		return (NULL);
	while (lst)
	{
		if (f(lst->content, data))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
