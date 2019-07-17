#include "ft_minishell.h"

char
	*get_curr_dir()
{
	char *dir;

	dir = (char *)malloc(sizeof(char) * (MAXDIR + 1));
	getcwd(dir, MAXDIR);
	return (dir);
}
