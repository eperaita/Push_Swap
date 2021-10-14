/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:14:43 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/14 17:40:56 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//////////UTILS/////////

int	ft_maxint(int catched, t_list *src, int chunk, int neg)
{
	int	new;

	new = -2147483648;
	if (neg == -1)
		new = 2147483647;
	while (neg == 1 && src && src->chunk == chunk)
	{
		if ((int)src->content * neg < catched && (int)src->content * neg > new)
			new = (int)src->content;
		src = src->next;
	}
	while (neg == -1 && src && src->chunk == chunk)
	{
		if ((int)src->content > catched && (int)src->content < new)
			new = (int)src->content;
		src = src->next;
	}
	return (new);
}

int	ft_set_pivot(int pivot, t_list *src, int chunk, int neg)
{
	int	size;
	int	catched;

	size = ft_sizeofchunk(src, chunk);
	size /= 2;
	if (neg == 1)
		catched = 2147483647;
	if (neg == -1)
		catched = -2147483648;
	while (src && size)
	{
		catched = ft_maxint(catched, src, chunk, neg);
		size--;
	}
	pivot = catched;
	return (pivot);
}

int	ft_sizeofchunk(t_list *src, int chunk)
{
	int	i;

	i = 0;
	if (!src)
		return (0);
	while (src && src->chunk == chunk)
	{
		src = src->next;
		i++;
	}
	return (i);
}

int	ft_check_sorted(t_list *head, int chunk, char list)
{
	int	neg;

	if (list == 'a')
		neg = 1;
	if (list == 'b')
		neg = -1;
	while (head->next && head->chunk == chunk)
	{
		if ((int)head->content * neg > (int)head->next->content * neg)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_freelist(t_list *head)
{
	t_list	*temp;

	if (!head)
		return ;
	while (head)
	{
		temp = head;
		head = head->next;
		free (temp);
	}
}
