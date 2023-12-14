/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:40:27 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/14 20:05:11 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void    ft_check(int argc, char **argv)
{
	int i;

	i = 0;
	while (--argc > 0)
	{
		i = 0;
		while (argv[argc][i] != '\0')
		{
			if(0 == ft_isdigit(argv[argc][i]) && argv[argc][i] != ' ')
			{
				ft_printf("found \"%c\" Error\n", argv[argc][i]);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
}

int	ft_check_same(t_Node *a)
{
	t_Node	*tmp;
	t_Node	*cmp;
	int		size;
	
	cmp = a;
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
