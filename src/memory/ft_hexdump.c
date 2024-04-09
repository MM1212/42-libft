/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:19:29 by martiper          #+#    #+#             */
/*   Updated: 2024/04/09 11:31:43 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dump_ascii(void *ptr, size_t size, size_t dbpl)
{
	size_t	i;
	char	c;

	ft_printf("|");
	i = 0;
	while (i < size)
	{
		c = *((uint8_t *)ptr + i);
		if (ft_isprint(c))
			ft_printf("%c", c);
		else
			ft_printf(".");
		i++;
	}
	while (i < dbpl)
	{
		ft_printf(" ");
		i++;
	}
	ft_printf("|");
}

static void	dump_addr(void *ptr, size_t size, size_t dbpl)
{
	size_t	i;

	ft_printf("%016p", ptr);
	ft_printf("  ");
	i = 0;
	while (i < size)
	{
		if (i == dbpl / 2)
			ft_printf("  ");
		else if (i > 0)
			ft_printf(" ");
		ft_printf("%02x", *((uint8_t *)ptr + i));
		i++;
	}
	ft_printf("%*s", (dbpl - size) * 3 + (size < dbpl / 2 != 0), "");
	ft_printf("  ");
	dump_ascii(ptr, size, dbpl);
	ft_printf("\n");
}

void	ft_hexdump(void *ptr, size_t size, size_t dbpl)
{
	size_t	addresses;
	size_t	remaining;
	size_t	i;

	if (!ptr || !size || !dbpl)
		return ;
	addresses = size / dbpl;
	remaining = size % dbpl;
	i = 0;
	while (i < addresses)
	{
		dump_addr(ptr, dbpl, dbpl);
		ptr += dbpl;
		i++;
	}
	if (remaining)
		dump_addr(ptr, remaining, dbpl);
}
