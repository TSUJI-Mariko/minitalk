#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		if (i == 2)
			return ;
		i++;
	}
	printf(" i = %d\n", i);
}

int main(void)
{
	ft_putstr("a");
	return (0);
}
