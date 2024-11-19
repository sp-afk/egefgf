#include <stdio.h>
#include <string.h>

int		cheker(char *str)
{
	int i = 0;
	while(str[i] != 0)
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == 32)
			i++;
		else
			return 1;
	}
	return 0;
}

int		compteur(char *str, int *z)
{
	int i = 0;
	while(str[i] != 0)
	{
		if(str[0] == 32)
			return 1;

		if(str[i] == 32)
		{
			i++;
			(*z)++;
			if (str [i] == 32)
				return 1;
			else
				i--;
		}
	i++;
	}
	i--;
	if (str[i] == 32)
		return 1;
	(*z)++;
	return 0;
}

int main (int av, char **ac)
{
	int sr = 0;
	int z = 0;

	if (av == 2)
	{
		sr = strlen (ac[1]);
		sr += cheker(ac[1]);
		sr += compteur(ac[1], &z);
		if (sr != (int)strlen (ac[1]) || sr == 0)
			printf("met un bonne imput sale zgeug\n");
		else
			printf("bv batard ta pute %d ombre\n", z);
	}
	return 0;
}
