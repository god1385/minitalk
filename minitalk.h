/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctorrek <ctorrek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:08:44 by ctorrek           #+#    #+#             */
/*   Updated: 2022/03/10 21:11:03 by ctorrek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct byte
{
	unsigned char	b1:1;
	unsigned char	b2:1;
	unsigned char	b3:1;
	unsigned char	b4:1;
	unsigned char	b5:1;
	unsigned char	b6:1;
	unsigned char	b7:1;
	unsigned char	b8:1;
}	t_byte_struct;

void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	convert(int c, int pid);
void	ft_putchar_fd(char c, int fd);
void	ft_handler(int sig, siginfo_t *info, void *context);
int		main(int argc, char **argv);

#endif