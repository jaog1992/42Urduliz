/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:27:36 by jde-orma          #+#    #+#             */
/*   Updated: 2023/11/01 21:27:36 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"
#include <stdlib.h>


void	ft_quicksort_3(t_stack *stack, int size)
{
	if (size == 3 && stack->size_a == 3)
		ft_sort_three_a(stack);
	else if (size == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack, EXECUTE);
	}
	else if (size == 3)
	{
		while (size != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (size == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack, EXECUTE);
			else if (size == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				size = ft_push(stack, size, 0);
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack, EXECUTE);
			else if (size++)
				ft_pa(stack, EXECUTE);
		}
	}
}

int	ft_sort_small_b(t_stack *s, int size)
{
	if (size == 1)
		ft_pa(s, EXECUTE);
	else if (size == 2)
	{
		if (s->b[0] < s->b[1])
			ft_sb(s, EXECUTE);
		while (size--)
			ft_pa(s, EXECUTE);
	}
	else if (size == 3)
	{
		while (size || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (size == 1 && s->a[0] > s->a[1])
				ft_sa(s, EXECUTE);
			else if (size == 1 || (size >= 2 && s->b[0] > s->b[1])
				|| (size == 3 && s->b[0] > s->b[2]))
				size = ft_push(s, size, 1);
			else
				ft_sb(s, EXECUTE);
		}
	}
	return (0);
}

int	ft_get_mediane(int *pivot, int *stack, int size)
{
	int		*tmp_stack;
	int		i;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	ft_sort_tmp(tmp_stack, size);
	*pivot = tmp_stack[size / 2];
	free(tmp_stack);
	return (EXIT_SUCCESS);
}

int	ft_quicksort_a(t_stack *stack, int size, int cnt)
{
	int	pivot;
	int	items;

	if (ft_check_sorted(stack->a, size, ASCENDING) == 0)
		return (EXIT_SUCCESS);
	items = size;
	if (size <= 3)
	{
		ft_quicksort_3(stack, size);
		return (EXIT_SUCCESS);
	}
	if (!cnt && ft_get_mediane(&pivot, stack->a, size))
		return (EXIT_FAILURE);
	while (size != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (size--))
			ft_pb(stack, EXECUTE);
		else if (++cnt)
			ft_ra(stack, EXECUTE);
	}
	while (items / 2 + items % 2 != stack->size_a && cnt--)
		ft_rra(stack, EXECUTE);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0) == EXIT_SUCCESS 
			&& ft_quicksort_b(stack, items / 2, 0) == EXIT_SUCCESS);
}

//revisar lo que devuelve
int	ft_quicksort_b(t_stack *stack, int size, int cnt)
{
	int	pivot;
	int	items;

	if (!cnt && ft_check_sorted(stack->b, size, DESCENDING) == 0)
		while (size--)
			ft_pa(stack, EXECUTE);
	if (size <= 3)
	{
		ft_sort_small_b(stack, size);
		return (EXIT_SUCCESS);
	}
	items = size;
	if (ft_get_mediane(&pivot, stack->b, size))
		return (EXIT_FAILURE);
	while (size != items / 2)
	{
		if (stack->b[0] >= pivot && size--)
			ft_pa(stack, EXECUTE);
		else if (++cnt)
			ft_rb(stack, EXECUTE);
	}
	while (items / 2 != stack->size_b && cnt--)
		ft_rrb(stack, EXECUTE);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0) == EXIT_SUCCESS
		&& ft_quicksort_b(stack, items / 2, 0)  == EXIT_SUCCESS);
}
