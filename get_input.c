#include "minishell.h"

void    loop_promt(char *str, int flag)
{
    char    *command;
    
    // printf("command - %s | str - %s\n", command, str);
    if (flag == 1)
        command = readline(YELLOW"dquote> " RESET);
    else if (flag == 2)
        command = readline(YELLOW"squote> " RESET);
    else if (flag == 3)
        command = readline(YELLOW"pipe> " RESET);
    command = ft_strjoin(str, command);
    check_if_complete(command);
}

void    get_input()
{
    char    *tmp_command;

    tmp_command = readline(YELLOW"minishell> " RESET);
    check_if_complete(tmp_command);
    printf("!!!!!!!str - %s\n", _input()->command);
    if (_input()->command && *_input()->command)
        add_history(_input()->command);
    // handles Ctrl+D
    if (_input()->command == NULL || !strcmp(_input()->command, "exit"))
    {
        write(1, "\n", 1);
        free(_input()->command);
        exit(1);
    }
}