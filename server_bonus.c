/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:45:55 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/02 10:51:02 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



void	unicode_buffer(unsigned char c, int pid)
{
	static int				status[100000];
	static unsigned char	buff[100000][5];
	static int				counter[100000];

	if (counter[pid] == 0)
	{
		status[pid] = unicode_checker(c);
		counter[pid] = status[pid];
	}
	if (counter[pid] != 0)
	{
		buff[pid][status[pid] - counter[pid]] = c;
		counter[pid]--;
	}
	if (counter[pid] == 0)
	{
		ft_printf("%s", buff[pid]);
		ft_bzero(buff[pid], 5);
	}
}

void	kill_system(int pid)
{
	usleep(50);
	if (kill(pid, SIGUSR1) == -1)
		ft_error_s();
}

void	signal_processing(int sig, int pid, unsigned char (*c)[100000])
{
	if (sig == SIGUSR1)
	{
		(*c)[pid] |= (unsigned char)(1 << 7);
		kill_system(pid);
	}
	else if (sig == SIGUSR2)
	{
		(*c)[pid] |= (unsigned char)0;
		kill_system(pid);
	}
}

void	handler_action(int sig, siginfo_t *info, void *str)
{
	static int				i[100000];
	static unsigned char	c[100000];

	(void)str;
	if (info->si_pid == 0)
		return ;
	signal_processing(sig, info->si_pid, &c);
	if (i[info->si_pid] < 7)
		c[info->si_pid] >>= 1;
	if (i[info->si_pid] == 7)
	{
		unicode_buffer(c[info->si_pid], info->si_pid);
		c[info->si_pid] = 0;
		i[info->si_pid] = 0;
		return ;
	}
	i[info->si_pid]++;
}

int	main(int argc, char	**argv)
{
	struct sigaction	new_handler;
	sigset_t			set;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error : too much arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	sigemptyset(&set);
	new_handler.sa_flags = SA_SIGINFO;
	new_handler.sa_mask = set;
	new_handler.sa_sigaction = handler_action;
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
	ft_printf("- process id of the server : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
