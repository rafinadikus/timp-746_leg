#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int *mas;
	int n = 0;
	int i = 0;
	int j = 0;

	scanf("%d", &n);
	float	step = (n / 1.247);

	mas = (int*)malloc(n * sizeof(int));
	// Ввод элементов массива
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &mas[i]);
	}


	heapsort(mas,n);

	// Вывод элементов массива
	for (i = 0; i < n; i++)
		printf("%d ", mas[i]);
	free(mas);
	getchar();   getchar();
	return 0;

}


void siftdown(int *mas, int root, int bottom)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done))
  {
    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (mas[root * 2] > mas[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (mas[root] < mas[maxChild])
    {
      int temp = mas[root]; // меняем их местами
      mas[root] = mas[maxChild];
      mas[maxChild] = temp;
      root = maxChild;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}
// Функция сортировки на куче
void heapsort(int *mas, int an)
{
  // Формируем нижний ряд пирамиды
  for (int i = (n / 2) - 1; i >= 0; i--)
    siftdown(mas, i, n - 1);
  // Просеиваем через пирамиду остальные элементы
  for (int i = n - 1; i >= 1; i--)
  {
    int tmp = mas[0];
    mas[0] = mas[i];
    mas[i] = tmp;
    siftdown(mas, 0, i - 1);
  }
}
