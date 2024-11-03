#include "cub3d.h"

int game_loop(t_data *data)
{
	if (data->movement.move_forward)
		move_forward(data);
	if (data->movement.move_backward)
		move_backward(data);
	if (data->movement.move_left)
		move_left(data);
	if (data->movement.move_right)
		move_right(data);
	if (data->movement.rotate_left)
		rotate_left(data);
	if (data->movement.rotate_right)
		rotate_right(data);

	//mlx_clear_window(data->mlx_ptr, data->win_ptr);
	perform_raycasting(data);
	return (0);
}

void	handle_keyhook(t_data *data)
{
	//mlx_hook(data->win_ptr, 33, NoEventMask, close_window, data);
	mlx_hook(data->win_ptr, 2, KeyPressMask, key_pressed, data);
	mlx_hook(data->win_ptr, 3, KeyReleaseMask, key_released, data);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == 65307)
		printf("close window lol\n");
	if (keycode == 119)
		data->movement.move_forward = 1;
	if (keycode == 115)
		data->movement.move_backward = 1;
	if (keycode == 97)
		data->movement.move_left = 1;
	if (keycode == 100)
		data->movement.move_right = 1;
	if (keycode == 65363)
		data->movement.rotate_left = 1;
	if (keycode == 65361)
		data->movement.rotate_right = 1;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == 119)
		data->movement.move_forward = 0;
	if (keycode == 115)
		data->movement.move_backward = 0;
	if (keycode == 97)
		data->movement.move_left = 0;
	if (keycode == 100)
		data->movement.move_right = 0;
	if (keycode == 65363)
		data->movement.rotate_left = 0;
	if (keycode == 65361)
		data->movement.rotate_right = 0;
	return (0);
}
