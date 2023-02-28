/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-biha <mle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:32:05 by mle-biha          #+#    #+#             */
/*   Updated: 2023/02/28 11:32:06 by mle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**read_and_stock_map(char *filename)
{
	char	*line;
	int		len;
	int		fd;
	char	**tab;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("File does not exist.", 2);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	len = ft_strlen(line);
	tab = malloc(sizeof(char *) * len);
	if (tab == NULL)
	{
		free(line);
		close(fd);
		ft_putendl_fd("Something unsual happened...", 2);
		exit(EXIT_FAILURE);
	}
	tab = line;
	free(line);
	close(fd);
	return (tab);
}
