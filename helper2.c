/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:19:24 by dlyubich          #+#    #+#             */
/*   Updated: 2018/05/04 12:19:25 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			check_doub_coord(t_lem *ant, int x, int y)
{
	t_list		*tmp;
	t_room		*room;

	tmp = ant->rooms;
	while (tmp)
	{
		room = (t_room*)tmp->content;
		if (room && room->x == x && room->y == y)
			my_error_coord();
		tmp = tmp->next;
	}
}

int				check_coordinates(char *str)
{
	int			i;
	int			tmp;

	if (str == NULL || str[0] == '\0')
		return (0);
	tmp = ft_strlen(str);
	if (tmp > 11 || (tmp == 10 && str[0] != '-'
	&& ft_strcmp(str, "2147483647") > 0)
	|| (tmp == 11 && str[0] == '-' && ft_strcmp(str, "-2147483648") > 0))
		return (0);
	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void			check_x(char *x)
{
	if (!check_coordinates(x))
		my_error_coord();
}

void			check_y(char *y)
{
	if (!check_coordinates(y))
		my_error_coord();
}

char			*find_end_name(t_lem *data)
{
	t_list		*tmp;
	t_room		*room;

	tmp = data->rooms;
	while (tmp)
	{
		room = (t_room*)tmp->content;
		if (room->id == data->end_id)
			return (room->name);
		tmp = tmp->next;
	}
	return (NULL);
}
