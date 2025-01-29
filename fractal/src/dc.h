#ifndef DC_H
# define DC_H

# include "../minilibx-linux/mlx.h"

# define X 1000
# define Y 800
# define MAX_IT  255
# define MAX_BIG 2
# define HB 2.0
# define GD 3.0
# define JY (HB / Y)
# define JX (GD / X)

typedef struct	s_z
{
	double n;
	double i;
}				z;

typedef struct	s_data
{
	void *mlx;
	void *win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


z	sqrmgk(z k);
z adimgk (z a, z b);
void printz (z k);
void mandelbroot(t_data *data);
void putcentpix(t_data *data, int x, int y, int color);
void julia(t_data *data ,z c);
z	crtcmplx(double k , double c);




#endif
