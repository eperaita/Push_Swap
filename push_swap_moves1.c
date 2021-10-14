/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:29:58 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/14 18:13:25 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

////////// MOVES 1 ///////////

void	ft_swap_a(t_list **head_a, int check)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head_a;
	tmp2 = (*head_a)->next;
	if (!tmp1 || !tmp2)
		return ;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*head_a = tmp2;
	if (check == 0)
		write(1, "sa\n", 3);
}

void	ft_swap_b(t_list **head_b, int check)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!*head_b)
		return ;
	tmp1 = *head_b;
	tmp2 = (*head_b)->next;
	if (!tmp1 || !tmp2)
		return ;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*head_b = tmp2;
	if (check == 0)
		write(1, "sb\n", 3);
}

void	ft_swap_ab(t_list **head_a, t_list **head_b)
{
	if (!*head_a || !*head_b)
		return ;
	ft_swap_a(head_a, 1);
	ft_swap_b(head_b, 1);
	write(1, "ss\n", 3);
}

void	ft_push_a(t_list **head_a, t_list **head_b, int check)
{
	t_list	*temp;

	if (!*head_b)
		return ;
	temp = *head_b;
	temp = temp->next;
	ft_lstadd_front(head_a, *head_b);
	*head_b = temp;
	if (check == 0)
		write(1, "pa\n", 3);
}

void	ft_push_b(t_list **head_a, t_list **head_b, int check)
{
	t_list	*temp;

	if (!*head_a)
		return ;
	temp = *head_a;
	temp = temp->next;
	ft_lstadd_front(head_b, *head_a);
	*head_a = temp;
	if (check == 0)
		write(1, "pb\n", 3);
}
