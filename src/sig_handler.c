#include "ft_minishell.h"

void
	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar('\n');
		put_start_shell(NULL);
	}
}
