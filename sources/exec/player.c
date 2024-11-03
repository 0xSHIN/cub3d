#include "cub3d.h"

void init_player(t_player *player, t_config *config)
{
    // j'ajoute 0.5 ici pour etre bien au centre de la case
    player->x = config->player_x + 0.5;
    player->y = config->player_y + 0.5;
    if (config->player_orientation == 'N')
    {
        player->dirX = 0;
        player->dirY = -1;
        player->planeX = 0.66;
        player->planeY = 0;
    }
    else if (config->player_orientation == 'S')
    {
        player->dirX = 0;
        player->dirY = 1;
        player->planeX = -0.66;
        player->planeY = 0;
    }
    else if (config->player_orientation == 'E')
    {
        player->dirX = 1;
        player->dirY = 0;
        player->planeX = 0;
        player->planeY = 0.66;
    }
    else if (config->player_orientation == 'W')
    {
        player->dirX = -1;
        player->dirY = 0;
        player->planeX = 0;
        player->planeY = -0.66;
    }
}
