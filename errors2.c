/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:30:59 by dlyubich          #+#    #+#             */
/*   Updated: 2018/05/03 14:31:00 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	my_error_coord(void)
{
	write(1, "ERROR. Wrong coordinates\n", 25);
	exit(EXIT_FAILURE);
}

void	my_error_nolink(void)
{
	write(1, "ERROR. No links\n", 16);
	exit(EXIT_FAILURE);
}

void	my_error_nosol(void)
{
	write(1, "ERROR. No ways\n", 15);
	exit(EXIT_FAILURE);
}
