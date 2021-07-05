#ifndef	MINITALK_H
# define MINITALK_H
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_data
{
	char			*str;
	int 			bits;
	unsigned int	byte;
	int				end;
}				t_data;

int		ft_strlen(char *str);
int		ft_atoi(const char *str);
char	*add_char(char *str, unsigned int byte);
char	*ft_itoa(int n);

#endif
