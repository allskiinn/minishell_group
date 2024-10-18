/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:39:24 by aliberal          #+#    #+#             */
/*   Updated: 2024/07/16 12:06:27 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_type(const char *input, va_list arg)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += ft_print_char((char)va_arg(arg, int));
	else if (*input == 's')
		i += ft_print_string(va_arg(arg, char *));
	else if (*input == 'p')
		i += ft_print_pointer(va_arg(arg, void *));
	else if (*input == 'd' || *input == 'i')
		i += ft_print_int(va_arg(arg, int));
	else if (*input == 'u')
		i += ft_print_unsigned(va_arg(arg, unsigned int));
	else if (*input == 'x')
		i += ft_print_hex(va_arg(arg, unsigned int), 87);
	else if (*input == 'X')
	{
		i += ft_print_hex(va_arg(arg, unsigned int), 55);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX", *format))
				i += check_type(format, args);
			else if (*format == '%')
				i += ft_print_char('%');
		}
		else
			i = i + ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (i);
}
