/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_key_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:15:58 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/22 18:09:34 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

void	ft_upward(t_data *data)
{
	if (data->map[data->p_real_i - 1][data->p_real_j] == 'C')
		ft_consumable(data);
	if (data->map[data->p_real_i - 1][data->p_real_j] != '1')
	{
		key_hook(data);
		data->move_number++;
		(data->p_old_i)--;
		if (data->print_door == 1)
		{
			data->map[data->p_real_i][data->p_real_j] = 'E';
			data->print_door = 0;
		}
		else
			data->map[data->p_real_i][data->p_real_j] = '0';
		if (data->map[data->p_real_i - 1][data->p_real_j] == 'E')
		{
			ft_open_door(data);
			data->print_door = 1;
		}
		data->map[data->p_real_i - 1][data->p_real_j] = 'P';
		(data->p_real_i)--;
	}
}

void	ft_downward(t_data *data)
{
	if (data->map[data->p_real_i + 1][data->p_real_j] == 'C')
		ft_consumable(data);
	if (data->map[data->p_real_i + 1][data->p_real_j] != '1')
	{
		key_hook(data);
		data->move_number++;
		(data->p_old_i)++;
		if (data->print_door == 1)
		{
			data->map[data->p_real_i][data->p_real_j] = 'E';
			data->print_door = 0;
		}
		else
			data->map[data->p_real_i][data->p_real_j] = '0';
		if (data->map[data->p_real_i + 1][data->p_real_j] == 'E')
		{
			ft_open_door(data);
			data->print_door = 1;
		}
		data->map[data->p_real_i + 1][data->p_real_j] = 'P';
		(data->p_real_i)++;
	}
}

void	ft_right(t_data *data)
{
	if (data->map[data->p_real_i][data->p_real_j + 1] == 'C')
		ft_consumable(data);
	if (data->map[data->p_real_i][data->p_real_j + 1] != '1')
	{
		key_hook(data);
		data->move_number++;
		(data->p_old_j)++;
		if (data->print_door == 1)
		{
			data->map[data->p_real_i][data->p_real_j] = 'E';
			data->print_door = 0;
		}
		else
			data->map[data->p_real_i][data->p_real_j] = '0';
		if (data->map[data->p_real_i][data->p_real_j + 1] == 'E')
		{
			ft_open_door(data);
			data->print_door = 1;
		}
		data->map[data->p_real_i][data->p_real_j + 1] = 'P';
		(data->p_real_j)++;
	}
}

void	ft_left(t_data *data)
{
	if (data->map[data->p_real_i][data->p_real_j - 1] == 'C')
		ft_consumable(data);
	if (data->map[data->p_real_i][data->p_real_j - 1] != '1')
	{
		key_hook(data);
		data->move_number++;
		(data->p_old_j)--;
		if (data->print_door == 1)
		{
			data->map[data->p_real_i][data->p_real_j] = 'E';
			data->print_door = 0;
		}
		else
			data->map[data->p_real_i][data->p_real_j] = '0';
		if (data->map[data->p_real_i][data->p_real_j - 1] == 'E')
		{
			ft_open_door(data);
			data->print_door = 1;
		}
		data->map[data->p_real_i][data->p_real_j - 1] = 'P';
		(data->p_real_j)--;
	}
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_destroy_windows(data);
	if (keycode == 13)
		ft_upward(data);
	if (keycode == 1)
		ft_downward(data);
	if (keycode == 2)
		ft_right(data);
	if (keycode == 0)
		ft_left(data);
	return (0);
}
