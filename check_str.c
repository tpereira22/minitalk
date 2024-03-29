#include "minishell.h"

int g_counter = 0;

int check_qt_marks(char *str, int i)
{
    if (str[i] == '"')
    {
        i++;
        while (str[i] && str[i] != '"')
            i++;
        if (!str[i])
            loop_promt(str, 1);
        return (i);
    }
    else if (str[i] == 39)
    {
        i++;
        while (str[i] && str[i] != 39)
            i++;
        if (!str[i])
            loop_promt(str, 2);
        return (i);
    }
    return (i);
}

int check_pipe_done(char *str, int i)
{
    i++;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (!str[i])
        loop_promt(str, 3);
    return (i);
}

void    check_if_complete(char *str)
{
    int i;

    i = 0;
    _input()->qt_flag = 1;
    while (str[i] && _input()->qt_flag == 1)
    {
        if (str[i] == '"' || str[i] == 39)
        {
            i = check_qt_marks(str, i);
            if (!str[i])
                _input()->qt_flag = 0;
        }
        else if (str[i] == 124)
        {
            i = check_pipe_done(str, i);
            if (!str[i])
                _input()->qt_flag = 0;
        }
        if (str[i])
            i++;
    }
    if (_input()->qt_flag == 1)
        _input()->command = ft_strcpy(str);
}