#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int *mas;
	int n = 0;
	int i = 0;
	int tmp = 0;
	scanf("%d", &n);

	mas = (int*)malloc(n * sizeof(int));
	// Ввод элементов массива
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &mas[i]);
	}

	combsort(mas, n);

	// Вывод элементов массива
	for (i = 0; i < n; i++)
		printf("%d ", mas[i]);
	free(mas);
	getchar();   getchar();
	return 0;


	//scanf("%d", &n);
	return 0;
}


void combsort(int*mas, int n)
{
    int i = 0;
	int j = 0;
	int tmp;
	int step;
    step = (n / 1.247);

    while (step >= 1)
	{
		for (i = 0; i + step < n; i++)
		{
			if (mas[i] > mas[i + step])
			{
				tmp = mas[i];
				mas[i] = mas[i + step];
				mas[i + step] = tmp;
				//swap(mas[i], mas[i + step]);
			}
		}
		step /= 1.247;
	}
	// сортировка пузырьком
	for (i = 0; i < n - 1; i++) {
		// сравниваем два соседних элемента.
		for (j = 0; j < n - i - 1; j++) {
			if (mas[j] > mas[j + 1]) {
				// если они идут в неправильном порядке, то
				//  меняем их местами.
				tmp = mas[i];
				mas[i] = mas[i + step];
				mas[i + step] = tmp;
			}
		}
	}
}
