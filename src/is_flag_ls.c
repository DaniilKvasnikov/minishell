#include "ft_minishell.h"

int	is_flag_ls(char *flags, char flag)
{
	int	i;

	i = -1;
	while (flags[++i] != '\0')
		if (flags[i] == flag)
			return (1);
	return (0);
}
