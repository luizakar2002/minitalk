#include "minitalk.h"

static t_data data;

static	void	handle_signal(int sig)
{
	int	i;
	int	arr[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	
	i = 0;
	if (sig == SIGUSR1)
		i = 1;
	data.byte += i * arr[data.bits];
	data.bits++;
	if (data.bits == 8)
	{
		if (data.byte == 0)
			data.end = 1;
		data.str = add_char(data.str, data.byte);
		data.bits = 0;
		data.byte = 0;
	}
}

int		main(void)
{
	printf("My PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	data.str = NULL;
	data.bits = 0;
	data.byte = 0;
	while (1)
	{
		if (data.end)
		{
			printf("%s\n", data.str);
			data.end = 0;
			data.str = NULL;
			data.bits = 0;
			data.byte = 0;
		}
	}
	return (0);
}
