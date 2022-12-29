/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:36:23 by letnitan          #+#    #+#             */
/*   Updated: 2022/12/29 09:07:51 by letnitan         ###   ########.fr       */
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

char	checkflag(mandatory_argument, i)
{
	if mandatory_argument[i+1] == 'c'
		return ('c');
	if mandatory_argument[i+1] == 's'
		return ('s');
	if mandatory_argument[i+1] == 'p'
		return ('p');
	if mandatory_argument[i+1] == 'd'
		return ('d');
	if mandatory_argument[i+1] == 'i'
		return ('i');
	if mandatory_argument[i+1] == 'u'
		return ('u');
	if mandatory_argument[i+1] == 'x'
		return ('x');
	if mandatory_argument[i+1] == 'X'
		return ('X');
	if mandatory_argument[i+1] == '%'
		return ('%');
	else
		return (0);
}

int	ft_printf(const char *mandatory_argument, ...)
{
	va_list	args;
	va_start(args, mandatory_argument);
	
	va_end(args)
	return 0;
}

int	main()
{
	ft_printf("number %i %i hello", 42, 53);
}