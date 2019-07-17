#include "ft_minishell.h"

int
    ft_strsplit_len(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i] != NULL)
        ;
    return (i);
}