/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:36:23 by letnitan          #+#    #+#             */
/*   Updated: 2022/12/29 22:25:50 by letnitan         ###   ########.fr       */
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putnbr_counter(long long nb)
{
	int	counter;

	counter = 0;
	if (nb < 0)
	{
		nb *= -1;
		counter++;
	}
	while(nb > 0)
	{
		nb = nb/10;
		counter++;
	}
	return(counter);
}

int	ft_putnbr(long long n, char *base, int	trigger)
{
	unsigned long long	nbr;
	size_t				base_len;

	base_len = ft_strlen(base);
	nbr = n;
	if (n < 0 && trigger == 1)
	{
		nbr = n * -1;
		ft_putchar('-');
	}
	if (nbr > base_len - 1)
		ft_putnbr(nbr / base_len, base, 0);
	ft_putchar(base[nbr % base_len]);
	return(putnbr_counter(n));
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
		print_counter = ft_putnbr(va_arg(args, long long), "0123456789", 1);
	else if (c == 'i')
		print_counter = ft_putnbr(va_arg(args, int), "0123456789", 1);
	else if (c == 'u')
		print_counter = ft_putnbr(va_arg(args, int), "0123456789", 0);
	else if (c == 'x')
		print_counter = ft_putnbr(va_arg(args, int), "0123456789abcdef", 1);
	else if (c == 'X')
		print_counter = ft_putnbr(va_arg(args, int), "0123456789ABCDEF", 1);
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
	long long	n;
	int i;

	n = -4294967295895;
	i = 5879;
	printf("The test will begin :\n\n");
	ft_printf("I. Number : %d\n", n);
	ft_printf("\nII. Number : %d\n", i);
	printf("\n\n-------------------------------");
	printf("\n\nI. The expected print was : \"-4294967295895\"\nThe counter should print %li.", ft_strlen("I. Number : -4294967295895\n"));
	printf("\n\nII. The expected print was : \"5879\"\nThe counter should print %li.", ft_strlen("\nII> Number : 5879\n"));
	printf("\n\nDone.");
}

// int	main()
// {
// 	long long	n;
// 	int i;

// 	n = -4294967295895;
// 	i = 5879;
// 	printf("The test will begin :\n\n");
// 	ft_printf("I. Number : %d\n", n);
// 	ft_printf("\nII. Number : %d\n", i);
// 	printf("\n\n-------------------------------");
// 	printf("\n\nI. The expected print was : \"-4294967295895\"\nThe counter should print %li.", ft_strlen("I. Number : -4294967295895\n"));
// 	printf("\n\nII. The expected print was : \"5879\"\nThe counter should print %li.", ft_strlen("\nII> Number : 5879\n"));
// 	printf("\n\nDone.");
// }