#include "cub3d.h"

void load_textures(t_data *data)
{
    int bpp;
    int size_line;
    int endian;

    data->north_texture.img = mlx_xpm_file_to_image(data->mlx_ptr, data->config->north_texture,
                                                    &data->north_texture.width, &data->north_texture.height);
    data->north_texture.data = (int *)mlx_get_data_addr(data->north_texture.img, &bpp, &size_line, &endian);

    data->south_texture.img = mlx_xpm_file_to_image(data->mlx_ptr, data->config->south_texture,
                                                    &data->south_texture.width, &data->south_texture.height);
    data->south_texture.data = (int *)mlx_get_data_addr(data->south_texture.img, &bpp, &size_line, &endian);

    data->west_texture.img = mlx_xpm_file_to_image(data->mlx_ptr, data->config->west_texture,
                                                   &data->west_texture.width, &data->west_texture.height);
    data->west_texture.data = (int *)mlx_get_data_addr(data->west_texture.img, &bpp, &size_line, &endian);

    data->east_texture.img = mlx_xpm_file_to_image(data->mlx_ptr, data->config->east_texture,
                                                   &data->east_texture.width, &data->east_texture.height);
    data->east_texture.data = (int *)mlx_get_data_addr(data->east_texture.img, &bpp, &size_line, &endian);
    if (!data->north_texture.img || !data->south_texture.img ||
        !data->west_texture.img || !data->east_texture.img)
    {
        printf("Error\nFailed to load textures\n");
        exit(EXIT_FAILURE);
    }
}

void init_game(t_data *data, char *cub_file)
{
    (void)cub_file;
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
    {
        printf("Error\nFailed to initialize MLX\n");
        exit(1);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
    if (!data->mlx_ptr)
    {
        printf("Error\nFailed to create window\n");
        exit(1);
    }
    load_textures(data);
    init_player(&data->player, data->config);

}