/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:49:50 by dlyubich          #+#    #+#             */
/*   Updated: 2018/02/19 12:49:51 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_doubles(t_list *tmp, t_list *list, int j)
{
	t_list	*tmp2;
	int		*id;

	while (tmp != NULL)
	{
		tmp2 = (t_list*)tmp->content;
		while (tmp2)
		{
			id = tmp2->content;
			if (*id == j && list->content != NULL && tmp->content != NULL)
			{
				if (lstlen(list->content) < lstlen(tmp->content))
					lst_free((t_list**)&tmp->content);
				else
					lst_free((t_list**)&list->content);
				return ;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void		check_dou(t_lem *ant, t_list *list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ant->room_num)
	{
		if (ant->visit[i] == 1)
			ant->visit[i] = 0;
		i++;
	}
	while (j < ant->room_num)
	{
		if (ant->visit[j] > 2)
		{
			ant->visit[j] = 2;
			ft_doubles(ant->roads, list, j);
		}
		j++;
	}
}

int			end(t_lem *ant, int id, t_list *list)
{
	if (id == ant->end_id)
		return (1);
	if (ant->matrix[id][ant->end_id] == 1 || id == ant->end_id)
	{
		ft_lstadd((t_list**)&list->content,
		ft_lstnew(&ant->end_id, sizeof(int)));
		return (1);
	}
	return (0);
}

int			find_solution(t_lem *ant, int id, t_list *list, int prev)
{
	int		i;

	i = 0;
	if (end(ant, id, list))
		return (1);
	while (i < ant->room_num)
	{
		if (ant->matrix[i][id] == 1 && ant->visit[i] != 1 && i != prev)
		{
			ant->visit[i] = ant->visit[i] == 0 ? 1 : ant->visit[i];
			if (find_solution(ant, i, list, id))
			{
				ant->visit[i] += 1;
				ft_lstadd((t_list**)&list->content,
				ft_lstnew(&i, sizeof(i)));
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void		print_map(t_lem *ant, int i, t_list *list)
{
	ft_create_matrix(ant);
	ft_create_visit_matrix(ant);
	list = ft_lstnew(NULL, 0);
	ant->roads = list;
	while (i < ant->room_num)
	{
		ant->visit[ant->start_id] = 1;
		if (ant->matrix[ant->start_id][i] == 1)
		{
			ant->visit[i] = 1;
			if (find_solution(ant, i, list, ant->start_id))
			{
				ant->visit[i] += 1;
				ft_lstadd((t_list**)&list->content, ft_lstnew(&i, sizeof(i)));
				ft_lstadd((t_list**)&list->content,
				ft_lstnew(&ant->start_id, sizeof(i)));
				check_dou(ant, list);
				list->next = ft_lstnew(NULL, 0);
				list = list->next;
			}
		}
		i++;
	}
}
