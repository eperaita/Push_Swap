/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:54:34 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/12 13:00:24 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"libft/libft.h"

/////////ERRORS/////////
void	ft_nonum(char **str);
void	ft_norepeat(t_list **head_a);
///////LINKED LIST CREATION//////
void	ft_get_args(int argc, char **argv, t_list **head_a);
void	ft_newnode(t_list **head, size_t num);
////MOVES (1,2,3)/////
void	ft_swap_a(t_list **head_a, int check);
void	ft_swap_b(t_list **head_b, int check);
void	ft_swap_ab(t_list **head_a, t_list **head_b);
void	ft_push_a(t_list **head_a, t_list **head_b, int check);
void	ft_push_b(t_list **head_a, t_list **head_b, int check);
void	ft_reverse_a(t_list **head_a, int check);
void	ft_reverse_b(t_list **head_b, int check);
void	ft_reverse_ab(t_list **head_a, t_list **head_b);
void	ft_rotate_a(t_list **head_a, int check);
void	ft_rotate_b(t_list **head_b, int check);
void	ft_rotate_ab(t_list **head_a, t_list **head_b);
///////////UTILS/////////
int		ft_maxint(int catched, t_list *src, int chunk, int neg);
int		ft_set_pivot(int pivot, t_list *src, int chunk, int neg);
int		ft_sizeofchunk(t_list *src, int chunk);
int		ft_check_sorted(t_list *head, int chunk, char list);
void	ft_freelist(t_list *head);
///////////PUSH/////////
int		ft_nopush_b(t_list **src, int rotate);
int		ft_push_push_b(t_list **src, t_list **dest, int chunk, int pushed);
void	ft_push_chunk_b(t_list **src, t_list **dest, int act_chunk);
int		ft_nopush_a(t_list **src, int pivot, int rotate);
void	ft_push_chunk_a(t_list **src, t_list **dest, int act_chunk, int first);
////////QUICKSORT//////
void	ft_caseof3(t_list **head);
void	ft_overturn(t_list **head_a, t_list **head_b);
void	ft_swap(t_list **head_a, t_list **head_b);
void	ft_chunk_zero(t_list **head_a, int chunk);
void	ft_quicksort(t_list **head_a, t_list **head_b);

#endif
