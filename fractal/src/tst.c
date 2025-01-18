#include "dc.h"
/*#include <stdio.h>

void printm(int i)
{
	static int z;

	if (i == 1)
		write(1,'.', 1)
	else
		write(1,' ', 1)

}


int main (void)
{
	printf("%.*s\n", 50, "..............");
	return 0;
}

*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void putcentpix(t_data *data, int x, int y, int color)
{
	my_mlx_pixel_put(data, (((X / 3)*2) + x), ((Y/2) + y), color);
}
