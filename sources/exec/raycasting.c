#include "cub3d.h"

void	draw_vertical_line(t_data *data, int x, int draw_start, int draw_end, int color)
{
	int y;

	y = draw_start;
	while (y < draw_end)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		y++;
	}
}

/*

ça c'est une grille (une map en gros)

on va appeller chaque chiffre ici une "cellule", chaque cellule est constué soit de 1 ou 1 ou N S W E tas capter

1 1 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 0 0 1
1 1 1 1 1

donc delta_dist_x c la distance que dois parcourir ton rayon pour traverser UNE cellule
et side_dist_x c la distance exact a laquelle ton rayon va passer a une autre cellule
*/

// dirx = plus je regarde a l'est plus c negatif (-1) et vice versa
// diry = plus je regarde vers le sud plus c negatif (-1) et vice versa
// camera_x = position relative de la colonne sur l'écran en gros plus ta cam est a gauche plus c negatif (-1) et vice versa
// plane = c'est ta pov
// side_dist = distance jusqu'à la prochaine ligne de la grille
// perp_wall_dist = distance perpendiculaire au mur (pour calculer la hauteur du mur a afficher)

// step_x et y c la direction dans laquelle va le rayon
// si step_x est -1, cv dire que le rayon va de gauche a droite et vice versa pareil pr y 

// en gros jcalcule les directions de rayons pour chaque colonne de l'écran
// jparcours tt les rayons pour trouver un mur
// je calcule la distance au mur et donc la hauteur a afficher
// je render le ciel, le mur et le sol pixel par pixel
// je calcule les cordonnées X et Y des textures pour chaque colonne
// et japplique pixel par pixel la texture en remplacant la couleur par la couleur du pixel de la cordonnée de la la texture

void perform_raycasting(t_data *data)
{
    int x;
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;
    int map_x;
    int map_y;
    double side_dist_x;
    double side_dist_y;
    double delta_dist_x;
    double delta_dist_y;
    double perp_wall_dist;
    int step_x;
    int step_y;
    int hit;
    int side;
    int line_height;
    int draw_start;
    int draw_end;
    int tex_x, tex_y;
    int color;
    int y;
    t_texture *current_texture;

    x = 0;
    while (x < WIN_WIDTH)
    {
        camera_x = 2 * x / (double)WIN_WIDTH - 1;
        ray_dir_x = data->player.dirX + data->player.planeX * camera_x;
        ray_dir_y = data->player.dirY + data->player.planeY * camera_x;
        map_x = (int)data->player.x;
        map_y = (int)data->player.y;

        // distance que le rayon parcourt
        if (ray_dir_x == 0)
            delta_dist_x = fabs(1 / 0.0001);
        else
            delta_dist_x = fabs(1 / ray_dir_x);

        if (ray_dir_y == 0)
            delta_dist_y = fabs(1 / 0.0001);
        else
            delta_dist_y = fabs(1 / ray_dir_y);

        hit = 0;

        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (data->player.x - map_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_x + 1.0 - data->player.x) * delta_dist_x;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (data->player.y - map_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - data->player.y) * delta_dist_y;
        }

        while (hit == 0)
        {
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                side = 0;
            }
            else
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                side = 1;
            }

            if (data->config->map[map_y][map_x] == '1')
                hit = 1;
        }

        if (side == 0)
            perp_wall_dist = (map_x - data->player.x + (1 - step_x) / 2) / ray_dir_x;
        else
            perp_wall_dist = (map_y - data->player.y + (1 - step_y) / 2) / ray_dir_y;

        line_height = (int)(WIN_HEIGHT / perp_wall_dist);
        draw_start = -line_height / 2 + WIN_HEIGHT / 2;
        if (draw_start < 0)
            draw_start = 0;
        draw_end = line_height / 2 + WIN_HEIGHT / 2;
        if (draw_end >= WIN_HEIGHT)
            draw_end = WIN_HEIGHT - 1;

        // text en fonction de la direction du mur
        if (side == 1 && ray_dir_y > 0)
            current_texture = &data->north_texture;  // mur nord
        else if (side == 1 && ray_dir_y < 0)
            current_texture = &data->south_texture;  // mur sud
        else if (side == 0 && ray_dir_x > 0)
            current_texture = &data->west_texture;   // mur ouest
        else
            current_texture = &data->east_texture;   // mur est

        // calcul de la position exacte où le rayon touche le mur
        double wall_x;
        if (side == 0)
            wall_x = data->player.y + perp_wall_dist * ray_dir_y;
        else
            wall_x = data->player.x + perp_wall_dist * ray_dir_x;
        wall_x -= floor(wall_x);

        // coordonée X de la texture
        tex_x = (int)(wall_x * (double)current_texture->width);
        if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
            tex_x = current_texture->width - tex_x - 1;

        // dessin des murs texturés
        y = draw_start;
        double step = 1.0 * current_texture->height / line_height;
        double tex_pos = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * step;
        while (y < draw_end)
        {
            tex_y = (int)tex_pos & (current_texture->height - 1);
            tex_pos += step;
            color = current_texture->data[tex_y * current_texture->width + tex_x];
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
            y++;
        }

        // plafond
        y = 0;
        while (y < draw_start)
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x1b4f08);  // Couleur pour le plafond
            y++;
        }

        // sol
        y = draw_end;
        while (y < WIN_HEIGHT)
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x096a09);  // Couleur pour le sol
            y++;
        }
        x += 1;
    }
}
