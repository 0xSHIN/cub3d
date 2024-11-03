#include "cub3d.h"


// je verifie si ou jvais c un mur ou pas et 
// jajoute ou je soustrait la direciton multiplier par la vitesse aux cordonnées x et y du joueur
// data->player.dirX * moveSpeed
void move_forward(t_data *data)
{
    double moveSpeed = 0.1;

    if (data->config->map[(int)(data->player.y)][(int)(data->player.x + data->player.dirX * moveSpeed)] != '1')
        data->player.x += data->player.dirX * moveSpeed;
    if (data->config->map[(int)(data->player.y + data->player.dirY * moveSpeed)][(int)(data->player.x)] != '1')
        data->player.y += data->player.dirY * moveSpeed;
}

void move_backward(t_data *data)
{
    double moveSpeed = 0.1; 

    if (data->config->map[(int)(data->player.y)][(int)(data->player.x - data->player.dirX * moveSpeed)] != '1')
        data->player.x -= data->player.dirX * moveSpeed;
    if (data->config->map[(int)(data->player.y - data->player.dirY * moveSpeed)][(int)(data->player.x)] != '1')
        data->player.y -= data->player.dirY * moveSpeed;
}

void move_left(t_data *data)
{
    double moveSpeed = 0.1;

    if (data->config->map[(int)(data->player.y)][(int)(data->player.x - data->player.planeX * moveSpeed)] != '1')
        data->player.x -= data->player.planeX * moveSpeed;
    if (data->config->map[(int)(data->player.y - data->player.planeY * moveSpeed)][(int)(data->player.x)] != '1')
        data->player.y -= data->player.planeY * moveSpeed;
}

void move_right(t_data *data)
{
    double moveSpeed = 0.1; 

    if (data->config->map[(int)(data->player.y)][(int)(data->player.x + data->player.planeX * moveSpeed)] != '1')
        data->player.x += data->player.planeX * moveSpeed;
    if (data->config->map[(int)(data->player.y + data->player.planeY * moveSpeed)][(int)(data->player.x)] != '1')
        data->player.y += data->player.planeY * moveSpeed;
}

void rotate_left(t_data *data)
{
    double rotSpeed = 0.05;
    double oldDirX = data->player.dirX;
    // rotation de la direction du joueur vers la gauche
    data->player.dirX = data->player.dirX * cos(rotSpeed) - data->player.dirY * sin(rotSpeed);
    data->player.dirY = oldDirX * sin(rotSpeed) + data->player.dirY * cos(rotSpeed);

    double oldPlaneX = data->player.planeX;
    // rotation du plan de camera vers al gauche aussi
    data->player.planeX = data->player.planeX * cos(rotSpeed) - data->player.planeY * sin(rotSpeed);
    data->player.planeY = oldPlaneX * sin(rotSpeed) + data->player.planeY * cos(rotSpeed);
}

void rotate_right(t_data *data)
{
    double rotSpeed = 0.05;
    double oldDirX = data->player.dirX;
    data->player.dirX = data->player.dirX * cos(-rotSpeed) - data->player.dirY * sin(-rotSpeed);
    data->player.dirY = oldDirX * sin(-rotSpeed) + data->player.dirY * cos(-rotSpeed);

    double oldPlaneX = data->player.planeX;
    data->player.planeX = data->player.planeX * cos(-rotSpeed) - data->player.planeY * sin(-rotSpeed);
    data->player.planeY = oldPlaneX * sin(-rotSpeed) + data->player.planeY * cos(-rotSpeed);

}
