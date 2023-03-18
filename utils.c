#include "minishell.h"

t_input *_input(void)
{
    static t_input input;

    return (&input);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
    if (s1[i] || s2[i])
        return (0);
    return (1);
}

int quotes_end(char *str, int i)
{
    if (str[i] == '"')
    {
        i++;
        while (str[i] && str[i] != '"')
            i++;
    }
    else if (str[i] == 39)
    {
        i++;
        while (str[i] && str[i] != 39)
            i++;
    }
    return (i);
}

char    *ft_strcpy(char *str)
{
    char    *cpy;
    int i;
    int len;

    len = ft_strlen(str);
    cpy = malloc(sizeof(cpy) * len + 1);
    i = 0;
    while (str[i])
    {
        cpy[i] = str[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}

size_t  ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *str;
    size_t     i;
    size_t     j;

    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    i = 0;
    if (s1)
    {
        while (s1[i] != '\0')
        {
            str[i] = s1[i];
            i++;
        }
    }
    j = 0;
    while (s2[j] != '\0')
        str[i++] = s2[j++];
    str[i] = '\0';
    //free(s1);
    return (str);
}