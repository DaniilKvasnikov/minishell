#include "ft_minishell.h"

void
	ft_strsplit_print(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i] != NULL)
		ft_putendl(strs[i]);
}
