/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:27:29 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/22 18:09:42 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

void	ft_open_door(t_data *data)
{
	if (data->open_door == 1 || data->consumable == 0)
		ft_destroy_windows(data);
}

void	ft_consumable(t_data *data)
{
	(data->consumable)--;
	if (data->consumable == 0)
		data->open_door = 1;
}

int	ft_destroy_windows(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	ft_putstr_fd("Game over\n", 1);
	exit(1);
	return (1);
}
