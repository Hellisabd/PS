/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:40:27 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/18 12:25:27 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    ft_check(int argc, char **argv)
{
	int i;
	int	j;

	j = 1;
	while (argc > j)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (0 == ft_isdigit(argv[j][i]) && (argv[j][i] != ' ' && argv[j][i] != '-'))
			{
				ft_printf("found \"%c\" Error\n", argv[j][i]);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
}

int	ft_check_same(t_Node **a, int size)
{
	t_Node	*tmp;
	t_Node	*cmp;
	
	cmp = (*a);
	size = 0;
	while (cmp)
	{
		tmp = cmp->next;
		while (tmp)
		{
			if (tmp->nbr == cmp->nbr)
			{
				ft_printf("Error : found 2 times %d", cmp->nbr);
				exit (EXIT_FAILURE);
			}
			tmp = tmp->next;
		}
		size++;
		cmp = cmp->next;
	}
	return (size);
}
