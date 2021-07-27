/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:58:27 by lukarape          #+#    #+#             */
/*   Updated: 2021/07/27 14:58:29 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_atoi(const char *str)
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

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	t;

	i = 0;
	size = ft_strlen(str);
	while (str[i] != 0 && i < size / 2)
	{
		t = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = t;
		i++;
	}
	return (str);
}

int		ft_intlen(int n)
{
	int			i;
	long long	t;

	i = 1;
	t = n;
	if (t < 0)
	{
		t = t * -1;
		i++;
	}
	while (t >= 10)
	{
		t = t / 10;
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen((char *)str) + 1))))
	{
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)str + i) = c;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int				idx;
	int				is_negative;
	unsigned int	positive_n;
	char			*value;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(value = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1))))
		return (NULL);
	ft_memset(value, '\0', (ft_intlen(n) + 1));
	is_negative = n < 0 ? 1 : 0;
	positive_n = n < 0 ? -n : n;
	idx = 0;
	while (positive_n != 0)
	{
		value[idx++] = (positive_n % 10) + '0';
		positive_n = positive_n / 10;
	}
	if (is_negative)
		value[idx++] = '-';
	return (ft_strrev(value));
}

