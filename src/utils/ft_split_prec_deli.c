#include <stdlib.h>

int	count_rows_del(char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
	        if (str[i] == c)
			len++;
		i++;
	}
	return (len);
}

int	ft_strlen_del(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && !(str[len] == c))
		len++;
	return (len);
}

char	**ft_split_del(char *str, c)
{
	int	i;
	int	j;
	int	len1;
	int	len2;
	char	**res;

	i = 0;
	len1 = count_rowss(str) + 1;
	res = (char **)malloc(sizeof(char *) * (len1 + 1));
	res[len1] = NULL;
	while (i < len1)
	{
		len2 = ft_strlenn(str);
		res[i] = (char *)malloc(sizeof(char ) * (len2 + 1));
		j = 0;
		while (*str && (*str == c)
			str++;
		while (*str && !(*str == c)
			res[i][j++] = *str++;
		res[i][j] = '\0';
		i++;
	}
	return (res);
}
