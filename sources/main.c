/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:29:17 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/31 13:52:44 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

void	create_data(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->p = 0;
	data->e = 0;
	data->window_x = 700;
	data->window_y = 700;
	data->consumable = 0;
	data->open_door = 0;
	data->print_door = 0;
	data->move_number = 1;
}

int	tab_check(t_data *data)
{
	int	nb;

	nb = 0;
	while (data->map[nb])
		nb++;
	data->len_haut_bas = nb - 1;
	if (!tab_check_first(data->map) || !tab_check_last(data->map, nb - 1))
		return (0);
	if (!tab_check_len(data->map))
		return (0);
	if (!tab_check_first_last_char(data->map))
		return (0);
	if (!tab_check_value(data->map))
		return (0);
	if (!tab_check_p_e_c(data))
		return (0);
	return (1);
}

int	get_nb_line(t_data *data)
{
	int		fd;
	int		nb_line;
	char	*line;

	fd = open(data->av, O_RDONLY);
	nb_line = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		nb_line++;
	}
	free(line);
	close(fd);
	return (nb_line);
}

int	read_map(t_data *data)
{
	int		fd;
	int		nb_line;
	char	*line;

	nb_line = get_nb_line(data);
	fd = open(data->av, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * (nb_line + 1));
	data->map[nb_line] = NULL;
	data->i = 0;
	while (data->i < nb_line)
	{
		line = get_next_line(fd);
		data->map[data->i] = ft_strdup(line);
		if (data->map[data->i][ft_strlen(line) - 1] == '\n')
			data->map[data->i][ft_strlen(line) - 1] = 0;
		free(line);
		data->i++;
	}
	if (data->i < 3)
	{
		ft_putstr_fd("Error\nProbleme de carte\n", 1);
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_ac(ac))
		return (0);
	data.av = av[1];
	if (!error_map(&data))
		return (0);
	if (!read_map(&data))
		return (0);
	create_data(&data);
	if (!tab_check(&data))
		return (0);
	main_start(&data);
}
