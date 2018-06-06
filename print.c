/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:26:16 by dlyubich          #+#    #+#             */
/*   Updated: 2018/05/02 14:26:18 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			init_struct(t_road **road, int *id, t_lem *ant)
{
	t_road		*tmp;

	tmp = *road;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_road*)malloc(sizeof(t_road));
		tmp->next->name = find_room_name(*id, ant);
		tmp->next->ant = -1;
		tmp->next->next = NULL;
	}
	else
	{
		(*road) = (t_road*)malloc(sizeof(t_road));
		(*road)->name = find_room_name(*id, ant);
		(*road)->ant = -1;
		(*road)->next = NULL;
	}
}

void			ft_create_struct(t_lem *ant, int i)
{
	t_road		**road;
	t_list		*tmp;
	t_list		*tmp2;

	ant->road_len = road_len(ant->roads);
	road = (t_road**)malloc(sizeof(t_road*) * ant->road_len);
	ant->routes = road;
	tmp = ant->roads;
	while (tmp)
	{
		if (!tmp->content)
		{
			tmp = tmp->next;
			continue;
		}
		road[i++] = NULL;
		tmp2 = ((t_list*)tmp->content)->next;
		while (tmp2)
		{
			init_struct(&road[i - 1], (int*)tmp2->content, ant);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void			move_ant(t_road *r, t_lem *ant)
{
	if (r->next)
		move_ant(r->next, ant);
	if (r->next == NULL && r->ant > 0)
	{
		r->ant = 0;
		ant->ants_num--;
	}
	else if (r->ant > 0)
	{
		if (ant->fl == 1)
		{
			ft_printf(" ");
		}
		ft_printf("\x1b[1mL%d\x1b[0m-%s", r->ant, r->next->name);
		r->next->ant = r->ant;
		r->ant = 0;
		ant->fl = 1;
	}
}

void			move_new(t_road **r, t_lem *ant, int *n)
{
	static int	a;
	int			i;

	i = -1;
	if (a >= *n)
		return ;
	while (++i < ant->road_len && a < *n)
	{
		r[i]->ant = a + 1;
		if (ant->fl == 1)
		{
			ft_printf(" ");
		}
		ft_printf("\x1b[1mL%d\x1b[0m-%s", a + 1, r[i]->name);
		a++;
		ant->fl = 1;
	}
}

void			print_fin(t_lem *ant)
{
	int			num;
	int			i;
	t_road		**tmp;

	num = ant->ants_num;
	tmp = ant->routes;
	i = -1;
	ft_printf("\x1b[33m\x1b[1mINPUT DATA\n\n\x1b[0m");
	while (ant->buf[++i])
	{
		printf("%s\n", ant->buf[i]);
		free(ant->buf[i]);
	}
	ft_printf("\x1b[32m\x1b[1m\nMOVEMENT OF ANTS\n\n\x1b[0m");
	while (ant->ants_num > 0)
	{
		ant->fl = 0;
		i = -1;
		while (++i < ant->road_len)
			move_ant(tmp[i], ant);
		move_new(tmp, ant, &num);
		if (ant->ants_num > 0)
			ft_printf("\n");
	}
}
