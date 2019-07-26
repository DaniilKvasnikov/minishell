/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 19:01:05 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 19:04:32 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# define MAXDIR 100

# include <signal.h>
# include <sys/stat.h>
# include <stdio.h>
# include <unistd.h>
# include "ft_printf.h"
# include "ft_color.h"
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>

typedef struct stat		t_stat;

typedef struct	s_mydata
{
	int			argc;
	char		**argv;
	char		**envp;
	char		*flags;
}				t_mydata;

t_mydata		*init_mydata(int argc, char **argv, char **envp);
void			ft_auto_minishell(t_mydata *mydata);
void			ft_standart_minishell(t_mydata *mydata);

char			**character_name_completion(const char *text, int start,
																	int end);
char			*character_name_generator(const char *text, int state);

int				check_file(char *path, t_mydata *mydata);

void			ft_set_color_fd(t_mydata *mydata, char *color, int fd);
void			ft_set_color(t_mydata *mydata, char *color);

char			*set_flags(int argc, char **argv);
int				is_flag_ls(char *flags, char flag);

int				check_file(char *path, t_mydata *mydata);
char			*get_curr_dir();
void			sig_handler(int signo);
void			put_start_shell(t_mydata *mydata);
int				run_cmd(char *path, char **args, char **envp, t_mydata *mydata);
int				start_prog(char **strs, t_mydata *mydata);

void			start_cd(char **strs, char **envp, t_mydata *data);
void			start_ls(char **str, char **envp, t_mydata *mydata);
void			start_pwd(char **strs, char **envp, t_mydata *mydata);
void			start_echo(char **strs, char **envp, t_mydata *mydata);
char			**start_setenv(char **strs, char **envp);
void			start_unsetenv(char *str, char **envp);

char			**set_envp(char *name, char *par, char **envp);
char			*get_env(char *str, char **envp);
void			print_envp(char **envp, t_mydata *mydata);
int				ft_get_envp_len(char **envp);
int				ft_get_envp_free(char **envp);

void			ft_strsplit_print(char **strs);
int				ft_strsplit_len(char **strs);
void			ft_strsplit_free(char **str);
char			**ft_strsplit_argv(char const *s, char c);

#endif
