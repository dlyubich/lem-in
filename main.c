/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:37:23 by dlyubich          #+#    #+#             */
/*   Updated: 2018/02/07 16:37:23 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_data(t_lem *ant)
{
	if (ant->room_num == 0 || ant->start_id == -1 || ant->end_id == -1)
		my_error();
}

int			root_exist(t_lem *ant)
{
	t_list *tmp;

	tmp = ant->roads;
	while (tmp)
	{
		if (tmp->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		init_data(t_lem *data)
{
	data->rooms = NULL;
	data->room_num = 0;
	data->start_id = -1;
	data->end_id = -1;
	data->d = 0;
	data->flaq_start = 0;
	data->flaq_end = 0;
}

void		check_fin(t_lem *data, char *end_name)
{
	t_road	**tmp;
	int		i;

	i = -1;
	ft_create_struct(data, 0);
	tmp = data->routes;
	while (++i < data->road_len)
	{
		if (tmp[i]->name == end_name)
			print_into_line(data);
	}
	print_fin(data);
}

int			main(int c, char **v)
{
	t_lem	*data;

	data = (t_lem*)malloc(sizeof(t_lem));
	data->verbose = 0;
	if (c > 1 && ft_strcmp(v[1], "-v") == 0)
		data->verbose = 1;
	init_data(data);
	if (read_file(data, 0))
	{
		check_data(data);
		print_map(data, 0, NULL);
		if (data->verbose == 1 && road_len(data->roads))
			print_roads(data);
		if (root_exist(data))
			check_fin(data, find_end_name(data));
		else
			my_error_nosol();
		exit(0);
	}
	exit(1);
}
