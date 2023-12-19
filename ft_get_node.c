/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:13:48 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/19 19:19:26 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	get_right_pos_pos(t_stock *costs, t_Node **src, t_Node **dest)
{
	if (costs->cost > 0 && costs->cost2 > 0)
	{
		while (costs->cost != 0 && costs->cost2 != 0)
		{
			costs->cost--;
			costs->cost2--;
			rr(src, dest);
		}
		if (costs->cost == 0)
		{
			while (costs->cost2-- != 0)
				rb(dest, 1);
		}
		if (costs->cost2 == 0)
		{
			while (costs->cost-- != 0)
				ra(dest, 1);
		}
	}
	get_right_pos_utils(costs, src, dest);
}

void	ft_get_node_b(t_Node **src, t_Node **find_target, int size)
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
		tmp->cost2 = ft_get_target_cost_b(tmp->nbr, *find_target, size);
		tmp->costoverall = ft_check_cost_diff(tmp->cost, tmp->cost2);
		tmp = tmp->next;
		node_pos++;
	}
	tmp = *src;
	costs.best_cost = find_best_cost(tmp, &costs);
	get_right_pos_neg_b(&costs, src, find_target);
}

int	find_max(t_Node *find_target)
{
	int i;
	int	c;
	int	nbr;

	i = 0;
	nbr = INT_MIN;
	while (find_target)
	{
		if (find_target->nbr > nbr)
		{
			nbr = find_target->nbr;
			c = i;
		}
		find_target = find_target->next;
		i++;
	}
	return (c);
}

int	ft_get_target_cost(int nbr, t_Node *find_target, int size)
{
	int		i;
	int		target_cost;
	t_Node	*tmp;
	long	best_target;

	i = 0;
	tmp = find_target;
	best_target = LONG_MIN;
	while (tmp)
	{
		if (tmp->nbr < nbr && tmp->nbr > best_target)
		{
			best_target = tmp->nbr;
			target_cost = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (best_target == LONG_MIN)
		target_cost = find_max(find_target);
	if (target_cost > size / 2 && size % 2 == 0)
		return (target_cost - size);
	else if (target_cost > size / 2)
		return (target_cost - (size + 1));
	else
		return (target_cost);
	return (target_cost);
}

int	ft_get_target_cost_b(int nbr, t_Node *find_target, int size)
{
	int		i;
	int		target_cost;
	t_Node	*tmp;
	long	best_target;

	i = 0;
	tmp = find_target;
	best_target = LONG_MAX;
	while (tmp)
	{
		if (tmp->nbr >= nbr && tmp->nbr < best_target)
		{
			best_target = tmp->nbr;
			target_cost = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (best_target == LONG_MAX)
		target_cost = find_min(find_target);
	if (target_cost > size / 2 && size % 2 == 0)
		return (target_cost - size);
	else if (target_cost > size / 2)
		return (target_cost - (size + 1));
	else
		return (target_cost);
	return (target_cost);
}

