/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:36:23 by letnitan          #+#    #+#             */
/*   Updated: 2022/12/29 11:23:39 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// C'EST UN BROUILLON

int	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	return(i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	unsigned int	n;
	int	counter;

	n = nb;
	counter = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		n *= -1;
		counter = 1;
	}
	if (n < 10)
	{
		counter += ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return(counter);
}

int	checkflag(va_list args, const char c)
{
	int	print_counter;

	print_counter = 0;
	if (c == 'c')
		print_counter += ft_putchar(va_arg(args, int));
	else if (c == 's')
		print_counter = ft_putstr(va_arg(args, char*));
	// else if (c == 'p')
	// 	// counter =; putpointeur ?
	else if (c == 'd')
		print_counter = ft_putnbr(va_arg(args, int));
	// else if (c == 'i')
	// 	// counter =; putnbr
	// else if (c == 'u')
	// 	// counter =; putnbr unsigned
	// else if (c == 'x')
	// 	// counter =; puthex
	// else if (c == 'X')
	// 	// counter =;putHEX
	else if (c == '%')
		print_counter = ft_putchar('%');
	return (print_counter);
}

int	ft_printf(const char *mandatory_argument, ...)
{
	va_list	args;
	int	counter;
	int	i;
	va_start(args, mandatory_argument);
	
	counter = 0;
	i = 0;
	while (mandatory_argument[i])
	{
		if(mandatory_argument[i] == '%')
		{
			counter = counter + checkflag(args, mandatory_argument[i + 1]);
			i++;
		}
		else
		{
			counter += ft_putchar(mandatory_argument[i]);
		}
		i++;
	}
	va_end(args);
	printf("\nCounter : %i\n", counter);
	return (counter);
}

int	main()
{
	int	n;

	n = 4588;
	printf("The test will begin :\n\n");
	ft_printf("Number : %d", n);
	printf("\nThe expected print was : \"45\"");
	printf("\nDone.");
}