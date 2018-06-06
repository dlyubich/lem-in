/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:59:55 by dlyubich          #+#    #+#             */
/*   Updated: 2018/03/26 14:59:56 by dlyubich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	my_error(void)
{
	write(1, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}

void	my_error_start(void)
{
	write(1, "ERROR. Invalid start or end room\n", 33);
	exit(EXIT_FAILURE);
}

void	my_error_link(void)
{
	write(1, "ERROR. Invalid link\n", 20);
	exit(EXIT_FAILURE);
}

void	my_error_room(void)
{
	write(1, "ERROR. Invalid room\n", 20);
	exit(EXIT_FAILURE);
}

void	my_error_ants(void)
{
	write(1, "ERROR. Invalid number of ants\n", 30);
	exit(EXIT_FAILURE);
}
