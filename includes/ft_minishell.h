
#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# define MAXDIR 100

# include "ft_printf.h"
# include <signal.h>
// # include <wait.h>
// # include <dir.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_mydata
{
	int			argc;
	char		**argv;
	char		**envp;
}				t_mydata;

int			check_file(char *path);
char		*get_curr_dir();
void		sig_handler(int signo);
void		put_start_shell();
int			run_cmd(char *path, char **args);
int			start_prog(char **strs, t_mydata *mydata);

void		start_cd(char **strs, char **envp, t_mydata *data);
void		start_ls(char **str);
void		start_pwd(char **strs);
void		start_echo(char **strs, char **envp);
char		**start_setenv(char **strs, char **envp);
void		start_unsetenv(char *str, char **envp);

char		**set_envp(char *name, char *par, char **envp);
char		*get_env(char *str, char **envp);
void		print_envp(char **envp);
int			ft_get_envp_len(char **envp);
int			ft_get_envp_free(char **envp);

void		ft_strsplit_print(char **strs);
int			ft_strsplit_len(char **strs);
void		ft_strsplit_free(char **str);
char		**ft_strsplit_argv(char const *s, char c);

#endif
