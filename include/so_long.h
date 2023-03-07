/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:13:56 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/23 10:55:39 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "libft.h"
# include <limits.h>
# include <mlx.h>

typedef struct s_item {
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}				t_item;

typedef struct s_data
{
	int				i;
	int				j;

	int				p;
	int				p_real_i;
	int				p_real_j;
	int				p_i;
	int				p_j;
	int				p_old_i;
	int				p_old_j;

	int				consumable;
	int				move_number;
	int				e;
	int				len_haut_bas;
	int				print_door;
	int				open_door;

	char			*av;
	char			**map;

	void			*mlx;
	void			*window;
	int				window_x;
	int				window_y;
	char			*dst;
	char			*relative_path;
	int				img_width;
	int				img_height;

	void			*dog;
	void			*bottle;
	void			*character;
	void			*door;
	void			*floor;

}					t_data;

int			tab_check(t_data *data);
int			tab_check_p_e(t_data *data);
int			tab_check_value(char **tab);
int			tab_check_len(char **tab);
int			tab_check_first(char **tab);
int			tab_check_last(char **tab, int nb);
void		main_start(t_data *data);
void		my_mlx_pixel_put(t_data **data, int x, int y, int color);
int			key_pressed(int keycode, t_data *data);
int			tab_check_p_e_c(t_data *data);
int			ft_destroy_windows(t_data *data);
int			key_hook(t_data *data);
int			error_map(t_data *data);
int			check_ac(int ac);
void		ft_consumable(t_data *data);
int			tab_check_value(char **tab);
void		ft_open_door(t_data *data);
int			tab_check_first_last_char(char **tab);

#endif
