#include "ft_minishell.h"

void
	ft_strsplit_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
}
