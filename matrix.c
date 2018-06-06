/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:27:27 by dlyubich          #+#    #+#             */
/*   Updated: 2018/05/02 15:27:29 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			lstlen(t_list *list)
{
	int		i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void		lst_free(t_list **list)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *list;
	while (tmp != NULL)
	{
		next = tmp->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
		tmp = next;
	}
	*list = NULL;
}

void		fill_matrix(t_lem *ant)
{
	t_room	*tmp;
	t_list	*tmp2;
	t_list	*rooms;
	int		*num;
	int		i;

	i = 0;
	rooms = ant->rooms;
	while (rooms)
	{
		tmp = (t_room*)rooms->content;
		tmp2 = tmp->link;
		i = tmp->id;
		while (tmp2)
		{
			num = (int*)tmp2->content;
			ant->matrix[i][*num] = 1;
			tmp2 = tmp2->next;
		}
		rooms = rooms->next;
	}
}

void		ft_create_matrix(t_lem *ant)
{
	int		**mas;
	int		i;

	mas = (int**)malloc(sizeof(int*) * ant->room_num);
	if (!mas)
		my_error();
	i = 0;
	while (i < ant->room_num)
	{
		mas[i] = (int*)malloc(sizeof(int) * ant->room_num);
		ft_bzero(mas[i], ant->room_num * sizeof(int));
		i++;
	}
	ant->matrix = mas;
	fill_matrix(ant);
}

void		ft_create_visit_matrix(t_lem *ant)
{
	int		*mas;

	mas = (int*)malloc(sizeof(int) * ant->room_num);
	ft_bzero(mas, sizeof(int) * ant->room_num);
	if (!mas)
		my_error();
	ant->visit = mas;
}
