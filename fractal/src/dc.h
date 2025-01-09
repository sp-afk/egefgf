#ifndef DC_H
# define DC_H

# include "../minilibx-linux/mlx.h"

# define X 1920
# define Y 1080
# define MAX_IT  256
# define MAX_BIG 2


typedef struct	s_z
{
	long long n;
	long long i;
}				z;

z	sqrmgk(z k);
z adimgk (z a, z b);
void printz (z k);
void mandelbroot(void *mlx, void *mlx_win);



#endif
