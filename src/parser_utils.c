/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <jmartini@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:21:12 by jmartini          #+#    #+#             */
/*   Updated: 2021/07/15 02:07:39 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_perror(int err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)g_errstr[err], 2);
	ft_putstr_fd("\n", 2);
}

int	ft_arg_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_perror(ERR_ARGNO);
		return (0);
	}
	if (ft_strlen(argv[1]) < 5)
	{
		ft_perror(ERR_ARGINV);
		return (0);
	}
	if (ft_memcmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
	{
		ft_perror(ERR_ARGEXT);
		return (0);
	}
	return (1);
}

int	ft_map_valid_bounds(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != c)
			return (0);
	}
	return (1);
}

int	ft_map_valid_line(char *str, char *c)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (str[++i])
	{
		j = -1;
		k = 0;
		while (c[++j])
		{
			if (c[j] == str[i])
				k++;
		}
		if (!k)
			return (0);
	}
	return (1);
}
