
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("text.text", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
// int main()
// {
// 	printf ("%s", ft_strjoin("ho", "ho"));
// }