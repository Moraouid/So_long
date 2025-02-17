/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:43:58 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/02/16 23:56:17 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	check_extension(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
		i++;
	if (av[1][i - 1] != 'r' || av[1][i - 2] != 'e' || av[1][i - 3] != 'b'
		|| av[1][i - 4] != '.')
		return (0);
	return (1);
}

void	textures_collect(t_game *game)
{
	int	a;

	a = 32;
	game->collect[0] = mlx_xpm_file_to_image(game->mlx,
			"texture/collect_f1.xpm", &a, &a);
	game->collect[1] = mlx_xpm_file_to_image(game->mlx,
			"texture/collect_f2.xpm", &a, &a);
	game->collect[2] = mlx_xpm_file_to_image(game->mlx,
			"texture/collect_f3.xpm", &a, &a);
	game->collect[3] = mlx_xpm_file_to_image(game->mlx,
			"texture/collect_f4.xpm", &a, &a);
	game->collect[4] = mlx_xpm_file_to_image(game->mlx,
			"texture/collect_f5.xpm", &a, &a);
	game->collect[5] = mlx_xpm_file_to_image(game->mlx,
			"texture/collect_f6.xpm", &a, &a);
}

void	textures_enemy(t_game *game)
{
	int	a;

	a = 32;
	game->enemy[0] = mlx_xpm_file_to_image(game->mlx, "texture/enemy_f1.xpm",
			&a, &a);
	game->enemy[1] = mlx_xpm_file_to_image(game->mlx, "texture/enemy_f2.xpm",
			&a, &a);
	game->enemy[2] = mlx_xpm_file_to_image(game->mlx, "texture/enemy_f3.xpm",
			&a, &a);
	game->enemy[3] = mlx_xpm_file_to_image(game->mlx, "texture/enemy_f4.xpm",
			&a, &a);
}

void	clean_screen_helpre(t_game *game)
{
	if (game->collect[0])
		mlx_destroy_image(game->mlx, game->collect[0]);
	if (game->collect[1])
		mlx_destroy_image(game->mlx, game->collect[1]);
	if (game->collect[2])
		mlx_destroy_image(game->mlx, game->collect[2]);
	if (game->collect[3])
		mlx_destroy_image(game->mlx, game->collect[3]);
	if (game->collect[4])
		mlx_destroy_image(game->mlx, game->collect[4]);
	if (game->collect[5])
		mlx_destroy_image(game->mlx, game->collect[5]);
	if (game->enemy[0])
		mlx_destroy_image(game->mlx, game->enemy[0]);
	if (game->enemy[1])
		mlx_destroy_image(game->mlx, game->enemy[1]);
	if (game->enemy[2])
		mlx_destroy_image(game->mlx, game->enemy[2]);
	if (game->enemy[3])
		mlx_destroy_image(game->mlx, game->enemy[3]);
}
