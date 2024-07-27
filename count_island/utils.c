#include "count_island.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_find_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_bzero(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_calloc(int len)
{
	char	*str;

	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_bzero(str, len);
	return (str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*bigboy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1)
	{
		bigboy = ft_calloc(ft_strlen(str2) + 1);
		if (!bigboy)
			return (NULL);
		while (str2[i])
		{
			bigboy[i] = str2[i];
			i++;
		}
		return (bigboy);
	}
	bigboy = ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!bigboy)
		return (NULL);
	while (str1[i])
	{
		bigboy[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		bigboy[i] = str2[j];
		i++;
		j++;
	}
	return (bigboy);
}
