/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro < dcano-ro@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:06:15 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/09/25 12:09:20 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_node **head)
{
	t_node	*aux;
	t_node	*node;

	node = *head;
	while (node != NULL)
	{
		aux = node;
		node = node->next;
		free(aux);
	}
	write(2, "Error\n", 6);
	exit(-1);
}

int	process_splitted(char **splitted, t_node **head)
{
	int	j;

	j = 0;
	while (splitted[j])
	{
		error_or_added(splitted[j], head);
		free(splitted[j++]);
	}
	free(splitted[j]);
	free(splitted);
	return (0);
}

t_node	**parse(int argc, char **argv)
{
	char	**splitted;
	int		i;
	t_node	**head;

	i = 1;
	head = malloc(sizeof(t_node *));
	if (!head)
		exit(-1);
	*head = NULL;
	while (i < argc)
	{
		splitted = ft_split(argv[i++], ' ');
		if (splitted == NULL)
			error(head);
		process_splitted(splitted, head);
	}
	return (head);
}
