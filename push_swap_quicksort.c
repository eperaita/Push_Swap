/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:02:18 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/14 17:40:34 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_caseof3(t_list **head)
{
	t_list	*temp;
	int		max;
	int		min;

	temp = *head;
	max = ft_maxint(2147483647, *head, (*head)->chunk, 1);
	min = 2147483647;
	while (temp)
	{
		if ((int)temp->content < min)
			min = (int)temp->content;
		temp = temp->next;
	}
	temp = ft_lstlast(*head);
	while (head && !ft_check_sorted(*head, (*head)->chunk, 'a'))
	{
		if ((int)temp->content == min && (int)(*head)->content != max)
			ft_reverse_a(head, 0);
		else if ((int)temp->content != min && (int)(*head)->content == max)
			ft_rotate_a(head, 0);
		else
			ft_swap_a(head, 0);
	}
}

void	ft_overturn(t_list **head_a, t_list **head_b)
{
	int	size;

	size = ft_sizeofchunk(*head_b, (*head_b)->chunk);
	while (size)
	{
		(*head_b)->chunk = 0;
		ft_push_a(head_a, head_b, 0);
		size--;
	}
}

void	ft_swap(t_list **head_a, t_list **head_b)
{
	if (ft_sizeofchunk(*head_a, (*head_a)->chunk) == 2
		&& !ft_check_sorted(*head_a, (*head_a)->chunk, 'a'))
	{
		ft_swap_a(head_a, 0);
		ft_chunk_zero(head_a, (*head_a)->chunk);
	}
	if (ft_sizeofchunk(*head_b, (*head_b)->chunk) == 2
		&& !ft_check_sorted(*head_b, (*head_b)->chunk, 'b'))
		ft_swap_b(head_b, 0);
}

void	ft_chunk_zero(t_list **head_a, int chunk)
{
	t_list	*temp;

	temp = *head_a;
	while (temp && temp->chunk == chunk)
	{
		temp->chunk = 0;
		temp = temp->next;
	}
}

void	ft_quicksort(t_list **head_a, t_list **head_b)
{
	int	first;

	first = 1;
	while (!ft_check_sorted(*head_a, (*head_a)->chunk, 'a') || *head_b)
	{
		if (ft_check_sorted(*head_a, (*head_a)->chunk, 'a'))
			ft_chunk_zero(head_a, (*head_a)->chunk);
		while (ft_sizeofchunk(*head_a, (*head_a)->chunk) > 2
			&& !ft_check_sorted(*head_a, (*head_a)->chunk, 'a'))
			ft_push_chunk_a(head_a, head_b, (*head_a)->chunk, first);
		first = 0;
		ft_swap(head_a, head_b);
		if (ft_sizeofchunk(*head_b, (*head_b)->chunk) <= 2)
			ft_overturn(head_a, head_b);
		if (*head_b)
		{
			if (ft_check_sorted(*head_b, (*head_b)->chunk, 'b'))
				ft_overturn(head_a, head_b);
			else
				ft_push_chunk_b(head_b, head_a, (*head_b)->chunk);
		}
	}
}
