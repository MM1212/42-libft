/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:41:36 by martiper          #+#    #+#             */
/*   Updated: 2023/11/15 21:43:28 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strjoin_mult(size_t count, ...)
{
	char	*join;
	char	*tmp;
	va_list	args;

	va_start(args, count);
	join = ft_strdup("");
	while (count--)
	{
		tmp = join;
		join = ft_strjoin(join, va_arg(args, char *));
		free(tmp);
	}
	va_end(args);
	return (join);
}
