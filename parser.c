/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:02:51 by dlyubich          #+#    #+#             */
/*   Updated: 2018/02/07 13:02:52 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			parse_link(char *str, t_lem *ant)
{
	t_room		*room1;
	t_room		*room2;
	char		*str1;
	char		*str2;
	int			i;

	i = 0;
	ant->d = 1;
	if (ant->flaq_start == 0 || ant->flaq_end == 0)
		my_error_start();
	while (str[i] != '-')
		i++;
	str1 = ft_strsub(str, 0, i);
	str2 = ft_strsub(str, i + 1, ft_strlen(str) - (i + 1));
	room1 = find_struct(str1, ant->rooms);
	room2 = find_struct(str2, ant->rooms);
	if (!room1 || !room2)
		my_error_link();
	ft_lstpushback(&room1->link, &room2->id, sizeof(room2->id));
	ft_lstpushback(&room2->link, &room1->id, sizeof(room1->id));
	free(str1);
	free(str2);
}

void			parse_coor(char *str, int i, t_room *room, t_lem *ant)
{
	room->x = 0;
	while (ft_isdigit(str[++i]))
		room->x = room->x * 10 + str[i] - 48;
	room->y = ft_atoi(str + i);
	check_doub_coord(ant, room->x, room->y);
	room->link = NULL;
}

void			parse_room(char *str, t_lem *ant, int fl, int i)
{
	static int	a;
	static int	dou;
	t_room		*room;

	if (!ft_strchr(str, ' ') && ft_strchr(str, '-') && (dou = 3))
		parse_link(str, ant);
	else
	{
		if (!check_room(str) || dou == 3 || str[0] == 'L')
			my_error_room();
		while (str[i] != ' ')
			i++;
		room = (t_room*)malloc(sizeof(t_room));
		room->name = ft_strsub(str, 0, i);
		check_room_name(ant->rooms, room->name);
		parse_coor(str, i, room, ant);
		room->id = a++;
		ft_lstpushback(&ant->rooms, (void*)room, sizeof(t_room));
		ant->room_num = a;
		check_fl(ant, fl, a);
		free(room);
	}
}

void			parsing(char *str, char **buf, int *i, t_lem *ant)
{
	buf[(*i)++] = str;
	if (str[0] == '#' && ft_strcmp(str, "##start")
	&& ft_strcmp(str, "##end"))
	{
		return ;
	}
	if (!ft_strcmp(str, "##start") && get_next_line(0, &str))
	{
		buf[(*i)++] = str;
		while (str && str[0] == '#' && ft_strcmp(str, "##start")
		&& ft_strcmp(str, "##end") && get_next_line(0, &str))
			buf[(*i)++] = str;
		parse_room(str, ant, 1, 0);
	}
	else if (!ft_strcmp(str, "##end") && get_next_line(0, &str))
	{
		buf[(*i)++] = str;
		while (str && str[0] == '#' && ft_strcmp(str, "##start")
		&& ft_strcmp(str, "##end") && get_next_line(0, &str))
			buf[(*i)++] = str;
		parse_room(str, ant, 2, 0);
	}
	else
		parse_room(str, ant, 0, 0);
}

int				read_file(t_lem *ant, int i)
{
	char		*str;

	str = NULL;
	ant->buf = (char**)malloc(sizeof(char*) * 4096);
	get_next_line(0, &str);
	while (str && str[0] == '#' && ft_strcmp(str, "##start")
	&& ft_strcmp(str, "##end"))
	{
		ant->buf[i++] = str;
		get_next_line(0, &str);
	}
	if (!check_str(str) || (ant->ants_num = ft_atoi(str)) == 0)
		my_error_ants();
	ant->buf[i++] = str;
	while (get_next_line(0, &str) > 0)
		parsing(str, ant->buf, &i, ant);
	if (ant->d == 0)
		my_error_nolink();
	ant->buf[i] = NULL;
	return (1);
}
