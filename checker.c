/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:00:38 by bgrosjea          #+#    #+#             */
/*   Updated: 2024/01/12 14:53:44 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "Libft/libft.h"

int	move(t_Node **a, t_Node **b, char *str)
{
	if (0 == ft_strncmp(str, "sa\n", 3))
		sa(a, 0);
	else if (0 == ft_strncmp(str, "sb\n", 3))
		sb(b, 0);
	else if (0 == ft_strncmp(str, "pa\n", 3))
		pa(a, b, 0);
	else if (0 == ft_strncmp(str, "pb\n", 3))
		pb(b, a, 0);
	else if (0 == ft_strncmp(str, "ra\n", 3))
		ra(a, 0);
	else if (0 == ft_strncmp(str, "rb\n", 3))
		rb(b, 0);
	else if (0 == ft_strncmp(str, "rra\n", 4))
		rra(a, 0);
	else if (0 == ft_strncmp(str, "rrb\n", 4))
		rrb(b, 0);
	else if (0 == ft_strncmp(str, "ss\n", 3))
		ss(a, b, 0);
	else if (0 == ft_strncmp(str, "rr\n", 3))
		rr(a, b, 0);
	else if (0 == ft_strncmp(str, "rrr\n", 4))
		rrr(a, b, 0);
	else
		return ((write(2, "Error\n", 6), 0));
	return (1);
}

void	aff(t_Node *a, t_Node *b)
{
	if (a_is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_Node	*a;
	t_Node	*b;
	char	*str;

	a = NULL;
	b = NULL;
	ft_error(argc);
	ft_check(argc, argv);
	a = ft_fill_a(a, argc, argv);
	ft_check_same(&a, 0);
	while (1)
	{
		str = get_next_line(0);
		if (!str || *str == '\n')
			break ;
		if (0 == move(&a, &b, str))
			break ;
		free (str);
	}
	if (str)
		free (str);
	aff(a, b);
	return (ft_free_stack(a), ft_free_stack(b), 0);
}
