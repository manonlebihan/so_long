#include "so_long.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

typedef struct map_s {
	char	**map;
	int	nb_lines;
	int	line_len; // TODO: ca pourra servir...
	int	flood_fill_collectible;
	int	flood_file_exit;
} map_t;

// je ne sais pas si tu as ecrit un ft_realloc() dans ta libft, si ce n'est pas le cas, en voici une rapide adaptation
// ca permet d'agrandir une zone mémoire, on l'utilise dans notre cas pour ajouter une nouvelle chaine de caracheres au tableau de la map qu'on est en train ed constauire
void *ft_realloc_str(void *oldptr, int oldlen, int newlen)
{
	if (newlen == 0)
	{
		free(oldptr);
		return NULL;
	}
	else if (!oldptr)
		return malloc(newlen * sizeof(char *));
	else if (newlen <= oldlen)
		return oldptr;
	else {
		void *newptr = malloc(newlen * sizeof(char *));
		if (newptr)
		{
			memcpy(newptr, oldptr, oldlen * sizeof(char *)); // ICI il faudra utiliser ft_memcpy()
			free(oldptr);
		}
		return newptr;
	}
}

void	load_memory_map(map_t *m, int fd)
{
	char	*line;
	int	len;

	m->map = NULL;
	m->nb_lines = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line) 
		{
			len = (int)strlen(line);
			if (line[len - 1] == '\n')
				line[--len] = '\0';
			if (m->nb_lines == 0)
				m->line_len = len;
			m->map = ft_realloc_str(m->map, m->nb_lines, m->nb_lines + 1);
			m->map[m->nb_lines] = line;
			(m->nb_lines)++;
		}
	}
}

void	free_memory_map(map_t m) 
{
	int	i;
	
	i = 0;
	while (i < m.nb_lines) 
	{
		free(m.map[i]);
		i++;
	}
	free(m.map);
}

int    duplicate_map(map_t m, map_t *dup) {
	int	i;

	dup->nb_lines = m.nb_lines;
	dup->line_len = m.line_len;
	dup->map = (char **)malloc(m.nb_lines * sizeof(char *));
	if (dup->map == NULL) {
		return 0;
	}
	i = 0;
	while (i < m.nb_lines) 
	{
		dup->map[i] = strdup(m.map[i]);
		if (dup->map[i] == NULL) {
			while(i)
				free(dup->map[--i]);
			free(dup->map);
			return 0;
		}
		i++;
	}
	return 1;
}

void	flood_fill(map_t *m, int x, int y) {
	if (m->map[y][x] != '1') {
		if (m->map[y][x] == 'C')
			m->flood_fill_collectible++;
		if (m->map[y][x] == 'X')
			m->flood_file_exit++;
		m->map[y][x] = '1';
		flood_fill(m, x+1, y);
		flood_fill(m, x, y-1);
		flood_fill(m, x-1, y);
		flood_fill(m, x, y+1);
	}
}

int	main()
{
	map_t	m;
	map_t	dup;
	int	fd;
	int	i;

	fd = open("map.txt", O_RDONLY);
	load_memory_map(&m, fd);
	close(fd);
	
	printf("nb_lignes    = %d \n", m.nb_lines);
	printf("taille ligne = %d \n", m.line_len);

	// affiche la map
	i = 0;
	while (i < m.nb_lines) 
	{
		printf("%s\n", m.map[i]);
		i++;
	}

	printf("\n");

	if (duplicate_map(m, &dup)) {
		// affiche la map dupliquee
		i = 0;
		while (i < dup.nb_lines) 
		{
			printf("%s\n", dup.map[i]);
			i++;
		}
		dup.flood_fill_collectible = 0;
		dup.flood_file_exit = 0;

		// flood_fill sur le duplicate
		flood_fill(&dup, 15, 1);
		printf("%d\n", dup.flood_fill_collectible);
		printf("%d\n", dup.flood_file_exit);
		if (dup.flood_fill_collectible == 1 && dup.flood_file_exit == 1) {
			printf("C'est OK!\n");
		}

		// libere la memoire pour la map dupliquee
		free_memory_map(dup);
	}

	// libere la memoire pour la map 
	free_memory_map(m);
}

/* COMPILATION :

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c

*/
