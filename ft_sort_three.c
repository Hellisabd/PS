/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:13:30 by bgrosjea          #+#    #+#             */
/*   Updated: 2024/01/12 14:02:32 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	find_max_rank_a(t_Node *a)
{
	int	max_rank;

	max_rank = 0;
	while (a)
	{
		if (a->rank > max_rank)
			max_rank = a->rank;
		a = a->next;
	}
	return (max_rank);
}

bool	a_is_sorted(t_Node *a)
{
	while (a && a->next)
	{
		if ((a->nbr) > (a->next->nbr))
			return (false);
		a = a->next;
	}
	return (true);
}

void	ft_find_rank_to_p(t_Node **a)
{
	int	min;

	min = find_min(*a);
	while ((*a)->rank != min)
		ra(a, 1);
}

void	ft_sort_five(t_Node **a, t_Node **b, int size)
{
	if (size == 2 && !(a_is_sorted(*a)))
		sa(a, 1);
	if (5 == size)
	{
		ft_find_rank_to_p(a);
		pb(b, a, 1);
		size--;
	}
	if (size == 4)
	{
		ft_find_rank_to_p(a);
		pb(b, a, 1);
	}
	ft_sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
	size = find_min(*a);
	while ((*a)->rank != size)
	{
		if (find_r_or_rr(a, size))
			ra(a, 1);
		else
			rra(a, 1);
	}
}

t_Node	**ft_sort_three(t_Node **a)
{
	while (!a_is_sorted(*a))
	{
		if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
			ra(a, 1);
		if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
			sa(a, 1);
		if ((*a)->nbr < (*a)->next->nbr
			&& (*a)->next->nbr > (*a)->next->next->nbr)
			rra(a, 1);
	}
	return (a);
}
