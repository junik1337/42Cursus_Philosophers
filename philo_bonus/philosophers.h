/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:51:22 by ayassir           #+#    #+#             */
/*   Updated: 2022/06/27 15:00:23 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>

typedef struct s_data {
	struct s_info			*info;
	time_t					curtime;
	sem_t					*message;
	pid_t					*process;
	int						number_of_philos;
	int						t_nb_eat;
	int						t_sleep;
	int						t_die;
	int						t_eat;
	int						id;
	int						eats;
	sem_t					*fork;
}				t_data;

typedef struct s_info{
	pthread_t				thread;
	time_t					t_last_eat;
	time_t					curtime;
	t_data					*data;
	int						loop;
	int						p_number;
	int						nb_eats;
	struct s_info			*next;
}				t_info;

t_info	*ft_lstnew(int content);
size_t	ft_strlen(const char *str);
time_t	ft_get_time(void);
void	ft_lstadd_back(t_info **lst, t_info *new);
void	ft_lstadd_front(t_info **lst, t_info *new);
void	ft_lstlast(t_info *lst);
void	ft_init_struct(t_data *data, t_info *info);
void	sleep_time(int time);
void	ft_print_message(t_info *info, char *msg, sem_t *message);
void	ft_kill_process(t_data *data, pid_t *list_pid);
void	free_space(t_data *data, t_info *info);
void	closeandfree(t_data *data);
void	ft_routine_stop(t_data *data, t_info *info);
int		ft_check_arguments(char **av, int ac);
int		ft_atoi(const char *str);
int		ft_init_info(t_data *data, char **av, int i);
int		ft_process_semaphore_init(t_data *data, t_info *info);
int		ft_detach_philo(t_data *data);
int		ft_mutex_init(t_data *data);
#endif