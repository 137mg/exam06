#include "island.h"

static void	fill_island(char *str, int i, int len, char c)
{
	int	j;

	str[i] = c;
	j = i - len;
	if (j >= 0 && str[j] == 'X')
		fill_island(str, j, len, c);
	j = i - 1;
	if (j >= 0 && str[j] == 'X')
		fill_island(str, j, len, c);
	j = i + 1;
	if (j < ft_strlen(str) && str[j] == 'X')
		fill_island(str, j, len, c);
	j = i + len;
	if (j < ft_strlen(str) && str[j] == 'X')
		fill_island(str, j, len, c);
}


void	island(char *str)
{
	char	c;
	int		len;
	int		i;

	c = '0';
	len = ft_find_nl(str) + 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'X')
		{
			fill_island(str, i, len, c);
			c++;
		}
		i++;
	}
	write(1, str, ft_strlen(str));
}
