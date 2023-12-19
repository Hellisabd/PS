/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:40:27 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/19 16:58:59 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	find_min(t_Node *find_target)
{
	int i;
	int	c;
	int	nbr;

	i = 0;
	nbr = INT_MAX;
	while (find_target)
	{
		if (find_target->nbr < nbr)
		{
			nbr = find_target->nbr;
			c = i;
		}
		find_target = find_target->next;
		i++;
	}
	return (c);
}

void	get_right_pos_utils(t_stock *costs, t_Node **src, t_Node **dest)
{
	if (costs->cost <= 0 && costs->cost2 >= 0)
	{
		while (costs->cost != 0)
		{
			rra(src, 1);
			costs->cost++;
		}
		while (costs->cost2 != 0)
		{
			rb(dest, 1);
			costs->cost2--;
		}
	}
	else
	{
		while (costs->cost != 0)
		{
			ra(src, 1);
			costs->cost--;
		}
		while (costs->cost2 != 0)
		{
			rrb(dest, 1);
			costs->cost2++;
		}
	}
}

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

int	ft_check_cost_diff(int cost, int cost2)
{
	if ((cost < 0 && cost2 < 0) || (cost > 0 && cost2 > 0))
	{
		if (cost < 0 && cost2 < 0)
		{
			if (cost > cost2)
				return (cost2);
			else
				return(cost);
		}
		else
			if (cost > cost2)
				return (cost);
			else
				return(cost2);
	}
	else if (cost > cost2 || cost < 0)
		return (cost - cost2);
	else
		return(cost2 - cost);
	return (0);
}
