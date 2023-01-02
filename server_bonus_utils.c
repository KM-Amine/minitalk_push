/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:49:06 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/02 10:50:29 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error_s(void)
{
	ft_putstr_fd("Error in signal sending or process does not exist\n", 2);
	exit(EXIT_FAILURE);
}

int	unicode_checker(unsigned char c)
{
	int	i;

	i = 0;
	if ((c & 0x80) == 0)
		i = 1;
	else if ((c & 0xC0) != 0 && (c & 0x20) == 0)
		i = 2;
	else if ((c & 0xE0) != 0 && (c & 0x10) == 0)
		i = 3;
	else if ((c & 0xF0) != 0 && (c & 0x8) == 0)
		i = 4;
	return (i);
}
