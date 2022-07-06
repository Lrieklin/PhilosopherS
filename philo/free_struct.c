/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrieklin <lrieklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:38:29 by lrieklin          #+#    #+#             */
/*   Updated: 2022/06/30 16:41:31 by lrieklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_thread(t_data *data)
{
	if (data->thread != NULL)
	{
		free(data->thread);
		data->thread = NULL;
	}
	if (data->rules != NULL)
	{
		free(data->rules);
		data->rules = NULL;
	}
	if (data->philos != NULL)
	{
		free(data->philos);
		data->philos = NULL;
	}
}
