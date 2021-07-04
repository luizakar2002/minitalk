#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int sign;
	int nb;

	sign = 1;
	nb = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
	|| *str == '\f' || *str == '\r')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * sign);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*add_char(char *str, unsigned int byte)
{
	char	*ptr;
	int		i;

	i = ft_strlen(str);
	ptr = malloc(i + 2);
	i--;
	while (i >= 0)
	{
		ptr[i] = str[i];
		i--;
	}
	ptr[ft_strlen(str)] = byte;
	ptr[ft_strlen(str) + 1] = '\0';
	return (ptr);
}
