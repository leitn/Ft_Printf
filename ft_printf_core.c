/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:36:23 by letnitan          #+#    #+#             */
/*   Updated: 2022/12/30 09:51:45 by letnitan         ###   ########.fr       */
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

int	ft_nbrcounter(long long nb, int base_len)
{
	int	counter;

	counter = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
	{
		nb *= -1;
		counter++;
	}
	while(nb > 0)
	{
		nb = nb/base_len;
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
	return(ft_nbrcounter(n, base_len));
}

int	ft_ptrlen(unsigned long long n, int base_len)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base_len;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_pointer(unsigned long long ptr, char *base, int trigger)
{
	unsigned long long	nbr;

	nbr = ptr;
	if (nbr == 0)
		return (write(1, "(nil)", 5));
	if (trigger == 0)
		write(1, "0x", 2);
	if (nbr > 15)
		ft_pointer(nbr / 16, base, 1);
	ft_putchar(base[nbr % 16]);
	return (ft_ptrlen(nbr, ft_strlen(base)) + 2);
}

int	checkflag(va_list args, const char c)
{
	int	print_counter;

	print_counter = 0;
	if (c == 'c')
		return(ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return(ft_putstr(va_arg(args, char*)));
	else if (c == 'p')
		return(ft_pointer(va_arg(args, unsigned long long), "0123456789abcdef", 0));
	else if ((c == 'd') || (c == 'i'))
		return(ft_putnbr((long long)va_arg(args, int), "0123456789", 1));
	else if (c == 'u')
		return(ft_putnbr(va_arg(args, unsigned int), "0123456789", 0));
	else if (c == 'x')
		return(ft_putnbr(va_arg(args, unsigned int), "0123456789abcdef", 1));
	else if (c == 'X')
		return(ft_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF", 1));
	else if (c == '%')
		return(ft_putchar('%'));
	return (0);
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
	return (counter);
}

//-----------------------------------------TEST HEXA----------------------------------------
// int	main()
// {
// 	long long	n;
// 	int i;

// 	n = 31;
// 	i = 15;
// 	printf("The test will begin :\n\n");
// 	ft_printf("I. Number : %X\n", n);
// 	ft_printf("\nII. Number : %X\n", i);
// 	printf("\n\n-------------------------------");
// 	printf("\n\nI. The expected print was : \"1F\"\nThe counter should print %li.", ft_strlen("I. Number : 1F\n"));
// 	printf("\n\nII. The expected print was : \"F\"\nThe counter should print %li.", ft_strlen("\nII. Number : F\n"));
// 	printf("\n\nDone.");
// }

//-------------------------------------TEST GRANDS CHIFFRES--------------------------------------
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

//-------------------------------------TEST POINTEUR--------------------------------------
// int	main()
// {
// 	void	*p;
// 	char	a;

// 	a = 'H';
// 	p = &a;
// 	printf("The test will begin :\n\n");
// 	ft_printf("Pointer : %p\n", p);
// 	printf("\n\nReal printf Comparaison : %p", p);
// 	printf("\n\nDone.");
// }