/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro < dcano-ro@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:22:49 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/09/25 12:13:30 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			content;
	struct node	*next;
}	t_node;

char	**ft_split(char const *str, char c);
t_node	**parse(int argc, char **argv);
long	ft_atoi(const char *str);
int		is_duplicate(t_node **head, int elem);
void	add(t_node **head, int new_elem);
int		error_or_added(char *new, t_node **head);
int		is_digit(char *str);
int		error(t_node **head);
t_node	**copy(t_node **head, t_node *first);
int		is_ordered(t_node **head);
void	order(t_node **head);
void	cambiar_positivo(t_node **original, t_node **ordered);
void	ordena_stack(t_node **head);
void	free_list(t_node **head);
void	add_first(t_node **head, int new_elem, t_node **head2);
t_node	*delete_node(t_node **head, t_node *n1, t_node *prev);
void	ra(t_node **head);
void	sb(int *b, int size);
void	big_stack(t_node **head);
int		eval(t_node *aux, int bi, int size);
#endif