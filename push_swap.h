/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:26:59 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/23 12:04:42 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

# define DEFAULT_COST -1

typedef struct s_list		t_list;
typedef struct s_info		t_info;
typedef struct s_stack		t_stack;
typedef struct s_decisions	t_decisions;

struct s_list
{
	int				id;
	int				value;
	struct s_list	*next;
};

struct s_stack
{
	t_list	*head;
	int		len;
	int		min_id;
	int		median_id;
	int		max_id;
};

struct s_decisions
{
	int	r;
	int	rr;
	int	cost;
};

struct s_info
{
	t_stack	*a;
	t_stack	*b;
	int		min_cost;
	int		pop_ind;
	int		ra_ct;
	int		rb_ct;
	int		rra_ct;
	int		rrb_ct;
};
/*				CHECK INPUT DATA			*/
void	check_parameters(int number, char **data);
/*				CREATE STRUCT				*/
void	reset_costs(t_info *info);
void	reset_default_costs(t_info *info);
t_info	*create_main_struct(char **data, int size);
/*				LIST UTILS					*/
t_list	*create_node(int value);
t_list	*last_node(t_list *lst);
void	push_back(t_list **lst, t_list *node);
void	push_front(t_list **lst, t_list *node);
int		lstsize(t_list **lst);

t_list	*create_lst(char **data);

int		find_min_id(t_list **lst);
int		find_max_id(t_list **lst);
int		find_median_id(t_list **lst);

int		append_id(t_stack *stack_a, char **data, int size);

int		rotate_a_cost(t_stack *stack_a, int b_id, int last_id);
int		rotate_b_cost(t_stack *stack_b, int b_id);

int		reverse_rotate_a_cost(t_stack *stack_a, int b_id, int last_id);
int		reverse_rotate_a_cost_orig(t_stack *stack_a, int b_id);

int		reverse_rotate_b_cost(t_stack *stack_b, int b_id);

void	insertion(t_info *info);
void	finish_sort(t_stack *stack_a);

void	fill_b(t_info *info);

void	triple_sort_a(t_stack *stack_a);
void	sort_all(t_list **lst_a, t_list **lst_b);

/*					SWAP					*/
void	swap_a(t_list **lst_a);
void	swap_b(t_list **lst_b);
void	swap_ab(t_list **lst_a, t_list **lst_b);
/*					PUSH					*/
void	push_a(t_list **lst_a, t_list **lst_b);
void	push_b(t_list **lst_a, t_list **lst_b);
/*				   ROTATE					*/

void	do_rotate(t_list **lst, char *op_name);
// void	rotate_a(t_list **lst_a);
// void	rotate_b(t_list **lst_b);
void	rotate_ab(t_list **lst_a, t_list **lst_b);
/*				REVERSE ROTATE
*/

void	do_reverse_rotate(t_list **lst, char *op_name);
// void	reverse_rotate_a(t_list **lst_a);
// void	reverse_rotate_b(t_list **lst_b);
void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b);

void	print_op(char *op);

void	print_one_stack_with_id(t_stack *stack, char *name);
void	print_max_min_mid(t_stack *stack);
void	print_found_cost(t_info *info);
void	print_stacks_with_ids(t_stack *a, t_stack *b);

#endif
