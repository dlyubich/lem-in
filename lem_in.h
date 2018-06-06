/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:03:19 by dlyubich          #+#    #+#             */
/*   Updated: 2018/02/07 13:03:20 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>

# define RESET    "\x1b[0m"
# define BOLD    "\x1b[1m"
# define BLACK    "\x1b[30m"
# define RED    "\x1b[31m"
# define GREEN    "\x1b[32m"
# define YEL    "\x1b[33m"
# define BLUE    "\x1b[34m"
# define WHITE    "\x1b[37m"

typedef struct		s_road
{
	char			*name;
	int				ant;
	struct s_road	*next;
}					t_road;

typedef struct		s_lem
{
	int				ants_num;
	int				room_num;
	t_list			*rooms;
	int				start_id;
	int				end_id;
	t_list			*roads;
	int				**matrix;
	int				*visit;
	int				flaq_start;
	int				flaq_end;
	int				flaq;
	int				road_len;
	t_road			**routes;
	int				fl;
	int				verbose;
	int				d;
	char			**buf;
}					t_lem;

typedef struct		s_room
{
	char			*name;
	int				id;
	int				x;
	int				y;
	t_list			*link;
}					t_room;

int					read_file(t_lem *ant, int i);
void				print_map(t_lem *ant, int i, t_list *list);
int					check_str(char *str);
int					check_room(char *str);
void				my_error(void);
void				check_room_name(t_list *rooms, char *str);
void				print_roads(t_lem *ant);
char				*find_room_name(int id, t_lem *ant);
void				ft_create_visit_matrix(t_lem *ant);
void				ft_create_matrix(t_lem *ant);
void				fill_matrix(t_lem *ant);
void				lst_free(t_list **list);
int					lstlen(t_list *list);
int					road_len(t_list *ant);
void				print_fin(t_lem *ant);
void				check_fl(t_lem *ant, int fl, int a);
t_room				*find_struct(char *str, t_list *room);
void				check_x(char *x);
void				check_y(char *y);
void				check_doub_coord(t_lem *ant, int x, int y);
void				my_error_ants(void);
void				my_error_room(void);
void				my_error_link(void);
void				my_error_start(void);
void				my_error(void);
void				my_error_coord(void);
void				my_error_nolink(void);
void				my_error_nosol(void);
char				*find_end_name(t_lem *data);
void		print_into_line(t_lem *ant);
void			ft_create_struct(t_lem *ant, int i);
#endif
