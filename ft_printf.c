/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:36:23 by letnitan          #+#    #+#             */
/*   Updated: 2022/12/29 10:15:10 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

// C'EST UN BROUILLON

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	checkflag(va_list mandatory_argument, char c)
{
	int	counter;

	counter = 0;
	if mandatory_argument[i+1] == 'c'
		// counter =; putchar avec option compteur
	if mandatory_argument[i+1] == 's'
		// counter =; putstr avec compteur
	if mandatory_argument[i+1] == 'p'
		// counter =; putpointeur ?
	if mandatory_argument[i+1] == 'd'
		// counter =; putnbr
	if mandatory_argument[i+1] == 'i'
		// counter =; putnbr
	if mandatory_argument[i+1] == 'u'
		// counter =; putnbr unsigned
	if mandatory_argument[i+1] == 'x'
		// counter =; puthex
	if mandatory_argument[i+1] == 'X'
		// counter =;putHEX
	if mandatory_argument[i+1] == '%'
		// counter =; putpercentage
	return (counter);
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
			// counter = counter + putchar 
			i++;
		}
	}
	va_end(args)
	return (counter);
}

int	main()
{
	ft_printf("number %i %i hello", 42, 53);
}