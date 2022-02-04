/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:26:59 by iugolin           #+#    #+#             */
/*   Updated: 2022/02/04 17:32:55 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

// typedef struct s_list
// {
// 	int				data;
// 	struct s_list	*next;
// }				t_list;

// t_list	*create_list(int argc, char **argv);
t_list	*create_lst(char **data);
int		is_input_sorted(char **data);
int		is_input_repeat(char **data);

#endif