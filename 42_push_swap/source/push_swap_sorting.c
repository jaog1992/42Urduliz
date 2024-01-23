/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:27:08 by jde-orma          #+#    #+#             */
/*   Updated: 2023/11/01 21:27:08 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"
#include <stdlib.h>

void	ft_sort_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_three_a(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		ft_sa(s, EXECUTE);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		ft_sa(s, EXECUTE);
		ft_rra(s, EXECUTE);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ft_ra(s, EXECUTE);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		ft_sa(s, EXECUTE);
		ft_ra(s, EXECUTE);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		ft_rra(s, EXECUTE);
}

int	ft_sort(t_stack *stack, int size)
{
	if (ft_check_sorted(stack->a, stack->size_a, ASCENDING) == 1)
	{
		if (size == 2)
			ft_sa(stack, EXECUTE);
		else if (size == 3)
			ft_sort_three_a(stack);
		else
			ft_quicksort_a(stack, size, 0);
	}
	return (0);
}

int	ft_push(t_stack *stack, int len, int operation)
{
	if (operation == 0)
		ft_pb(stack, EXECUTE);
	else
		ft_pa(stack, EXECUTE);
	len--;
	return (len);
}
