#include "fnc.c"

int main(int argc, char *argv[])
{
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
	x = ft_getnb(argv[1], &sign);
	/*Loop to get the second number*/
	y = ft_getnb(argv[3], &sign);

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
