#include "minishell.h"

int	ft_strlen_c(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != c)
		len++;
	return (len);
}


char	*ft_strjoin_ptr(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char ) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*remove_char(char *str, char c, char *rep)
{
	int	len;
	char	*res;
	char	*start;
	char	*ptr_str;

	len = ft_strlen_c(str, c) + 1;
	res = (char *)malloc(sizeof(char ) * len + 1);
	start = res;
	ptr_str = str;
	res[len] = '\0';
	while (*ptr_str)
	{
		if (rep)
		{
			if (*ptr_str == c)
				*res = rep[0];
			else
				*res = *ptr_str;
		}
		else
		{
			if (*ptr_str == c)
				*ptr_str++;
			else
				*res = *ptr_str;
		}
		res++;
		ptr_str++;
	}
	return (free(str), start);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
	}
}
