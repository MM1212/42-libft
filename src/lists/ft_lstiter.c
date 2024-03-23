/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:19:32 by mm                #+#    #+#             */
/*   Updated: 2024/03/23 21:37:31 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, t_lst_iter f)
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	ft_lstiter2(t_list *lst, t_lst_iter2 f, void *data)
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content, data);
		lst = lst->next;
	}
}
