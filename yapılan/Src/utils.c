#include "minishell.h"

size_t	ft_strlen(char *ptr)
{
	size_t	count;

	count = 0;
	while (ptr && *(ptr++))
		count++;
	return (count);
}

char	*ft_strdup(char *ptr)
{
	char	*new_ptr;
	char	*return_new_ptr;

	if (!ptr)
		return (NULL);
	new_ptr = (char *)malloc(sizeof(char) * (ft_strlen(ptr) + 1));
	return_new_ptr = new_ptr;
	while (*ptr)
		*(new_ptr++) = *(ptr++);
	*new_ptr = 0;
	return (return_new_ptr);
}