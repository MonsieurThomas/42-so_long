/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:35:23 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/22 18:09:24 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

int	tab_check_p_e_c_error(t_data *data)
{
	if (data->p > 1)
	{
		ft_putstr_fd("Error\nIl ne doit y avoir qu'un point de départ\n", 1);
		return (0);
	}
	if (data->p == 0)
	{
		ft_putstr_fd("Error\nIl n'y a pas de point de départ\n", 1);
		return (0);
	}
	if (data->e == 0)
	{
		ft_putstr_fd("Error\nIl n'y a pas de point de sortie\n", 1);
		return (0);
	}
	return (1);
}

int	tab_check_p_e_c(t_data *data)
{
	data->i = 0;
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == 'P')
			{
				data->p += 1;
				data->p_old_i = data->i - 3;
				data->p_old_j = data->j - 3;
				data->p_real_i = data->i;
				data->p_real_j = data->j;
			}
			if (data->map[data->i][data->j] == 'E')
				data->e += 1;
			if (data->map[data->i][data->j] == 'C')
				(data->consumable)++;
			data->j++;
		}
		data->i++;
	}
	if (!tab_check_p_e_c_error(data))
		return (0);
	return (1);
}

int	tab_check_len(char **tab)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(tab[0]);
	while (tab[i])
	{
		if (len != ft_strlen(tab[i]))
		{
			ft_putstr_fd("Error\nVotre carte n'", 1);
			ft_putstr_fd("est pas rectangulaire\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	tab_check_first(char **tab)
{
	int	i;

	i = -1;
	while (tab[0][++i])
	{
		if (tab[0][i] && tab[0][i] != '1')
		{
			ft_putstr_fd("Error\nLes bordures ne doiv", 1);
			ft_putstr_fd("ent etre composé que de \"1\\n", 1);
			return (0);
		}
	}
	return (1);
}

int	tab_check_last(char **tab, int nb)
{
	int	i;

	i = -1;
	while (tab[nb][++i])
	{
		if (tab[nb][i] != '1')
		{
			ft_putstr_fd("Error\nLes bordures ne doivent ", 1);
			ft_putstr_fd("etre composé que de \"1\\n", 1);
			return (0);
		}
	}
	return (1);
}
