/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:24:45 by bgrosjea          #+#    #+#             */
/*   Updated: 2024/01/12 18:43:41 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_error(int argc)
{
	if (argc < 2)
		exit (EXIT_FAILURE);
}

void	ft_split_check(char *argv, int i)
{
	while (argv[i] != '\0')
	{
		while (argv[i] == ' ')
			i++;
		if (argv[i] == '-')
			i++;
		if ((argv[i] == '\0' && argv[i - 1] == '-')
			|| argv[i] == '\0')
			exit((write(2, "Error\n", 6), EXIT_FAILURE));
		while (1 == ft_isdigit(argv[i]))
			i++;
		if (argv[i] != ' ' && argv[i] != '\0'
			&& argv[i + 1] != ' ')
			exit((write(2, "Error\n", 6), EXIT_FAILURE));
	}
}
