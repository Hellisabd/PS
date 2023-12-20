/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:13:30 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/20 15:06:47 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

bool	a_is_sorted(t_Node *a)
{
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
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
	if (5 == size)
	{
		ft_find_rank_to_p(a);
		pb(b, a);
		size--;
	}
	if (size == 4)
	{
		ft_find_rank_to_p(a);
		pb(b, a);
	}
	ft_sort_three(a);
	pa(a, b);
	pa(a, b);
}

t_Node	**ft_sort_three(t_Node **a)
{
	while (!a_is_sorted(*a))
	{
		if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
			ra(a, 1);
		if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
			sa(*a, 1);
		if ((*a)->nbr < (*a)->next->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
			rra(a, 1);
	}
	return (a);
}
