
#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;
	unsigned int	len_s;
	char			*s1;

	s1 = (char *)s;
	if (!s)
		return (0);
	len_s = ft_strlen(s);
	i = 0;
	dest = (char*)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	if (!s1)
		return (NULL);
	while (start < len_s && i < (unsigned int)len && *s1)
	{
		dest[i] = s1[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_putstr_fd(char *s, int fd)
{
	int		x;
	char	c;

	x = 0;
	if (!s)
		return (0);
	while (s[x] != '\0')
	{
		c = s[x];
		write(fd, &c, 1);
		x++;
	}
	return (x);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (src[x] != '\0')
		x++;
	dest = (char *)malloc(sizeof(*dest) * (x + 1));
	if (dest == NULL)
		return (NULL);
	while (i <= x)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
