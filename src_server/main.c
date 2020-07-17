/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "../include/server.h"
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void	print_usage(void)
{
    printf("USAGE: ./myteams_server port\n");
    printf("\n\tport\tis the port number on");
    printf(" which the server socket listens.\n");
}

int	main(int ac, char **av)
{
    if (ac == 2) {
        if (strcmp(av[1], "-help") == 0) {
            print_usage();
        } else {
            if (check_if_number(av[1]) != 0) {
                print_usage();
                return (84);
            } else {
                if (atoi(av[1]) <= 0 || atoi(av[1]) > 65535) {
                    printf("Wrong port number!\n");
                    return 84;
                }
                signal(SIGINT, &handle_ctrl_c);
                start_server(av);
            }
        }
    } else {
        print_usage();
        return (84);
    }
    return 0;
}

