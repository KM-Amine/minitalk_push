/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:13:09 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/02 11:13:37 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error_c(void)
{
	ft_putstr_fd("Error in signal sending or process does not exist\n", 2);
	exit(EXIT_FAILURE);
}

void	sleep_system(void)
{
	if (sleep(5) == 0)
	{
		ft_putstr_fd("server dead or busy with an other client\n", 2);
		exit(EXIT_FAILURE);
	}
}
