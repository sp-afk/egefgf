# include "dc.h"
 #include <stdio.h>

void printz (z k)
{
	printf("(%f + %fi)\n", k.n, k.i);
}


int sqr(int a)
{
	int c;

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

int	gamberge (z c)
{
	int i = 0;

	z z;
	z.n = 0;
	z.i = 0;

	while (i != MAX_IT /*&& (z.n < MAX_BIG && z.i < MAX_BIG)*/ && (sqr(z.n) + sqr(z.i) < 4.0))
	{
		z = adimgk(sqrmgk(z), c);
		i++;
		//printz (z);

	}
	//printz (z);
	if(/*z.n >= MAX_BIG || z.i >= MAX_BIG*/ sqr(z.n) + sqr(z.i) > 4.0)
		return 1;
	else
		return 0;
}


void mandelbroot(t_data *data)
{
	z c;
	int px = ((X / 3)*2) * -1;
	int py = (Y / 2) *-1;

	c.n = -2.0;
	c.i = -1.0;

	while (px != X / 3 && py != Y/2)
	{
		if (gamberge(c) == 1)
			putcentpix(data ,px, py,0xFFFFFF);
		c.n += JX;
		px++;
		//printf("%d\n%d\n\n", px, X/3);
		if (px == X / 3)
		{
			c.i += JY;
			py++;
			c.n = -2;
			px = ((X / 3)*2) * -1;
		}
			//c.i++;
		//printz (c);
	}
}
/*
void julia(z c)
{

}


int main (void)
{
	z c;
	c.n = 1;
	c.i = 0;
	printf("%d", gamberge(c));
}*/
//gambrge
