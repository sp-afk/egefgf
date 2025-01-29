# include "dc.h"
#include <stdio.h>

/*int sqr(int a)
{
	int c;

	c = a * a;
	return c;
}

z	sqrmgk(z k)
{
	z ;

	c.n = sqr(k.n) - sqr(k.i);
	c.i = 2 *k.n * k.i;
	return(c);
}
void printz (z k)
{
	printf("(%d + %di)\n", k.n, k.i);
}
*/
double	atoy(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

int main(int ac, char **av)
{
	t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, X, Y, "ez");
	data.img = mlx_new_image(data.mlx, X, Y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	if (ac == 1)
    	mandelbroot(&data);
	if (ac == 4)
		putcentpix(&data, -1080, -540, 0xFFFFFF);

	if (ac == 3)
		julia(&data, crtcmplx(atoy(av[1]),atoy(av[2])));
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	//putcentpix(0, 0, mlx, mlx_win, 0xFFFFFF);
    mlx_loop(data.mlx);
    return 0;
}



/*
z b;
	b.n = 3;
	b.i = 2;

	printz(sqrmgk(b));
void	*mlx = mlx_init();

	void	*windows = mlx_new_window(mlx, 1080, 600, "ZEUB");
	mlx_loop (mlx);*/
