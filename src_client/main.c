/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "../include/client.h"
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char **av)
{
    if (ac == 2 && (strcmp(av[1], "-help") == 0)) {
        print_usage();
    } else if (ac == 3) {
        return (ac_equals_three(ac, av));
    } else {
        print_usage();
        return (84);
    }
    return 0;
}

int	ac_equals_three(int ac, char **av)
{
    if (check_if_number(av[2]) != 0){
        print_usage();
        return (84);
    } else {
        return (if_ip_okay(ac, av));
    }
    return (0);
}

int	if_ip_okay(int ac, char **av)
{
    (void)ac;
    if (atoi(av[2]) <= 0 || atoi(av[2]) > 65535) {
        printf("Wrong port number!\n");
        return 84;
    } else {
        if (client(av) != 0)
            return (84);
    }
    return (0);
}

int	check_if_ip_correct(char *ip)
{
    int dots = 0;
    char *ptr;

    if (ip == NULL)
        return 84;
    ptr = strtok(ip, ".");
    if (ptr == NULL)
        return 84;
    dots = check_ip(ptr);
    if (dots != 3)
        return 84;
    return 0;
}

int	check_ip(char *ptr)
{
    int dots;
    int num;

    while (ptr) {
        if (check_if_number(ptr) != 0)
            return 0;
        num = atoi(ptr);
        if (num >= 0 && num <= 255) {
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
                dots++;
        } else
            return 0;
    }
    return dots;
}
