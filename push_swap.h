/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:26:59 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/02 17:27:17 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				id;
	int				data;
	struct s_list	*next;
}				t_list;

void	check_parameters(int number, char **data);

t_list	*create_node(int data);
t_list	*last_node(t_list *lst);
void	push_back(t_list **lst, t_list *node);
void	push_front(t_list **lst, t_list *node);
int		lstsize(t_list **lst);

t_list	*create_lst(char **data);

int		*int_arr_create(char **data);
void	quick_sort(int *data, int size);
void	append_id(t_list **lst, char **data, int size);

void	push_b_less_then_median(t_list **lst_a, t_list **lst_b);
void	push_b_more_then_median(t_list **lst_a, t_list **lst_b);
void	push_all_b(t_list **lst_a, t_list **lst_b);
void	triple_sort_a(t_list **lst_a);

int		find_smallest_id(t_list **lst);
int		find_biggest_id(t_list **lst);
int		find_median_id(t_list **lst);

/*					SWAP					*/
void	swap_a(t_list **lst_a);
void	swap_b(t_list **lst_b);
void	swap_ab(t_list **lst_a, t_list **lst_b);
/*					PUSH					*/
void	push_a(t_list **lst_a, t_list **lst_b);
void	push_b(t_list **lst_a, t_list **lst_b);
/*				   ROTATE					*/
void	rotate_a(t_list **lst_a);
void	rotate_b(t_list **lst_b);
void	rotate_ab(t_list **lst_a, t_list **lst_b);
/*				REVERSE ROTATE				*/
void	reverse_rotate_a(t_list **lst_a);
void	reverse_rotate_b(t_list **lst_b);
void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b);

#endif
