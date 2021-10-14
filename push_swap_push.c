/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:09:16 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/12 12:39:20 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_nopush_b(t_list **src, int rotate)
{
	ft_rotate_b(src, 0);
	rotate++;
	return (rotate);
}

int	ft_push_push_b(t_list **src, t_list **dest, int chunk, int pushed)
{
	(*src)->chunk = chunk;
	ft_push_a(dest, src, 0);
	pushed--;
	return (pushed);
}

void	ft_push_chunk_b(t_list **src, t_list **dest, int act_chunk)
{
	int			pushed;
	static int	chunk;
	int			pivot;
	int			rotate;

	pivot = 0;
	rotate = 0;
	if (!chunk)
		chunk = 1;
	pivot = ft_set_pivot(pivot, *src, (*src)->chunk, -1);
	pushed = ft_sizeofchunk(*src, act_chunk)
		- (ft_sizeofchunk(*src, act_chunk) / 2);
	while (pushed)
	{
		if (((int)(*src)->content) > pivot)
			pushed = ft_push_push_b(src, dest, chunk, pushed);
		else
			rotate = ft_nopush_b(src, rotate);
	}
	while (rotate--)
		ft_reverse_b(src, 0);
	chunk++;
}

int	ft_nopush_a(t_list **src, int pivot, int rotate)
{
	if ((int)ft_lstlast(*src)->content < pivot
		&& ft_sizeofchunk(*src, (*src)->chunk) == ft_lstsize(*src))
		ft_reverse_a(src, 0);
	else
	{
		ft_rotate_a(src, 0);
		rotate++;
	}
	return (rotate);
}

void	ft_push_chunk_a(t_list **src, t_list **dest, int act_chunk, int first)
{
	int			pushed;
	static int	chunk;
	int			pivot;
	int			rotate;

	pivot = 0;
	rotate = 0;
	pivot = ft_set_pivot(pivot, *src, (*src)->chunk, 1);
	pushed = ft_sizeofchunk(*src, act_chunk)
		- (ft_sizeofchunk(*src, act_chunk) / 2);
	while (pushed)
	{
		if (((int)(*src)->content) < pivot)
		{
			(*src)->chunk = chunk;
			ft_push_b(src, dest, 0);
			pushed--;
		}
		else
			rotate = ft_nopush_a(src, pivot, rotate);
	}
	while (rotate-- && !first)
		ft_reverse_a(src, 0);
	chunk++;
}
