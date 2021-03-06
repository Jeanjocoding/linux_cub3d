/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:53:44 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:53:46 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern int	g_ground;
extern int	g_ceiling;

int		get_rgb(int r, int g, int b)
{
	int rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

int		get_floor(char ***tab)
{
	int		r;
	int		g;
	int		b;
	char	**tab2;

	if (ft_tablen(*tab) != 2)
		error_quit("Error: invalid floor format", tab);
	if (!(tab2 = ft_split((*tab)[1], ',')))
		return (-1);
	ft_freetab(tab);
	if (check_all_digit(tab2[0]) == -1
		|| check_all_digit(tab2[1]) == -1
		|| check_all_digit(tab2[2]) == -1)
		error_quit("Error: invalid floor format", tab);
	r = ft_atoi(tab2[0]);
	g = ft_atoi(tab2[1]);
	b = ft_atoi(tab2[2]);
	g_ground = get_rgb(r, g, b);
	ft_freetab(&tab2);
	return (1);
}

int		get_g_ceiling(char ***tab)
{
	int		r;
	int		g;
	int		b;
	char	**tab2;

	if (ft_tablen(*tab) != 2)
		error_quit("Error: invalid g_ceiling format", tab);
	if (!(tab2 = ft_split((*tab)[1], ',')))
		return (-1);
	ft_freetab(tab);
	if (check_all_digit(tab2[0]) == -1
		|| check_all_digit(tab2[1]) == -1
		|| check_all_digit(tab2[2]) == -1)
		error_quit("Error: invalid g_ceiling format", tab);
	r = ft_atoi(tab2[0]);
	g = ft_atoi(tab2[1]);
	b = ft_atoi(tab2[2]);
	g_ceiling = get_rgb(r, g, b);
	ft_freetab(&tab2);
	return (1);
}
