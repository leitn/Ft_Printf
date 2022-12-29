/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:06:00 by letnitan          #+#    #+#             */
/*   Updated: 2022/12/29 20:06:30 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Je ne l'avais pas fait en piscine alors let's go. 
#include <stdio.h>


void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < 16)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 16);
		ft_putnbr(n % 16);
	}
}


void	main()
{
	int	n;
	char	*base;
	
	n = 15;
	base = "poneyvif";

	printf("p = 0\no = 1\nn = 2\ne = 3\ny = 4\nv = 5\ni = 6\nf = 7\n");
	printf("8 = op | 9 = oo | 10 = on | 11 = oe | 12 = oy | 13 = ov | 14 = oi | 15 = of\n");
	printf("16 = np | 17 = no | 18 = nn | 19 = ne | 20 = ny | 21 = nv | 22 = ni | 23 = nf\n");
	printf("24 = ep | 25 = eo | 26 = en | 27 = ee | 28 = ey | 29 = ev | 30 = ei | 31 = ef\n");
	printf("\n\nTest Begins : 15 in poneyvif : \n\n\n");
	ft_putnbr_base(n, base);
}