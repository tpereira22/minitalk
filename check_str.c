#include "minishell.h"

int check_quotation_marks(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '"')
        {
            i++;
            while (str[i] != '"' && str[i] != '\0')
                i++;
            if (str[i] == '\0')
                return (0);
        }
        i++;
    }
    return (1);
}

int matrix_len(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    while (str[i])
    {
        if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        {
            len++;
            while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
                i++;
            if (str[i] == '\0')
                break ;
        }
        i++;
    }
    if (str[i] == '\0' && str[i-1] != 32 && str[i-1] != 9 && str[i-1] != 13)
        len++;
    return (len);
}

char    **tokenizer(char *str)
{
    char **token_matrix;
    int len;

    len = matrix_len(str);
    token_matrix = malloc(sizeof(*token_matrix) * len + 1);
    if (!token_matrix)
        return (NULL);
        
    return (token_matrix);
}