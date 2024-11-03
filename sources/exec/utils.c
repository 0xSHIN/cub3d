#include <stdio.h>
#include "cub3d.h"

void print_color(int color[3])
{
    printf("R: %d, G: %d, B: %d\n", color[0], color[1], color[2]);
}

void print_config(t_config *config)
{
    int i;

    printf("North Texture: %s\n", config->north_texture);
    printf("South Texture: %s\n", config->south_texture);
    printf("West Texture: %s\n", config->west_texture);
    printf("East Texture: %s\n", config->east_texture);

    printf("Floor Color: ");
    print_color(config->floor_color);

    printf("Ceiling Color: ");
    print_color(config->ceiling_color);

    printf("Map Dimensions: %d x %d\n", config->map_width, config->map_height);

    printf("Player Start Position: (%d, %d)\n", config->player_x, config->player_y);
    printf("Player Orientation: %c\n", config->player_orientation);

    printf("Map:\n");
    for (i = 0; i < config->map_height; i++)
    {
        printf("%s\n", config->map[i]);
    }
}
