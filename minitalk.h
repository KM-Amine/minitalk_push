/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:09:22 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/02 11:09:17 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "libft/libft.h"

void	handler(int sig);
void	input(unsigned char *str, int pid);
void	sleep_system(void);
void	ft_error_c(void);
void	ft_error_s(void);
int		unicode_checker(unsigned char c);

#endif