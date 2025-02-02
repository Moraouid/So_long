#ifndef SO_LONG_H
#define SO_LONG_H

#include "/usr/include/minilibx-linux/mlx.h"
#include "../libft/get_next_line/get_next_line.h"
#include "../libft/libft/libft.h"
#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>      
#include <stdio.h>     
#include <string.h> 

#define TILE_SIZE 32

typedef struct s_point {
    int x;
    int y;
} t_point;

typedef struct s_map {
    char **data; 
    int rows;        
    int cols;        
    t_point player;  
    int collectibles;
    int exit;          
} t_map;

void exit_with_error(char *message);
void parse_map(char *file, t_map *map);
void validate_map(t_map *map);
void bfs(t_map *map, t_point start);

#endif
