/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:24:45 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/13 14:11:25 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_error(int argc, char **argv)
{
	// int	i;

	// i = 0;
	(void)argv;
	if (argc < 2 )// || !(ft_isdigit(argv[argc][i])))
		exit (EXIT_FAILURE);
}