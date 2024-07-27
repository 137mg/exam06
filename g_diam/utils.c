#include "g_diam.h"

int	ft_count_dash(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	return (n);
}

int	ft_skip(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	pow;
	int	n;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	pow = 1;
	n = 0;
	while (i >= 0)
	{
		n += (str[i] - '0') * pow;
		pow *= 10;
		i--;
	}
	return (n);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
		return;
	}
	c = n + '0';
	write(1, &c, 1);
}
