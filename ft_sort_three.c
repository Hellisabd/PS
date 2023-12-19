/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:13:30 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/19 12:03:43 by bgrosjea         ###   ########.fr       */
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