
#include "ft_minishell.h"

static void
	add_char(char *res, char c)
{
	int i;

	i = -1;
	while (res[++i] != '\0')
		if (res[i] == c)
			return ;
	res[i] = c;
}

char
	*set_flags(int argc, char **argv)
{
	char	*res;
	int		i;
	int		j;

	res = ft_strnew(255);
	ft_strclr(res);
	i = -1;
	while (++i < argc)
		if (argv[i][0] == '-' && ft_strlen(argv[i]) != 1)
			if (argv[i][1] != '-' || ft_strlen(argv[i]) != 2)
			{
				j = 0;
				while (argv[i][++j] != '\0')
					add_char(res, argv[i][j]);
			}
	return (res);
}