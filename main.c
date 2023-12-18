/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:53:11 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/18 13:53:50 by bgrosjea         ###   ########.fr       */
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
int	ft_fill_Node(t_Node **a, char **argv, int i)
{
	ssize_t		number;
	t_Node	*new;

	number = ft_atoi(argv[i]);
	if (number > INT_MAX || number < INT_MIN)
	{
		ft_printf("ERROR : int overflowed");
	}
	new = ft_lstnew(number);
	if (!new)
	{
		ft_lstclear(a);
		exit (EXIT_FAILURE);
	}
	ft_lstadd_back(a, new);
	return (i + 1);
}

t_Node	*ft_fill_a(t_Node *a, int argc, char **argv)
{
	int		i;
	char	**tmp;
	int		j;
	int		words;
	
	a = NULL;
	i = 1;
	tmp = NULL;
	while (argc > i)
	{
		words = count_words(argv[i], ' ');
		if (1 == words)
		{
			i = ft_fill_Node(&a, argv, i);
		}
		else
		{
			j = 0;
			tmp = ft_split(argv[i], ' ');
			while (j < words)
				j = ft_fill_Node(&a, tmp, j);
			i++;
		}
	}
	ft_free_double_tab(tmp);
	return (a);
}

int main(int argc, char **argv)
{
	t_Node  *a;
	// char *argv[14] = {"a.out", "110","9","168","7","16","5","1114","3","2","1","10","-1"};
	//  int		argc;
	int		size;

	//  argc = 13;
	size = 0;
	a = NULL;
	ft_error(argc, argv);
	ft_check(argc, argv);
	a = ft_fill_a(a, argc, argv);
	size = ft_check_same(&a, size);
	ft_sort(&a, argc);
	ft_print_stack(a);
	return (0);
}
