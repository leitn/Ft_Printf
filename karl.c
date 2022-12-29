#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long long n, char *base)
{
	unsigned long long	nbr;
	size_t				base_len;

	base_len = strlen(base);
	nbr = n;
	if (n < 0)
	{
		nbr = n * -1;
		ft_putchar('-');
	}
	if (nbr > base_len - 1)
    {
        printf("\nnbr before = %lli\n", nbr);
		ft_putnbr(nbr / base_len, base);
        printf("\nnbr after = %lli\n", nbr);
    }
	ft_putchar(base[nbr % base_len]);
	return (5);
}


int main(void)
{
    char *base;

    base = "0123456789BACDEF";

    ft_putnbr(31, base);
    return (0);
}