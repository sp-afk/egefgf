# include "dc.h"
 #include <stdio.h>

void printz (z k)
{
	printf("(%f + %fi)\n", k.n, k.i);
}

z	crtcmplx(double k , double c)
{
	z d;
	d.n = k;
	d.i = c;

	return d;
}
/*int sqr(int a)
{
	int c;

	c = a * a;
	return c;
}*/
double sqr(double a)
{
	double c;

	c = a * a;
	return c;
}

z	sqrmgk(z k)
{
	z c;

	c.n = sqr(k.n) - sqr(k.i);
	c.i = 2 *k.n * k.i;
	return(c);
}

z adimgk (z a, z b)
{
	z c;

	c.n = a.n + b.n;
	c.i = a.i + b.i;
	return (c);
}

int	gamberge (z c, z z)
{
	int i = 0;

	while (i != MAX_IT /*&& (z.n < MAX_BIG && z.i < MAX_BIG)*/ && (sqr(z.n) + sqr(z.i) < 4.0))
	{
		z = adimgk(sqrmgk(z), c);
		i++;
		//printz (z);

	}
	//printz (z);
	if(/*z.n >= MAX_BIG || z.i >= MAX_BIG*/ sqr(z.n) + sqr(z.i) > 4.0)
		return i;
	else
		return -1;
}


void mandelbroot(t_data *data)
{
	z c;
	z z;
	int px = ((X / 3)*2) * -1;
	int py = (Y / 2);

	z.n = 0;
	z.i = 0;
	c.n = -2.0;
	c.i = 1.0;

	while (px != X / 3 && py != (Y/2)*-1)
	{
		if (gamberge(c,z) > -1)
			putcentpix(data ,px, py,(gamberge(c,z) * 65793));
		c.n += JX;
		px++;
		//printf("%d\n%d\n\n", px, X/3);
		if (px == X / 3)
		{
			c.i -= JY;
			py--;
			c.n = -2;
			px = ((X / 3)*2) * -1;
		}
			//c.i++;
		//printz (c);
	}
}

void julia(t_data *data ,z c)
{
	z z;
	int px = ((X / 3)*2) * -1;
	int py = (Y / 2) *-1;

	z.n = -2.0;
	z.i = 1;

	while (px != X / 3 && py != Y/2)
	{
		if (gamberge(c,z) == 1)
			putcentpix(data ,px, py,0xFFFFFF);
		z.n += JX;
		px++;
		//printf("%d\n%d\n\n", px, X/3);
		if (px == X / 3)
		{
			z.i += JY;
			py++;
			z.n = -2;
			px = ((X / 3)*2) * -1;
		}
			//c.i++;
		//printz (c);
	}
}


/*int main (void)
{
	z c;
	c.n = 1;
	c.i = 0;
	//printf("%d", gamberge(c));
}*/
//gambrge
