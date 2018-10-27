#include <stdio.h>
#include <math.h>
int main()
{
	int n, x;
	int hh;
	hh = 0;
	int i = 0;
	printf("Wwedite n \n");
	scanf("%d", &n);
	do {
		printf("Wwedite X \n");
		scanf("%d", &x);
		i++;
		hh = hh + ((i + 1) % 2)*x*x*x;
		
	} while (i != n);
	printf("%d", hh);
	return 0;
}
