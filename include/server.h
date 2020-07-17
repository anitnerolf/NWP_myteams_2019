/*
** EPITECH PROJECT, 2020
** server
** File description:
** header file
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <netinet/in.h>
#include <sys/time.h>

typedef struct s_client
{
    int client_socket[30];
    struct sockaddr_in client_address;
    char buffer[1025];
    int max_sd;
    int sd;
    int max_clients;
    int activity;
    int new_socket;
} t_client;

typedef struct s_server
{
    int server_fd;
    struct sockaddr_in server_addr;
    int kot;
} t_server;

void print_usage(void);
void start_server(char **av);
void init_server(t_server *server, char *port);
void accept_clients(int server_fd, t_server *server);
void init_client(t_client *client);
void client_activity(t_client *client, fd_set *readfds, t_server *server);
void	handle_ctrl_c(int signal);


#endif /* SERVER_H_ */
