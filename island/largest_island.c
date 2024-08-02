#include "island.h"

static void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

static int	find_size(char *str, int i, int len)
{
	int	size;
	int	j;

	str[i] = 'Y';
	size = 1;
	j = i - len;
	if (j >= 0 && str[j] == 'X')
		size += find_size(str, j, len);
	j = i - 1;
	if (j >= 0 && str[j] == 'X')
		size += find_size(str, j, len);
	j = i + 1;
	if (j < ft_strlen(str) && str[j] == 'X')
		size += find_size(str, j, len);
	j = i + len;
	if (j < ft_strlen(str) && str[j] == 'X')
		size += find_size(str, j, len);
	return (size);
}


void	island(char *str)
{
	int	maxsize;
	int	size;
	int	len;
	int	i;

	maxsize = 0;
	len = ft_find_nl(str) + 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'X')
		{
			size = find_size(str, i, len);
			if (size > maxsize)
				maxsize = size;
		}
		i++;
	}
	ft_putnbr(maxsize);
	write(1, "\n", 1);
}
