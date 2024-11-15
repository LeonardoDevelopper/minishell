#include "minishell.h"

int	count_cmd_args(char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		if (cmd[i] == '-')
		{
			if (cmd[i + 1] == '-')
			{
				if (ft_isalpha(cmd[i + 2]))
				{
					count++;
					i += 2;
				}
			}
			else if (ft_isalpha(cmd[i + 1]))
			{
				count++;
				i += 1;
			}
		}
		else
			i++;
	}
	return (count);
}

char	**catch_cmd_args(t_cmd *cmd)
{
	int	i;
	int	j;
	char	**args;

	i = 0;
	j = 0;
	args = ft_split_args(cmd->input);
	return (args);
}
