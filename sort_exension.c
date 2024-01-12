/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_exension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:30:45 by bgrosjea          #+#    #+#             */
/*   Updated: 2024/01/11 17:01:58 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sort_extention1(t_Node **a, t_Node **b, t_m *var)
{
	while ((*a)->rank <= var->max_rank + var->div_max
		&& (*a)->rank <= (find_max_rank(*a) - 5)
		&& ((((*a)->rank) < (var->div_max * var->div))
			|| ((*a)->rank < (find_max_rank_a(*a)))))
	{
		if (!(*a)->next->next->next->next->next)
			break ;
		pb(b, a, 1);
		if ((*b)->rank <= var->max_rank)
			var->actual++;
		if ((*b)->next && ((*b)->rank < var->max_rank)
			&& ((*a)->rank > var->max_rank + var->div_max))
			rr(a, b, 1);
		if ((*b)->next && ((*b)->rank < var->max_rank))
			rb(b, 1);
		if ((*b)->next && (*b)->rank < (*b)->next->rank)
			sb(b, 1);
		while (((*b)->next && (*b)->rank < (*b)->next->rank))
			rb(b, 1);
	}
}

void	sort_extention2(t_Node **a, t_Node **b, int min, int exec)
{
	min = (*a)->rank - 1;
	exec = find_next_rank_b(*b, min);
	if (exec > 0)
	{
		while ((*b)->rank != min)
		{
			if ((*b)->rank == min - 1)
				pa(a, b, 1);
			if ((*b)->rank == min)
				break ;
			rb(b, 1);
		}
	}
	else
	{
		while ((*b)->rank != min)
		{
			if ((*b)->rank == min - 1)
				pa(a, b, 1);
			if ((*b)->rank == min)
				break ;
			rrb(b, 1);
		}
	}
}

int	count_size_a(t_Node *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}
