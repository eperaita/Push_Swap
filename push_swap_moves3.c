/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:27:18 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/14 17:31:20 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_rotate_a(t_list **head_a, int check)
{
	t_list	*temp;

	if (!*head_a)
		return ;
	temp = *head_a;
	*head_a = temp->next;
	ft_lstadd_back(head_a, temp);
	temp->next = NULL;
	if (check == 0)
		write(1, "ra\n", 3);
}

void	ft_rotate_b(t_list **head_b, int check)
{
	t_list	*temp;

	if (!*head_b)
		return ;
	temp = *head_b;
	*head_b = temp->next;
	ft_lstadd_back(head_b, temp);
	temp->next = NULL;
	if (check == 0)
		write(1, "rb\n", 3);
}

void	ft_rotate_ab(t_list **head_a, t_list **head_b)
{
	if (!*head_a || !*head_b)
		return ;
	ft_rotate_a(head_a, 1);
	ft_rotate_b(head_b, 1);
	write(1, "rr\n", 3);
}
