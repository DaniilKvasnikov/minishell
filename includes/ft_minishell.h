
#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# define MAXDIR 100

# include "ft_printf.h"
# include <signal.h>
# include <wait.h>
// # include <dir.h>
# include <stdio.h>

typedef struct	s_mydata
{
	int			argc;
	char		**argv;
}				t_mydata;

#endif
