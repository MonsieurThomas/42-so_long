/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:09:38 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/31 13:52:31 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

int	key_hook(t_data *data)
{
	ft_putstr_fd("This is the number of move = ", 1);
	ft_putnbr_fd(data->move_number, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

void	choose_object(t_data *d)
{
	if ((d->p_i >= 0 && d->p_i <= d->len_haut_bas)
		&& (d->p_j >= 0 && d->p_j <= ft_strlen(d->map[0])))
	{
		if ((d->map[d->p_i][d->p_j] == '1' || d->map[d->p_i][d->p_j] == 'C' ||
			d->map[d->p_i][d->p_j] == 'E' || d->map[d->p_i][d->p_j] == 'P'))
		{
			if (d->map[d->p_i][d->p_j] == '1')
				mlx_put_image_to_window(d->mlx, d->window, d->dog,
					d->j * 100, d->i * 100);
			else if (d->map[d->p_i][d->p_j] == 'C')
				mlx_put_image_to_window(d->mlx, d->window, d->bottle,
					d->j * 100, d->i * 100);
			else if (d->map[d->p_i][d->p_j] == 'E')
				mlx_put_image_to_window(d->mlx, d->window, d->door,
					d->j * 100, d->i * 100);
			else if (d->map[d->p_i][d->p_j] == 'P')
			{
				if (d->print_door == 1)
					mlx_put_image_to_window(d->mlx, d->window, d->door,
						d->j * 100, d->i * 100);
				mlx_put_image_to_window(d->mlx, d->window,
					d->character, d->j * 100, d->i * 100);
			}
		}
	}
}

int	loop_create_floor(t_data *data)
{
	data->i = 0;
	data->p_i = data->p_old_i;
	while (data->i < 7)
	{
		data->j = 0;
		data->p_j = data->p_old_j;
		while (data->j < 7)
		{
			mlx_put_image_to_window(data->mlx, data->window, data->floor,
				data->j * 100, data->i * 100);
			choose_object(data);
			data->j++;
			data->p_j++;
		}
		data->i++;
		data->p_i++;
	}
	return (0);
}

int	init_images(t_data *data)
{
	data->dog = mlx_xpm_file_to_image(data->mlx, "./texture/dog.xpm",
			&data->img_width, &data->img_height);
	data->bottle = mlx_xpm_file_to_image(data->mlx, "./texture/bottle.xpm",
			&data->img_width, &data->img_height);
	data->character = mlx_xpm_file_to_image(data->mlx,
			"./texture/character.xpm", &data->img_width, &data->img_height);
	data->door = mlx_xpm_file_to_image(data->mlx, "./texture/door.xpm",
			&data->img_width, &data->img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx, "./texture/grass.xpm",
			&data->img_width, &data->img_height);
	if (data->dog == NULL || data->bottle == NULL || data->character == NULL
		|| data->door == NULL || data->floor == NULL)
	{
		ft_putstr_fd("Error\nIl y a un probleme de texture\n", 1);
		return (0);
	}
	return (1);
}

void	main_start(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->window_x,
			data->window_y, "so_long");
	if (!init_images(data))
		return ;
	mlx_hook(data->window, 17, 1L << 5, ft_destroy_windows, data);
	mlx_loop_hook(data->mlx, loop_create_floor, data);
	mlx_hook(data->window, 2, 1L << 0, key_pressed, data);
	mlx_loop(data->mlx);
}
