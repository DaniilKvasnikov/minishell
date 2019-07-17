
#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# define MAXDIR 100

# include "ft_printf.h"
# include <signal.h>
// # include <wait.h>
// # include <dir.h>
# include <stdio.h>

typedef struct	s_mydata
{
	int			argc;
	char		**argv;
	char		**envp;
}				t_mydata;


void		ft_strsplit_print(char **strs);
void		ft_strsplit_free(char **str);
int			ft_strsplit_len(char **strs);
char		**ft_strsplit_argv(char const *s, char c);

#endif
