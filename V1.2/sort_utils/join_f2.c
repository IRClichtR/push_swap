#include "sort_utils.h"

char	*join_f2(char *s1, char *s2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	tmp = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (tmp);
}

