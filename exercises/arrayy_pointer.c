#include <stdio.h>

// Функция для разворота массива
void reverse_array(int *arr, int size)
{
    int *start = arr;
    int *end = arr + size - 1;
    int temp;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Функция для поиска максимального элемента через указатель
// Возвращает указатель на максимальный элемент
int *find_max_element(int *arr, int size)
{
    if (size <= 0)
        return NULL;

    int *max_ptr = arr;
    int *current = arr + 1;

    for (int i = 1; i < size; i++)
    {
        if (*current > *max_ptr)
        {
            max_ptr = current;
        }
        current++;
    }

    return max_ptr;
}

// Функция для вывода двумерного массива
void print_matrix(int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%4d ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

// Пример использования функций
int main()
{
    // Пример работы с одномерным массивом
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    printf("Исходный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Разворот массива
    reverse_array(arr, size);
    printf("После разворота: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Поиск максимального элемента
    int *max_ptr = find_max_element(arr, size);
    if (max_ptr != NULL)
    {
        printf("Максимальный элемент: %d, его индекс: %ld\n", *max_ptr, max_ptr - arr);
    }

    // Создание и вывод двумерного массива
    int rows = 3, cols = 4;
    int matrix[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    printf("\nМатрица:\n");
    print_matrix(&matrix[0][0], rows, cols);

    return 0;
}
