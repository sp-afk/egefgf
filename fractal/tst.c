#include <stdio.h>

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


