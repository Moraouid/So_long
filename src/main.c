/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:35:22 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/01/30 17:04:19 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/usr/include/minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	void	*mlx;
    void	*mlx_win;

	mlx = mlx_init();
	if (mlx == NULL) {
		fprintf(stderr, "Error initializing MLX\n");
		return (EXIT_FAILURE);
	}
    mlx_win = mlx_new_window(mlx, width, height, "so_long");
	if (mlx_win == NULL) {
		fprintf(stderr, "Error creating window\n");
		return (EXIT_FAILURE);
	}
	mlx_loop(mlx);
}
