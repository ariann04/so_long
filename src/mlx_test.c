#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 640
#define HEIGHT 640

int	main(void)
{
    mlx_t	*mlx = mlx_init(WIDTH, HEIGHT, "so_long test", true);
    if (!mlx)
        return (EXIT_FAILURE);

    mlx_texture_t *bg_texture = mlx_load_png("textures/64x64BG.png");
    if (!bg_texture)
    {
        fprintf(stderr, "Error cargando BG\n");
        return (EXIT_FAILURE);
    }

    mlx_image_t *bg_img = mlx_texture_to_image(mlx, bg_texture);
    mlx_image_to_window(mlx, bg_img, 0, 0);
    mlx_delete_texture(bg_texture);

    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}

