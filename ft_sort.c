/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:59 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/20 19:40:40 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	find_max_rank(t_Node *a)
{
	int		max_rank;
	
	max_rank = 0;
	while (a)
	{
		if (a->rank > max_rank)
			max_rank = a->rank;
		a = a->next;
	}
	return (max_rank);
}

int	ft_find_rank(t_Node **a)
{
	t_Node	*tmp;
	t_Node	*current_a;
	int		inf;

	inf = 1;
	current_a = *a;
	while (current_a)
	{
		tmp = *a;
		inf = 1;
		while (tmp)
		{
			if (tmp->nbr < current_a->nbr)
				inf++;
			tmp = tmp->next;
		}
		current_a->rank = inf;
		current_a = current_a->next;
	}
	return (find_max_rank(*a));
}

void	ft_fill_b(t_Node **a, t_Node **b, int max_rank)
{
	int		actual;
	int		div_max;
	int		diviseur;

	diviseur = ft_find_div(max_rank);
	actual = 0;
	div_max = max_rank / diviseur;
	max_rank = max_rank / diviseur;
	while ((*a)->next->next->next->next->next)
	{
		if (actual != 1)
			max_rank = max_rank + div_max;
		while (actual < max_rank && (*a)->next->next->next->next->next)
		{
			if ((*a)->rank <= max_rank && ((*a)->nbr) < (div_max * diviseur))
			{
				actual++;
				pb(b, a);
			}
			ra(a, 1);
		}
	}
}

void	ft_sort(t_Node **a, t_Node **b, int max_rank)
{
	max_rank = find_max_rank_a(*a);
	ft_fill_b(a, b, max_rank);
	ft_sort_five(a, b, count_size_a(*a));
	while (*b)
	{
		ft_final_sort(a, b);
		pa(a, b);
		 //if (ft_check_back(*a))
		 	//ra(a, 1);
	}
	max_rank = find_min(*a);
	while ((*a)->rank != max_rank)
	{
		if (find_r_or_rr(a, max_rank))
			ra(a, 1);
		else
			rra(a, 1);
	}
}

int	count_size_a(t_Node *a)
{
	int i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}
