/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:42:11 by dlyubich          #+#    #+#             */
/*   Updated: 2018/03/16 16:42:12 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				check_str(char *str)
{
	int			i;
	int			tmp;

	if (str == NULL || str[0] == '\0')
		return (0);
	tmp = 0;
	tmp = ft_strlen(str);
	if (tmp > 11 || (tmp == 10 && str[0] != '-'
	&& ft_strcmp(str, "2147483647") > 0)
	|| (tmp == 11 && str[0] == '-' && ft_strcmp(str, "-2147483648") > 0))
		return (0);
	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void			check_room_name(t_list *rooms, char *str)
{
	t_room		*tmp;

	while (rooms != NULL)
	{
		tmp = rooms->content;
		if (ft_strcmp(tmp->name, str) == 0)
			my_error_room();
		rooms = rooms->next;
	}
}

int				check_room(char *str)
{
	int			i;
	char		*x;
	char		*y;
	int			len;

	i = 0;
	while (i < (len = ft_strlen(str)))
	{
		while (str[i] && str[i] != ' ')
			i++;
		if (str[i] == '\0' || i == 0)
			return (0);
		i++;
		x = ft_substr(str, i, ' ');
		check_x(x);
		while (str[i] && str[i] != ' ')
			i++;
		i++;
		y = ft_substr(str, i, '\0');
		check_y(y);
		free(x);
		free(y);
		return (1);
	}
	return (0);
}

void			check_fl(t_lem *ant, int fl, int a)
{
	if (fl == 1 && (ant->flaq_start += 1))
		ant->start_id = a - 1;
	else if (fl == 2 && (ant->flaq_end += 1))
		ant->end_id = a - 1;
	if (ant->flaq_start == 2 || ant->flaq_end == 2)
		my_error_start();
}

t_room			*find_struct(char *str, t_list *room)
{
	t_room		*tmp;

	while (room)
	{
		tmp = (t_room*)room->content;
		if (!ft_strcmp(str, tmp->name))
			return (tmp);
		room = room->next;
	}
	return (NULL);
}
