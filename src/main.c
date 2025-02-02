/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:35:22 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/02 13:50:28 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/get_next_line/get_next_line.h"
#include "../libft/libft/libft.h"

typedef struct s_game t_game;

int key_handler(int keycode, t_game *game);
int close_window(t_game *game);

int main(int argc, char **argv) 
{
    if (argc != 2)
        exit_with_error("Usage: ./so_long <map_file.ber>");

    t_map map;

    parse_map(argv[1], &map);
    validate_map(&map);

    void *mlx = mlx_init();
    if (!mlx)
        exit_with_error("Failed to initialize MiniLibX");

    void *win = mlx_new_window(mlx, map.cols * TILE_SIZE, map.rows * TILE_SIZE, "so_long");
    if (!win)
        exit_with_error("Failed to create window");

    mlx_key_hook(win, key_handler, &map); 
    mlx_hook(win, 17, 0, close_window, &map); 

    mlx_loop(mlx);

    for (int i = 0; i < map.rows; i++)
        free(map.data[i]);
    free(map.data);

    return 0;
}

int key_handler(int keycode, t_game *game) {
    (void)keycode;
    (void)game; 
    return 0;
}

int close_window(t_game *game) {
    (void)game;
    return 0;
}
