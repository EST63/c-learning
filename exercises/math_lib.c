#include <stdio.h>
#include <stdlib.h>

// Прототипы функций
int sum(int a, int b);
int diff(int a, int b);
int product(int a, int b);
double quotient(int a, int b);
int max(int a, int b);
int min(int a, int b);
void swap(int *a, int *b);

int main()
{
    int num1, num2;
    int choice;

    printf("Введите первое целое число: ");
    scanf("%d", &num1);
    printf("Введите второе целое число: ");
    scanf("%d", &num2);

    // Демонстрация работы функции swap
    printf("\n--- Демонстрация функции swap ---\n");
    printf("До обмена: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("После обмена: num1 = %d, num2 = %d\n", num1, num2);
    // Возвращаем значения обратно для дальнейших операций
    swap(&num1, &num2);

    do
    {
        printf("\n--- Меню операций ---\n");
        printf("1. Сумма\n");
        printf("2. Разность\n");
        printf("3. Произведение\n");
        printf("4. Частное\n");
        printf("5. Максимум\n");
        printf("6. Минимум\n");
        printf("7. Выход\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Сумма: %d\n", sum(num1, num2));
            break;
        case 2:
            printf("Разность: %d\n", diff(num1, num2));
            break;
        case 3:
            printf("Произведение: %d\n", product(num1, num2));
            break;
        case 4:
            printf("Частное: %.2f\n", quotient(num1, num2));
            break;
        case 5:
            printf("Максимум: %d\n", max(num1, num2));
            break;
        case 6:
            printf("Минимум: %d\n", min(num1, num2));
            break;
        case 7:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
            break;
        }
    } while (choice != 7);

    return 0;
}

// Реализация функций
int sum(int a, int b)
{
    return a + b;
}

int diff(int a, int b)
{
    return a - b;
}

int product(int a, int b)
{
    return a * b;
}

double quotient(int a, int b)
{
    if (b == 0)
    {
        printf("Ошибка: деление на ноль! Возвращается 0.0.\n");
        return 0.0;
    }
    return (double)a / b;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
