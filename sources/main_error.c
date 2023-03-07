/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:32:21 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/27 18:15:10 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

int	error_map_ber(t_data *data)
{
	char	*ext;

	ext = ft_substr(data->av, (ft_strlen(data->av) - 4), 4);
	if (ft_strncmp(ext, ".ber", 4))
	{
		ft_putstr_fd("Error\nL'extension de votre fichier n'est pas bonne\n", 1);
		free (ext);
		return (0);
	}
	free (ext);
	return (1);
}

int	error_map(t_data *data)
{
	int	fd;

	if (!error_map_ber(data))
		return (0);
	fd = open(data->av, O_DIRECTORY);
	if (fd > 0)
	{
		ft_putstr_fd("Error\nVous essayer d'ouv", 1);
		ft_putstr_fd("rir un dossier et non un fichier\n", 1);
		return (0);
	}	
	close (fd);
	fd = open(data->av, O_RDONLY);
	if (fd < 1)
	{
		ft_putstr_fd("Error\nIl y a un probleme lor", 1);
		ft_putstr_fd("s de l'ouverture du fichier\n", 1);
		return (0);
	}
	close (fd);
	return (1);
}

int	check_ac(int ac)
{
	if (ac == 1)
	{
		ft_putstr_fd("Error\nIl n'y a pas de fichier\n", 1);
		return (0);
	}
	if (ac != 2)
	{
		ft_putstr_fd("Error\nMerci de ne mettre qu'un fichier\n", 1);
		return (0);
	}
	return (1);
}

int	tab_check_value(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != '0' && tab[i][j] != '1' && tab[i][j] != 'C'
				&& tab[i][j] != 'E' && tab[i][j] != 'P')
			{
				ft_putstr_fd("Error\nVous avez utilisé", 1);
				ft_putstr_fd(" un caractère non autorisé", 1);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	tab_check_first_last_char(char **tab)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(tab[0]) - 1;
	while (tab[i])
	{
		if (tab[i][0] != '1' || tab[i][len] != '1')
		{
			ft_putstr_fd("Error\nLes bords ne doiven", 1);
			ft_putstr_fd("t etre composés que de \"1\"\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}
