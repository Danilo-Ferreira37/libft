#include "libft.h"

static int	base_verification(char *base)
{
	int i;
	int j;

	i =0;
	while(base[i])
	{		
		if(base[i] == '+' || base[i] == '-')
			return(1);
		j = i + 1;
		while(base[j])
		{
			if(base[j] == base[i])
				return(1);
			j++;
		}
		i++;
	}
	if(i < 2)
		return(1);
	return(0);
}

void    ft_putnbr_base(int nbr, char *base)
{
	long nb;
	long base_len;

	nb = nbr;
	if(base_verification(base))
		return;
	base_len = ft_strlen(base);
	if(nb < 0)
	{
		write(1,"-", 1);
		nb *= -1;
	}
	if(nb >= base_len)
		ft_putnbr_base(nb / base_len, base);
	write(1, &base[nb % base_len], 1);
}

/* int main()
{
	int nbr;
	nbr = -200088;
	char *base = "123456789ABCDEF";
	ft_putnbr_base(nbr, base);
	write(1, "\n", 1);
	return(0);
} */
