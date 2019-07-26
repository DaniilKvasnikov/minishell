#include "ft_minishell.h"

void
	ft_set_color_fd(t_mydata *mydata, char *color, int fd)
{
	if (mydata != NULL)
	{
		if (is_flag_ls(mydata->flags, 'c'))
			ft_putstr_fd(color, fd);
	}
}

void
	ft_set_color(t_mydata *mydata, char *color)
{
	ft_set_color_fd(mydata, color, 0);
}
