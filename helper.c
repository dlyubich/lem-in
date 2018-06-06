/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:27:31 by dlyubich          #+#    #+#             */
/*   Updated: 2018/05/02 13:27:33 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			road_len(t_list *ant)
{
	int		n;

	n = 0;
	while (ant)
	{
		if (ant->content)
			n++;
		ant = ant->next;
	}
	return (n);
}

char		*find_room_name(int id, t_lem *ant)
{
	t_room	*tmp;
	t_list	*rooms;
	int		i;

	i = 0;
	rooms = ant->rooms;
	while (rooms)
	{
		tmp = (t_room*)rooms->content;
		i = tmp->id;
		if (i == id && rooms->content)
			return (tmp->name);
		rooms = rooms->next;
	}
	return (0);
}

void		print_roads(t_lem *ant)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = ant->roads;
	ft_printf("\x1b[34m\x1b[1mWAYS\n\n\x1b[0m");
	while (tmp)
	{
		if (tmp->content)
		{
			tmp2 = (t_list*)tmp->content;
			while (tmp2)
			{
				ft_printf("%s", find_room_name(*((int*)tmp2->content), ant));
				if (tmp2->next)
					ft_printf(" -> ");
				tmp2 = tmp2->next;
			}
			ft_printf("\n");
		}
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void		print_into_line(t_lem *ant)
{
	int		i;

	i = -1;
	ft_printf("\x1b[33m\x1b[1mINPUT DATA\n\n\x1b[0m");
	while (ant->buf[++i])
	{
		printf("%s\n", ant->buf[i]);
		free(ant->buf[i]);
	}
	ft_printf("\x1b[32m\x1b[1m\nMOVEMENT OF ANTS\n\n\x1b[0m");
	i = 0;
	while (++i <= ant->ants_num)
	{
		ft_printf("\x1b[1mL%d\x1b[0m-", i);
		ft_printf("%s", find_room_name(ant->end_id, ant));
		if (i < (ant->ants_num))
			ft_printf(" ");
	}
	ft_printf("\n");
	exit(EXIT_FAILURE);
}
