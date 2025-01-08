# include "dc.h"
 #include <stdio.h>

void printz (z k)
{
	printf("(%lld + %lldi)\n", k.n, k.i);
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

	while (i != MAX_IT && (z.n < MAX_BIG && z.i < MAX_BIG))
	{
		z = adimgk(sqrmgk(z), c);
		i++;
		printz (z);

	}
	printz (z);
	if(z.n >= MAX_BIG || z.i >= MAX_BIG)
		return 1;
	else
		return 0;
}


/*void mandelbroot()
{
	z k;
	z c;

	while (c.n != X && c.i != Y)
	{
		if (gamberge(c) == 1)
			//putp(mlx, c.n, c.i)
		else
			//putp(mlx, c.n, c.i)
		c.n++;
		if (c.n == X)
			c.i++;
	}
}*/

int main (void)
{
	z c;
	c.n = 1;
	c.i = 0;
	printf("%d", gamberge(c));
}
//gambrge
