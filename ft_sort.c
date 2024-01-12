/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:59 by bgrosjea          #+#    #+#             */
/*   Updated: 2024/01/11 17:05:50 by bgrosjea         ###   ########.fr       */
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
	t_m	var;

	var.div = ft_find_div(max_rank);
	var.actual = 0;
	var.max_rank = max_rank;
	var.div_max = var.max_rank / var.div;
	var.max_rank = var.max_rank / var.div;
	while ((*a)->next->next->next->next->next)
	{
		if (var.actual != 0)
		{
			var.actual = var.max_rank;
			var.max_rank += var.div_max * 2;
		}
		while (var.actual < var.max_rank && (*a)->next->next->next->next->next
			&& find_min(*a) <= var.max_rank)
		{
			sort_extention1(a, b, &var);
			ra(a, 1);
		}
	}
}

int	find_next_rank_b(t_Node *b, int to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (b)
	{
		if (b->rank == to_find)
			j = i;
		i++;
		b = b->next;
	}
	if (j < i / 2)
		return (j);
	else
		return (j * -1);
}

void	ft_sort(t_Node **a, t_Node **b, int max_rank)
{
	int	min;
	int	exec;

	min = 0;
	exec = 0;
	max_rank = find_max_rank_a(*a);
	ft_fill_b(a, b, max_rank);
	ft_sort_five(a, b, count_size_a(*a));
	while ((*b))
	{
		sort_extention2(a, b, min, exec);
		pa(a, b, 1);
		if ((*a)->rank > (*a)->next->rank)
			sa(a, 1);
	}
	min = find_min(*a);
	while ((*a)->rank != min)
	{
		if (find_r_or_rr(a, min))
			ra(a, 1);
		else
			rra(a, 1);
	}
}
