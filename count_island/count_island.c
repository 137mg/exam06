#include "count_island.h"

void	count_island(char *str)
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
			str[i] = check_env(str, i, len);
			if (str[i] == 'Y')
			{
				str[i] = c;
				c++;
			}
			reset_str(str);
		}
		i++;
	}
}

char	check_env(char *str, int i, int len)
{
	int	j;

	str[i] = 'Y';
	j = i - len;
	if (j >= 0)
	{
		if (str[j] >= '0' && str[j] <= '9')
			return (str[j]);
		if (str[j] == 'X')
		{
			str[j] = check_env(str, j, len);
			if (str[j] != 'Y')
				return (str[j]);
		}
	}
	j = i - 1;
	if (j >= 0)
	{
		if (str[j] >= '0' && str[j] <= '9')
			return (str[j]);
		if (str[j] == 'X')
		{
			str[j] = check_env(str, j, len);
			if (str[j] != 'Y')
				return (str[j]);
		}
	}
	j = i + 1;
	if (j < ft_strlen(str))
	{
		if (str[j] >= '0' && str[j] <= '9')
			return (str[j]);
		if (str[j] == 'X')
		{
			str[j] = check_env(str, j, len);
			if (str[j] != 'Y')
				return (str[j]);
		}
	}
	j = i + len;
	if (j < ft_strlen(str))
	{
		if (str[j] >= '0' && str[j] <= '9')
			return (str[j]);
		if (str[j] == 'X')
		{
			str[j] = check_env(str, j, len);
			if (str[j] != 'Y')
				return (str[j]);
		}
	}
	return ('Y');
}

void	reset_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'Y')
			str[i] = 'X';
		i++;
	}
}