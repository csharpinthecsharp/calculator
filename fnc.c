#include <unistd.h>

void ft_putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	char c;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int ft_getnb(char *arg, int *s)
{
    int i = 0;
    int nb = 0;

    if (arg[0] == '-')
    {
        *s = -1;
        i++;
    }
    while (arg[i])
    {
        if (arg[i] >= '0' && arg[i] <= '9')
        {
            nb = nb * 10 + (arg[i] - '0');
        }
        i++;

    }

    return (nb * (*s));
}