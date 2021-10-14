/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:02:48 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/14 18:15:11 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

/////// LIST CREATION ///////
void	ft_newnode(t_list **head, size_t num)
{
	t_list	*new;

	new = NULL;
	new = ft_lstnew((void *)num);
	ft_lstadd_back(head, new);
}

void	ft_get_args(int argc, char **argv, t_list **head_a)
{
	int		n;
	char	**str;

	n = 1;
	if (argc != 2)
	{
		ft_nonum(argv);
		while (n < argc)
			ft_newnode(head_a, ft_atoi(argv[n++]));
	}
	else
	{
		if (!ft_strlen(argv[1]))
			exit (0);
		str = ft_split(argv[n], ' ');
		ft_nonum(str);
		n = 0;
		while (str[n])
			ft_newnode(head_a, ft_atoi(str[n++]));
		while (n != 0)
			free (str[--n]);
		free (str);
	}
}

/////// ERRORS ///////

void	ft_nonum(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (str[i][j] == '.')
		i++;
	while (str[i])
	{
		while (str[i][j])
		{
			if (!ft_isdigit((str[i][j])) && str[i][j] != '-')
			{
				write(2, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_norepeat(t_list **head_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *head_a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp2->content == tmp1->content)
			{
				write(2, "Error\n", 6);
				exit (0);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

///////// MAIN ////////

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		return (1);
	ft_get_args(argc, argv, &head_a);
	ft_norepeat(&head_a);
	if (ft_sizeofchunk(head_a, head_a->chunk) == 3)
		ft_caseof3(&head_a);
	else
		ft_quicksort(&head_a, &head_b);
	ft_freelist(head_a);
	ft_freelist(head_b);
	return (0);
}
