/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:10:43 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/14 18:14:08 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_reverse_a(t_list **head_a, int check)
{
	t_list	*tail;
	t_list	*temp;

	if (!*head_a)
		return ;
	tail = *head_a;
	temp = *head_a;
	tail = ft_lstlast(tail);
	ft_lstadd_front(head_a, tail);
	while (temp->next != tail)
		temp = temp->next;
	temp->next = NULL;
	if (check == 0)
		write(1, "rra\n", 4);
}

void	ft_reverse_b(t_list **head_b, int check)
{
	t_list	*tail;
	t_list	*temp;

	if (!*head_b)
		return ;
	tail = *head_b;
	temp = *head_b;
	tail = ft_lstlast(tail);
	ft_lstadd_front(head_b, tail);
	while (temp->next != tail)
		temp = temp->next;
	temp->next = NULL;
	if (check == 0)
		write(1, "rrb\n", 4);
}

void	ft_reverse_ab(t_list **head_a, t_list **head_b)
{
	if (!*head_a || !*head_b)
		return ;
	ft_reverse_a(head_a, 1);
	ft_reverse_b(head_b, 1);
	write(1, "rrr\n", 4);
}
