
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

char		*get_curr_dir();
void		sig_handler(int signo);
void		put_start_shell();

char		*get_env(char *str, char **envp);
void		print_envp(char **envp);
int			ft_get_envp_len(char **envp);
int			ft_get_envp_free(char **envp);

void		ft_strsplit_print(char **strs);
int			ft_strsplit_len(char **strs);
void		ft_strsplit_free(char **str);
char		**ft_strsplit_argv(char const *s, char c);

#endif
