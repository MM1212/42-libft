/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:53:41 by martiper          #+#    #+#             */
/*   Updated: 2024/03/25 18:19:37 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mods.h"
#include <stdarg.h>

char	*build_format_buffer(t_date_flags flags, const t_date_mod *mod)
{
	static char	format_buff[256];
	char		mod_str[2];
	char		padding[256];

	ft_bzero(format_buff, sizeof(format_buff));
	ft_strlcat(format_buff, "%", sizeof(format_buff));
	if (flags.zero)
		ft_strlcat(format_buff, "0", sizeof(format_buff));
	if (flags.plus)
		ft_strlcat(format_buff, "+", sizeof(format_buff));
	ft_sprintf(padding, 256, "%d", mod->padding);
	ft_strlcat(format_buff, padding, sizeof(format_buff));
	mod_str[0] = mod->format[0];
	mod_str[1] = 0;
	ft_strlcat(format_buff, mod_str, sizeof(format_buff));
	return (format_buff);
}

void	printf_mod(char **buffer, size_t size, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	*buffer += ft_vsprintf(*buffer, size, format, args);
	va_end(args);
}

t_date_flags	parse_flags(const char *format, size_t *idx)
{
	t_date_flags	flags;

	ft_bzero(&flags, sizeof(flags));
	flags.zero = true;
	while (format[*idx] && ft_strchr("_0+^#", format[*idx]))
	{
		if (format[*idx] == '_')
		{
			ft_bzero(&flags, sizeof(flags));
			flags.space = true;
		}
		else if (format[*idx] == '0')
		{
			ft_bzero(&flags, sizeof(flags));
			flags.zero = true;
		}
		else if (format[*idx] == '+')
		{
			ft_bzero(&flags, sizeof(flags));
			flags.plus = true;
		}
		(*idx)++;
	}
	return (flags);
}
