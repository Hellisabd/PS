/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrosjea <bgrosjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:53:11 by bgrosjea          #+#    #+#             */
/*   Updated: 2023/12/21 19:47:09 by bgrosjea         ###   ########.fr       */
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
		// ft_printf("%d\n", a->nbr);
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
	
	// char *argv[3] = {"a.out","16 10 89 44 50 63 54 45 8 96 26 100 55 72 61 86 67 29 23 97 41 64 15 4 91 88 70 7 62 38 42 49 80 75 12 47 3 77 59 85 5 87 17 60 24 46 36 39 1 31 2 84 94 30 19 48 68 11 21 76 71 90 83 81 58 98 65 37 18 56 79 95 22 33 78 27 51 92 9 53 28 74 99 20 34 57 6 52 43 13 32 93 73 82 14 25 69 40 35 66 "};
	//  int		argc;
	// argc = 2;
	t_Node  *b;
	int		size;

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
