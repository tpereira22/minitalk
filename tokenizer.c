#include "minishell.h"

void    free_token(char **token_matrix)
{
    int i;

    if (token_matrix)
    {
        i = 0;
        while (token_matrix[i])
        {
            free(token_matrix[i]);
            i++;
        }
        free(token_matrix);
    }
}

int token_len(char *str, int i)
{
    if (str[i] == '"')
    {
        i++;
        while (str[i] && str[i] != '"')
            i++;
        if (str[i] == '"')
            i++;
        return (i);
    }
    else if (str[i] && str[i] == 39)
    {
        i++;
        while (str[i] != 39)
            i++;
        if (str[i] == 39)
            i++;
        return (i);
    }
    else
    {
        while (str[i] && !(str[i] >= 9 && str[i] <= 13) && str[i] != 32)
            i++;
        return (i);
    }
}

int matrix_len(char *str)
{
    int i;
    int len;

    i = -1;
    len = 0;
    while (str[++i])
    {
        while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
            i++;
        if (!str[i])
            return (len);
        if (str[i] == '"' || str[i] == 39)
        {
            i = quotes_end(str, i);
            len++;
        }
        else
        {
            while (str[i] && !(str[i] >= 9 && str[i] <= 13) && str[i] != 32)
                i++;
            if (!str[i])
                return (len + 1);
            len++;    
        }
    }
    return (len);
}

char    **tokenizer(char *str)
{
    char **token_matrix;
    int len;
    int i;
    int index;
    int end;

    len = matrix_len(str);
    if (len == 0)
        return (NULL);
    token_matrix = malloc(sizeof(char *) * (len + 1));
    if (!token_matrix)
        return (NULL);
    token_matrix[len] = '\0';
    i = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    index = 0;
    if (str[i] == '\0')
        return (0);
    while (str[i])
    {
        if (!(str[i] >= 9 && str[i] <= 13) && str[i] != 32)
        {
            end = token_len(str, i);
            token_matrix[index] = malloc(sizeof(char *) * (end - i + 1));
            ft_memcpy(token_matrix[index], str + i, (end - i));
            token_matrix[index][end] = '\0';
            index++;
            i = end;
        }
        else if (str[i] != '\0')
            i++;
    }
    return (token_matrix);
}