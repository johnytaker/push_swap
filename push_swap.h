/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:26:59 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/10 19:53:38 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	long int		id;
	long int		data;
	struct s_list	*next;
}				t_list;

void	check_parameters(int number, char **data);

t_list	*create_node(int data);
t_list	*last_node(t_list *lst);
void	push_back(t_list **lst, t_list *new);
void	push_front(t_list **lst, t_list *new);
t_list	*create_lst(char **data);
t_list	*append_ids(t_list **lst, char **data, int size);

int		*int_arr_create(char **data, int number);
int		*bubble_sort_id(int *data, int size);

void	swap_a(t_list **lst_a);
void	swap_b(t_list **lst_b);
void	swap_ab(t_list **lst_a, t_list **lst_b);

void	push_a(t_list **lst_a, t_list **lst_b);
void	push_b(t_list **lst_a, t_list **lst_b);

void	rotate_a(t_list **lst_a);
void	rotate_b(t_list **lst_b);
void	rotate_ab(t_list **lst_a, t_list **lst_b);

void	reverse_rotate_a(t_list **lst_a);
void	reverse_rotate_b(t_list **lst_b);
void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b);


#endif