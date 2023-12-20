/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:53:11 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/20 19:29:54 by bgrosjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "Libft/libft.h"
// https://www.youtube.com/watch?v=wRvipSG4Mmk
void	ft_free_stack(t_Node *a)
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

bool	ft_check_back(t_Node *a)
{
	t_Node	*tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	if ((tmp->rank) < (a->rank))
		return (true);
	return (false);
}

int main(int argc, char **argv)
{
	t_Node  *a;
	// char *argv[3] = {"a.out","15 34 38 17 28 41 10 20 2 23 42 3 35 21 6 25 1 31 13 8 22 5 33 32 11 16 24 4 27 44 30 7 26 12 29 45 37 39 43 18 14 9 19 40 36"};
	// int		argc;
	t_Node  *b;
	int		size;

	// argc = 2;
	size = 0;
	a = NULL;
	b = NULL;
	ft_error(argc, argv);
	ft_check(argc, argv);
	a = ft_fill_a(a, argc, argv);
	size = ft_check_same(&a, size);
	if (a_is_sorted(a))
		return (0);
	if (5 >= ft_find_rank(&a))
		ft_sort_five(&a, &b, size);
	else 
		ft_sort(&a, &b, size);
	if (a_is_sorted(a))
		ft_printf("OK");
	else 
		ft_printf("KO");
	ft_free_stack(a);
	return (0);
}
