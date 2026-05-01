#include "libft.h"

char *ft_strndup(char *s, int n)
{
	char *d;
	int i;

	if(!s)
		return(NULL);
	i = 0;
	d = malloc(sizeof(char) * (n + 1));
	if(!d)
		return (NULL);
	while (s[i] && i < n)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
