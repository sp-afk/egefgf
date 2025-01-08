#include "mlx.h"
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
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    mlx_loop(mlx);
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
