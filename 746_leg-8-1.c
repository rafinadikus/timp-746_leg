#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int *mas;
	int n = 0;
	int i = 0;
	int j = 0;
	int step;
	int tmp = 0;
	scanf("%d", &n);
	step = (n / 1.247);

	mas = (int*)malloc(n * sizeof(int));
	// Ввод элементов массива
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &mas[i]);
	}
	hoarasort(mas,0,n-1);

	// Вывод элементов массива
	for (i = 0; i < n; i++)
		printf("%d ", mas[i]);
	free(mas);
	getchar();   getchar();
	return 0;

}


void hoarasort(int* mas, int first, int last)
{

int i = first, j = last;
double tmp, x = mas[(first + last) / 2];

do {
   while (mas[i] < x)
     i++;
   while (mas[j] > x)
     j--;

   if (i <= j)
   {
     if (i < j)
     {
       tmp=mas[i];
       mas[i]=mas[j];
       mas[j]=tmp;
     }
     i++;
     j--;
   }
} while (i <= j);

if (i < last)
   hoarasort(mas, i, last);
if (first < j)
   hoarasort(mas, first,j);
}

