/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 04:49:52 by jde-orma          #+#    #+#             */
/*   Updated: 2023/10/31 04:49:52 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libraries/libft/include/libft.h"

typedef struct s_stack
{
	int error;
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

# define ASCENDING 0
# define DESCENDING 1
# define EXECUTE 0
# define DO_NOTHING 1

//Moves
void	ft_pa(t_stack *stack, int mode);
void	ft_pb(t_stack *stack, int mode);
void	ft_ra(t_stack *stack, int mode);
void	ft_rb(t_stack *stack, int mode);
void	ft_rr(t_stack *stack, int mode);
void	ft_sa(t_stack *stack, int mode);
void	ft_sb(t_stack *stack, int mode);
void	ft_ss(t_stack *stack, int mode);
void	ft_rra(t_stack *stack, int mode);
void	ft_rrb(t_stack *stack, int mode);
void	ft_rrr(t_stack *stack, int mode);
// Utilities
void	ft_error(t_stack *stack);
int		ft_atoi2(char *str, t_stack *stack);
int		ft_check_duplicates(int *stack, int len);
int		ft_check_sorted(int *stack, int size, int order);
int*	resizeArray(int *array, size_t oldSize, size_t newSize);
//Sorting functions
int		ft_sort_small_b(t_stack *s, int len);
int		ft_get_mediane(int *pivot, int *stack, int size);
int		ft_quicksort_a(t_stack *stack, int len, int cnt);
int		ft_quicksort_b(t_stack *stack, int len, int cnt);
void	ft_sort_tmp(int *tmp_stack, int size);
void	ft_sort_three_a(t_stack *s);
int		ft_sort(t_stack *stack, int size);
int		ft_push(t_stack *stack, int len, int operation);

#endif
