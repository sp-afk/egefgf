# include "dc.h"

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


int main(void)
{
	t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, X, Y, "Hello world!");
	data.img = mlx_new_image(data.mlx, X, Y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    mandelbroot(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	//putcentpix(0, 0, mlx, mlx_win, 0xFFFFFF);
    mlx_loop(data.mlx);
    return 0; // Ajoutez un retour explicite pour éviter d'autres avertissements potentiels.
}



/*
z b;
	b.n = 3;
	b.i = 2;

	printz(sqrmgk(b));
void	*mlx = mlx_init();

	void	*windows = mlx_new_window(mlx, 1080, 600, "ZEUB");
	mlx_loop (mlx);*/
