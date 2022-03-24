/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:26:59 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/24 20:13:11 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

# define DEFAULT_COST -1
/*				STRUCTS				*/
typedef struct s_info		t_info;
typedef struct s_stack		t_stack;
typedef struct s_list		t_list;
typedef struct s_decisions	t_decisions;

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

struct s_stack
{
	t_list	*head;
	int		len;
	int		min_id;
	int		median_id;
	int		max_id;
};

struct s_list
{
	int				id;
	int				value;
	struct s_list	*next;
};

struct s_decisions
{
	int	r;
	int	rr;
	int	cost;
};
/*				CHECK INPUT DATA			*/
void	check_parameters(int number, char **data);
/*				STRUCT UTILS				*/
void	reset_costs(t_info *info);
void	reset_default_costs(t_info *info);
int		append_id(t_stack *stack_a, char **data, int size);
int		find_median_id(t_list **lst);
int		find_min_id(t_list **lst);
// int		find_max_id(t_list **lst);
t_info	*create_main_struct(char **data, int size);
/*				LIST UTILS					*/
t_list	*create_node(int value);
t_list	*last_node(t_list *lst);
void	push_back(t_list **lst, t_list *node);
void	push_front(t_list **lst, t_list *node);
int		lstsize(t_list **lst);
/*				CREATE LIST					*/
t_list	*create_lst(char **data);
/*				COST UTILS					*/
int		rotate_a_cost(t_stack *stack_a, int b_id, int last_id);
int		rotate_b_cost(t_stack *stack_b, int b_id);
int		reverse_rotate_a_cost(t_stack *stack_a, int b_id, int last_id);
int		reverse_rotate_b_cost(t_stack *stack_b, int b_id);
/*				INSERTION UTILS				*/
void	find_costs_manager(t_info *info);
void	insertion(t_info *info);
void	make_stack_great_again(t_stack *stack_a);
/*				PRE SORT UTILS				*/
void	fill_b(t_info *info);
void	double_sort(t_stack *stack);
void	triple_sort(t_stack *stack);
void	fifth_sort(t_info *info);
void	sort_small_numbers(t_info *info, int size);
/*					SWAP					*/
void	do_swap(t_list **lst, char *op_name);
void	swap_ab(t_list **lst_a, t_list **lst_b);
/*					PUSH					*/
void	push_a(t_list **lst_a, t_list **lst_b);
void	push_b(t_list **lst_a, t_list **lst_b);
/*				   ROTATE					*/
void	do_rotate(t_list **lst, char *op_name);
void	rotate_ab(t_list **lst_a, t_list **lst_b);
/*				REVERSE ROTATE				*/
void	do_reverse_rotate(t_list **lst, char *op_name);
void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b);
/*				PRINT UTILS					*/
void	print_op(char *op);
void	print_one_stack_with_id(t_stack *stack, char *name);
void	print_max_min_mid(t_stack *stack);
void	print_found_cost(t_info *info);
void	print_stacks_with_ids(t_stack *a, t_stack *b);

#endif
