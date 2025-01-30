#include <stdlib.h>
#include <stdio.h>

typedef struct s_map {
    char **grid;
    int rows;
    int cols;
    int collectibles;
    int exit;
    int player;
} t_map;

void exit_with_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

void validate_map(t_map *map) 
{
    if (map->player != 1 || map->exit != 1 || map->collectibles < 1)
        exit_with_error("Invalid map: Missing P/E/C");
}
