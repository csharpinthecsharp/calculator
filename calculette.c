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

int main(int argc, char *argv[])
{
	int i = 0;
	int sign = 1;
	char operator; 
	int x = 0;
	int y = 0;
	/*Check if the pattern is of three args (3 + 3)*/
	if (argc != 4)
	{
		ft_putstr("We expect 3 arguments");
		return (0);
	}
	/*Check if operator section is what is supposed to be (+, -, /, *)*/
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putstr("Argument 2 is supposed to have 1 character");
		return (0);
	}
	else
	{
		if (argv[2][0] != '+'
			&& argv[2][0] != '-'
			&& argv[2][0] != '*'
			&& argv[2][0] != '/')
		{
			ft_putstr("Argument 2 is not a expected operator (+, -, /, *)");
			return (0);
		}
		else
		{
			operator = argv[2][0];	
		}
		       	       
	}
	/*Loop to get the first number*/
	while (argv[1][i] != '\0')
	{
		/*Check if it contains other thing than numbers (ASCII)*/
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			x = x * 10 + (argv[1][i] - '0');
			i++;
		}
		else if (argv[1][i] == '-')
		{
			sign *= -1;
			i++;
		}
		else
		{
			ft_putstr("Argument 1 seem to not be a number");
			return (0);
		}
	}
	x *= sign;
	sign = 1;
	i = 0;
	/*Loop to get the second number*/
	while (argv[3][i] != '\0')
	{
		if (argv[3][i] >= '0' && argv[3][i] <= '9')
		{
			y = y * 10 + (argv[3][i] - '0');
			i++;
		}
		else if (argv[3][0] == '-')
		{
			{
				sign *= -1;
				i++;
			}
		}
		else
		{
			ft_putstr("Argument 3 seem to not be a number");
		}
	}
	y *= sign;
	i = 0;

	if (x < 0 && y < 0)
	{
		x *= 1;
		y *= 1;
	}
	if (operator == '*')
	{
		ft_putnbr(x * y);
	}
	else if (operator == '/')
	{
		ft_putnbr(x / y);
	}
	else if (operator == '+')
	{
		ft_putnbr(x + y);
	}
	else if (operator == '-')
	{
		ft_putnbr(x - y);
	}
	return (0);
}
