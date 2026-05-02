/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:24:03 by dosorio-          #+#    #+#             */
/*   Updated: 2026/01/07 21:51:16 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_format(char c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		counter += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		counter += ft_print_adress(va_arg(args, void *), 16,
				"0123456789abcdef");
	else if (c == 'd' || c == 'i')
		counter += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		counter += ft_base(va_arg(args, unsigned int), 10, "0123456789");
	else if (c == 'x')
		counter += ft_base(va_arg(args, unsigned int), 16, "0123456789abcdef");
	else if (c == 'X')
		counter += ft_base(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
	else if (c == '%')
		counter += ft_putchar_fd('%', 1);
	else
		return (-1);
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	counter = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			counter += handle_format(s[++i], args);
		else
			counter += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	if (counter < 0)
		return (-1);
	return (counter);
}

/* int	main(void)
{
	int		i;
	char	c;
	char	*s;

	i = 200;
	c = 'D';
	s = "DANILO";
	ft_printf(" %d \n", i);
	ft_printf(" %c \n", c);
	ft_printf(" %s \n\n\n", s);
	return (0);
	return (0);
} */
