#include "island.h"

char	*read_file(int fd)
{
	char	*content;
	char	*buffer;
	char	*tmp;
	int		ret;

	content = NULL;
	buffer = ft_calloc(LINE_LEN + 1);
	if (!buffer)
		return (NULL);
	ret = read(fd, buffer, LINE_LEN);
	while (ret > 0)
	{
		tmp = ft_strjoin(content, buffer);
		if (content)
			free(content);
		if (!tmp)
		{
			free(buffer);
			return (NULL);
		}
		content = tmp;
		ft_bzero(buffer, LINE_LEN + 1);
		ret = read(fd, buffer, LINE_LEN);
	}
	free(buffer);
	if (ret == -1)
	{
		if (content)
			free(content);
		return (NULL);
	}
	return (content);
}

int	check_file(char *content)
{
	int	len;
	int	nl;
	int	i;

	len = 0;
	nl = 0;
	i = 0;
	while (content[i])
	{
		if (!(content[i] == '.'|| content[i] == 'X' || content[i] == '\n'))
			return (-1);
		if (content[i] == '\n')
		{
			if (len == 0)
				len = i + 1;
			else if (i - nl != len)
				return (-1);
			nl = i;
		}
		i++;
	}
	if (content[i - 1] != '\n')
		return (-1);
	return (0);
}

int	exit_error(void)
{
	write(1, "\n", 1);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*content;
	int		fd;

	if (argc != 2)
		return (exit_error());
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (exit_error());
	content = read_file(fd);
	close(fd);
	if (!content)
		return (exit_error());
	if (check_file(content) == -1)
	{
		free(content);
		return (exit_error());
	}
	island(content);
	free(content);
	return (0);
}
