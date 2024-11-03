#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <X11/keysym.h>
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <X11/X.h>
#include <stdbool.h>
#include "../mlx/mlx_int.h"
#include <string.h>
#include <sys/types.h>
#include <float.h>
#include <fcntl.h>
#include <sys/stat.h>


# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct s_texture {
    void        *img;
    int         *data;
    int         width;
    int         height;
}               t_texture;

typedef struct s_movement {
    int move_forward;
    int move_backward;
    int move_left;
    int move_right;
    int rotate_left;
    int rotate_right;
}   t_movement;

typedef struct s_player {
    double      x;
    double      y;
    double      dirX;
    double      dirY;
    double      planeX;
    double      planeY;
}   t_player;

// STRUCTURE PARSING 
typedef struct s_config {
    char    *north_texture;   // Chemin vers la texture du mur nord
    char    *south_texture;   // Chemin vers la texture du mur sud
    char    *west_texture;    // Chemin vers la texture du mur ouest
    char    *east_texture;    // Chemin vers la texture du mur est
    int     floor_color[3];   // Couleur du sol (RGB)
    int     ceiling_color[3]; // Couleur du plafond (RGB)
    char    **map;            // Carte 2D
    int     map_width;        // Largeur de la carte
    int     map_height;       // Hauteur de la carte
    int     player_x;         // Position X du joueur dans la carte
    int     player_y;         // Position Y du joueur dans la carte
    char    player_orientation; // Orientation initiale du joueur ('N', 'S', 'E', 'W')
}   t_config;

typedef struct s_data {
    void        *mlx_ptr;
    void        *win_ptr;
    t_config    *config;
    t_player    player;
    t_texture        north_texture;
    t_texture        south_texture;
    t_texture        west_texture;
    t_texture        east_texture;
    t_movement  movement;
    int         texture_width;
    int         texture_height;
}   t_data;


void    init_game(t_data *data, char *cub_file);

void    move_forward(t_data *data);
void    move_backward(t_data *data);
void    rotate_left(t_data *data);
void    rotate_right(t_data *data);
void move_left(t_data *data);
void move_right(t_data *data);

int     handle_keypress(int keycode, t_data *data);
void	handle_keyhook(t_data *data);

int     close_window(t_data *data);

void    perform_raycasting(t_data *data);

void init_player(t_player *player, t_config *config);
void load_textures(t_data *data);

void print_config(t_config *config);
void print_color(int color[3]);

int game_loop(t_data *data);

int	key_pressed(int keycode, t_data *data);
int	key_released(int keycode, t_data *data);


#endif