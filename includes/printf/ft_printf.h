/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:06:47 by martiper          #+#    #+#             */
/*   Updated: 2023/11/15 22:18:17 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_vprintf(const char *format, va_list args);
int	ft_fprintf(int fd, const char *format, ...);
int	ft_vfprintf(int fd, const char *format, va_list args);
int	ft_sprintf(char *str, size_t size, const char *format, ...);
int	ft_vsprintf(char *str, size_t size, const char *format, va_list args);

#endif
