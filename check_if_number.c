/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** check_if_nb
*/

int	check_if_number(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 57 || str[i] < 48)
            return 84;
        i++;
    }
    return 0;
}
