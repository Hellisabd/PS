/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:40:27 by bgrosjea          #+#    #+#             */
/*   Updated: 2024/01/12 14:56:36 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ft_find_best_rank(t_Node **a, t_Node **b)
{
	t_Node	*current_a;
	int		best_rank;

	current_a = *a;
	best_rank = find_max_rank_a(*a);
	while (current_a && *b)
	{
		if ((current_a->rank > (*b)->rank) && (best_rank > current_a->rank))
			best_rank = current_a->rank;
		current_a = current_a->next;
	}
	return (best_rank);
}

void	ft_final_sort(t_Node **a, t_Node **b)
{
	int		best_rank;

	if (!(*b) || !b)
		return ;
	while (ft_lstlast(*b)->rank > (*b)->rank
		&& ft_lstlast(*b)->rank < (*a)->rank)
		rrb(b, 1);
	best_rank = ft_find_best_rank(a, b);
	while ((*a)->rank != best_rank && *b)
	{
		if (find_r_or_rr(a, best_rank))
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	ft_check(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (argc > j)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			while (argv[j][i] == ' ')
				i++;
			if (argv[j][i] == '-')
				i++;
			if ((argv[j][i] == '\0' && argv[j][i - 1] == '-')
				|| argv[j][i] == '\0')
				exit((write(2, "Error\n", 6), EXIT_FAILURE));
			while (1 == ft_isdigit(argv[j][i]))
				i++;
			if (argv[j][i] != ' ' && argv[j][i] != '\0'
			&& argv[j][i + 1] != ' ')
				exit((write(2, "Error\n", 6), EXIT_FAILURE));
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
				write(2, "Error\n", 6);
				ft_free_stack(*a);
				exit (EXIT_FAILURE);
			}
			tmp = tmp->next;
		}
		size++;
		cmp = cmp->next;
	}
	return (size);
}

bool	find_r_or_rr(t_Node **a, int best_rank)
{
	int		cost;
	t_Node	*tmp;

	cost = 0;
	tmp = *a;
	while (tmp->rank != best_rank && tmp && tmp->next)
	{
		cost++;
		tmp = tmp->next;
	}
	if (cost > count_size_a(*a) / 2)
		return (false);
	return (true);
}
