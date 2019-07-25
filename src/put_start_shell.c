#include "ft_minishell.h"

void
	put_start_shell(t_mydata *mydata)
{
	char	*path;

	path = NULL;
	if (mydata != NULL)
	{
		path = get_curr_dir();
		if (is_flag_ls(mydata->flags, 'c'))
			ft_printf("\033[0;32m");
		if (is_flag_ls(mydata->flags, 'p'))
			ft_printf("%s ", path);
		if (is_flag_ls(mydata->flags, 'c'))
			ft_printf("\033[0m");
	}
	ft_putstr("$>");
	if (path != NULL)
		free(path);
}
