#include "count_island.h"

char	*read_file(int fd, char *content)
{
	int	ret;

	content = malloc(sizeof(char) * 1000);
	if (!content)
		return (NULL);
	ret = read(fd, content, 999);
	if (ret == 0 || ret == -1)
	{
		free(content);
		return (NULL);
	}
	return (content);
}

int	check_file(char *content)
{
	int	nl1;
	int	nl2;
	int	len;
	int	i;

	nl1 = find_nl(content);
	if (nl2 == -1)
		return (-1);
	len = nl1;
	i = 0;
	while (content[i])
	{
		i++;
	}
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
	return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (exit_error());
	content = NULL;
	content = read_file(fd, content);
	close(fd);
	if (!content)
		return (exit_error());
	if (check_file(content) == -1)
	{
		free(content);
		return (exit_error());
	}
	count_island(content);
	write(1, content, ft_strlen(content));
	free(content);
	return (0);
}
