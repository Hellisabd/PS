/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:59 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/19 19:12:14 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_get_Ntop(int N_to_p, t_Node *a, int size_a, int node_pos)
{
	int	i;

	i = node_pos;
	while (N_to_p != a->nbr)
	{
		a = a->next;
		i++;
	}
	if (N_to_p == a->nbr)
	{
		if (i > size_a / 2 && size_a % 2 == 0)
			return (i - (size_a));
		else if (i > size_a / 2)
			return (i - (size_a + 1));
		else
			return (i);
	}
	return (i);
}

int	find_best_cost(t_Node *a, t_stock *costs)
{
	int	i;
	int	tmp_nbr;
	int count;

	count = 0;
	i = a->costoverall;
	while (a)
	{
		if (a->costoverall < 0)
			tmp_nbr = a->costoverall * -1;
		else
			tmp_nbr = a->costoverall;
		if (tmp_nbr < i || i == 0 || count == 0)
		{
			i = a->costoverall;
			costs->cost = a->cost;
			costs->cost2 = a->cost2;
		}
		if (i == 0)
			break;
		a = a->next;
		count++;
	}
	return (i);
}

void	get_right_pos_neg(t_stock *costs, t_Node **src, t_Node **dest)
{
	if (costs->cost < 0 && costs->cost2 < 0)
	{
		while (costs->cost != 0 && costs->cost2 != 0)
		{
			costs->cost++;
			costs->cost2++;
			rrr(src, dest);
		}
		if (costs->cost == 0)
		{
			while (costs->cost2++ != 0)
				rrb(dest, 1);
		}
		if (costs->cost2 == 0)
		{
			while (costs->cost++ != 0)
				rra(dest, 1);
		}
	}
	else
		get_right_pos_pos(costs, src, dest);
}

void	ft_get_node_a(t_Node **src, t_Node **find_target, int size)
{
	t_Node	*tmp;
	t_stock costs;
	int		node_pos;
	
	tmp = *src;
	costs.best_cost = 0;
	costs.cost2 = 0;
	costs.cost = 0;
	node_pos = 0;
	while (tmp)
	{
		tmp->cost = ft_get_Ntop(tmp->nbr, tmp, size, node_pos);
		tmp->cost2 = ft_get_target_cost(tmp->nbr, *find_target, size);
		tmp->costoverall = ft_check_cost_diff(tmp->cost, tmp->cost2);
		if (tmp->costoverall == 0)
			break;
		tmp = tmp->next;
		node_pos++;
	}
	tmp = *src;
	costs.best_cost = find_best_cost(tmp, &costs);
	get_right_pos_neg(&costs, src, find_target);
}

void	ft_sort(t_Node **a, int size_a)
{
	t_Node	*b;
	int		size_b;

	b = NULL;
	if ((*a)->next->next->next)
	{
		pb(&b, a);
		pb(&b, a);
		size_a = size_a - 3;
	}
	while ((*a)->next->next->next)
	{
		ft_get_node_a(a, &b, size_a);
		pb(&b, a);
		size_a--;
		size_b++;
	}
	a = ft_sort_three(a);
	while (b)
	{
		ft_get_node_b(&b, a, size_b);
		pa(a, &b);
		size_a++;
		size_b--;
	}
}
