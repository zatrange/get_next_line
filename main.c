
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	// int fd;
// 	char *hold;
// 	int line = 6;
// 	int x = 0;
	// fd = open("text.text", O_RDONLY);
	int fdd = open("lol.text", O_RDONLY);
	// while ((x < line) && ((hold = get_next_line(1)) != NULL))
	// {
	// 	printf("%s", hold);
	// 	free(hold);
	// 	x++;
	// }
	printf("%s", get_next_line(fdd));
		printf("%s", get_next_line(fdd));
			printf("%s", get_next_line(fdd));
	printf("%s", get_next_line(fdd));
		// printf("%s", get_next_line(fd));
			// printf("%s", get_next_line(fd));
	close(fdd);

}
// int main()
// {
// 	printf ("%s", ft_strjoin("ho", "ho"));
// }