/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:53:11 by bgrosjea          #+#    #+#             */
/*   Updated: 2024/01/12 14:22:11 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "Libft/libft.h"

int	main(int argc, char **argv)
{
	t_Node	*a;
	t_Node	*b;
	int		size;

	size = 0;
	a = NULL;
	b = NULL;
	ft_error(argc);
	ft_check(argc, argv);
	a = ft_fill_a(a, argc, argv);
	size = ft_check_same(&a, size);
	if (a_is_sorted(a))
	{
		ft_free_stack(a);
		return (0);
	}
	if (5 >= ft_find_rank(&a))
		ft_sort_five(&a, &b, size);
	else
		ft_sort(&a, &b, size);
	ft_free_stack(a);
	return (0);
}
