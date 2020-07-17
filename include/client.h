/*
** EPITECH PROJECT, 2020
** client
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

void	print_usage(void);
int	check_if_ip_correct(char *);
int	check_ip(char *);
int	connect_client(int port, char *address);
int	ac_equals_three(int ac, char **av);
int	if_ip_okay(int ac, char **av);
int	client(char **av);

#endif /* CLIENT_H_ */
