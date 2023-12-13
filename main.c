/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:53:11 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/13 18:56:47 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "Libft/libft.h"
// https://www.youtube.com/watch?v=wRvipSG4Mmk
void	ft_print_stack(t_Node *a)
{
	t_Node	*tmp;

	while (a)
	{
		tmp = a->next;
		ft_printf("%d\n", a->nbr);
		free (a);
		a = tmp;
	}
}

t_Node	*ft_fill_a(t_Node *a, int argc, char **argv)
{
	t_Node	*new;
	int		number;
	int		i;
	
	a = NULL;
	i = 1;
	while (argc > i)
	{
		number = ft_atoi(argv[i]);
		new = ft_lstnew(number);
		if (!new)
		{
			ft_lstclear(&a);
			exit (EXIT_FAILURE);
		}
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}

int main(void)
{
	t_Node  *a;
	char *argv[8] = {"a.out", "1", "2", "3", "4", "5", "6"};
	int		argc;

	argc = 7;
	t_Node	*b;
	

	a = NULL;
	b = NULL;
	ft_error(argc, argv);
	a = ft_fill_a(a, argc, argv);
	pb(b, &a);
	pa(a, &b);
	ft_print_stack(a);
	return (0);
}