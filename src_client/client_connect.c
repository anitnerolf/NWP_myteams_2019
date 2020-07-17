/*
** EPITECH PROJECT, 2020
** client
** File description:
** connect
*/

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

void	handle_ctrl_c(int signal)
{
    (void)signal;
    return;
}

int	connect_client(int port, char *address)
{
    struct sockaddr_in serveraddress;
    int socket_fd = 0;

    signal(SIGINT, handle_ctrl_c);
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Socket creation failed...\n");
        return (84);
    }
    serveraddress.sin_addr.s_addr = inet_addr(address);
    serveraddress.sin_family = AF_INET;
    serveraddress.sin_port = htons(port);
    if (connect(socket_fd, (struct sockaddr *)&serveraddress, sizeof(serveraddress)) < 0) {
        perror("connect failed.");
        return 84;
    }
    printf("Connected...\n");
    return (socket_fd);
}

int	client(char **av)
{
    int sock = connect_client(atoi(av[2]), av[1]);
    if (sock == 84) {
        printf("Sock == 84\n");
        return (84);
    }
    char buf[1024];
    while (1) {
        bzero(buf, 1024);
        if (read(0, buf, 1024) <= 0) {
            printf("Error while reading\n");
            return (84);
        }
        write(1, buf, strlen(buf));
    }
    return (0);
}
