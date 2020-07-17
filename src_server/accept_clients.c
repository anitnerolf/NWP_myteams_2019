/*
** EPITECH PROJECT, 2020
** accept
** File description:
** clients
*/

#include "../include/server.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>
#include <strings.h>
#include <stdlib.h>
#include <arpa/inet.h>

void client_activity(t_client *client, fd_set *readfds, t_server *server)
{
    for (int i = 0; i < client->max_clients; i++)
    {
        client->sd = client->client_socket[i];
        if (FD_ISSET(client->sd, readfds))
        {
            if (read(client->sd, client->buffer, 1024) == 0)
            {
                close(client->sd);
                printf("A client left\n");
                client->client_socket[i] = 0;
            }
            /*  else
                start_comands(client, i, server);
                Here we will procedure the comands that are comming from client
            */
            server->kot = 1;
            bzero(client->buffer, 1024);
        }
    }
}

void new_clients(t_client *client, fd_set *readfds, int server_fd)
{
    int addrlen = sizeof(client->client_address);

    if (FD_ISSET(server_fd, readfds)) {
        if ((client->new_socket = accept(server_fd,
        (struct sockaddr *)&client->client_address, (socklen_t *)&addrlen)) < 0)
        {
            perror("Accept: ");
            exit(84);
        }
        printf("New connection, ip is: %s, ",
        inet_ntoa(client->client_address.sin_addr));
        printf("port is: %d\n", ntohs(client->client_address.sin_port));
        write(client->new_socket, "220 Welcome\r\n", 13);
        for (int i = 0; i < client->max_clients; i++) {
            if (client->client_socket[i] == 0) {
                client->client_socket[i] = client->new_socket;
                break;
            }
        }
    }
}

void add_client_socket(t_client *client, fd_set *readfds)
{
    for (int i = 0; i < client->max_clients; i++)
    {
        client->sd = client->client_socket[i];
        if (client->sd > 0)
            FD_SET(client->sd, readfds);
        if (client->sd > client->max_sd)
            client->max_sd = client->sd;
    }
    client->activity = select(client->max_sd + 1, readfds,
    NULL, NULL, NULL);
    if (client->activity < 0)
        perror("Select:");
}

void init_client(t_client *client)
{
    client->max_clients = 30;

    for (int i = 0; i < client->max_clients; i++)
    {
        client->client_socket[i] = 0;
    }
}

void accept_clients(int server_fd, t_server *server)
{
    t_client *client = malloc(sizeof(t_client));
    fd_set readfds;

    init_client(client);
    while (1)
    {
        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);
        client->max_sd = server_fd;
        add_client_socket(client, &readfds);
        new_clients(client, &readfds, server_fd);
        client_activity(client, &readfds, server);
    }
    free(client);
}
