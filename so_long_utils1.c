/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:27:58 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 15:01:17 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_win(t_map *t);
int		ft_exit(t_map *t);
void	ft_drow_map(t_map *t);
void	ft_checkleft(t_map *t, int i, int j);
void	ft_checkright(t_map *t, int i, int j);
void	ft_checkup(t_map *t, int i, int j);
int		ft_checkdown(t_map *t, int i, int j, int k);

void	ft_left(t_map *t, int c)
{
	int	i;
	int	j;

	i = 0;
	while (t->map[i])
	{
		j = 0;
		ft_checkleft(t, i, j);
		i++;
	}
	mlx_clear_window(t->mlx, t->mlx_win);
	ft_drow_map(t);
}

void	ft_right(t_map *t, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (t->map[i])
	{
		j = 0;
		ft_checkright(t, i, j);
		i++;
	}
	mlx_clear_window(t->mlx, t->mlx_win);
	ft_drow_map(t);
}

void	ft_up(t_map *t, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (t->map[i])
	{
		j = 0;
		ft_checkup(t, i, j);
		i++;
	}
	mlx_clear_window(t->mlx, t->mlx_win);
	ft_drow_map(t);
}

void	ft_down(t_map *t, int c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (t->map[i])
	{
		j = 0;
		if (ft_checkdown(t, i, j, k) != 0)
			break ;
		i++;
	}
	mlx_clear_window(t->mlx, t->mlx_win);
	ft_drow_map(t);
}

int	ft_keyprint(int c, t_map *t)
{
	if (c == 53)
		ft_exit(t);
	if (c == 0)
		ft_left(t, c);
	if (c == 1)
		ft_down(t, c);
	if (c == 2)
		ft_right(t, c);
	if (c == 13)
		ft_up(t, c);
	return (0);
}
