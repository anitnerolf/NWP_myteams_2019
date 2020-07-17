/*
** EPITECH PROJECT, 2020
** start
** File description:
** server
*/

#include "../include/server.h"
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void setnonblocking(int sock)
{
    int opts;

    opts = fcntl(sock, F_GETFL);
    if (opts < 0)
    {
        perror("fcntl(F_GETFL)");
        exit(EXIT_FAILURE);
    }
    opts = (opts | O_NONBLOCK);
    if (fcntl(sock, F_SETFL, opts) < 0)
    {
        perror("fcntl(F_SETFL)");
        exit(EXIT_FAILURE);
    }
    return;
}

void init_server(t_server *server, char *port)
{
    server->server_addr.sin_family = AF_INET;
    server->server_addr.sin_port = htons(atoi(port));
    server->server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if ((server->server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Error");
        exit(84);
    }
    setnonblocking(server->server_fd);
    if ((bind(server->server_fd, (struct sockaddr *)&server->server_addr,
    sizeof(server->server_addr))) < 0) {
        perror("Bind Error");
        exit(84);
    }
    if ((listen(server->server_fd, 5)) < 0)
    {
        perror("Listen Error");
        exit(84);
    }
    printf("start on port %d, waiting for connections...\n", atoi(port));
}

void start_server(char **av)
{
    t_server *server = malloc(sizeof(t_server));

    init_server(server, av[1]);
    accept_clients(server->server_fd, server);
    close(server->server_fd);
    free(server);
}
