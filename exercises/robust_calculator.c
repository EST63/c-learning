#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

// Функция для безопасного ввода целого числа
long long get_integer(const char *prompt)

{
    char buffer[BUFFER_SIZE];

    long long result;

    char *endptr;

    while (1)
    {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf("Ошибка ввода. Попробуйте ещё раз.\n");
            continue;
        }

        // Удаляем символ новой строки, если он есть
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }

        // Пропускаем пустые строки
        if (strlen(buffer) == 0)
        {
            printf("Ввод не может быть пустым. Попробуйте ещё раз.\n");
            continue;
        }

        errno = 0; // Сбрасываем errno перед вызовом strtol
        result = strtol(buffer, &endptr, 10);

        // Проверяем, что вся строка была успешно преобразована

        if (*endptr != '\0')
        {
            printf("Некорректный ввод: '%s' не является целым числом. Попробуйте ещё раз.\n",
                   buffer);
            continue;
        }

        // Проверяем на переполнение/недополнение

        if (errno == ERANGE)
        {
            printf("Число вне диапазона int. Попробуйте ещё раз.\n");
            continue;
        }

        // Дополнительно проверяем, что число помещается в int
        if (result < INT_MIN || result > INT_MAX)
        {
            printf("Число должно быть в диапазоне [%d, %d]. Попробуйте ещё раз.\n", INT_MIN,
                   INT_MAX);
            continue;
        }

        break; // Успешный ввод
    }

    return result;
}

// Функция для ввода операции
char get_operation(void)
{
    char buffer[BUFFER_SIZE];

    while (1)
    {
        printf("Введите операцию (+, -, *, /): ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {

            printf("Ошибка ввода. Попробуйте ещё раз.\n");
            continue;
        }

        // Удаляем символ новой строки
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }

        // Проверяем, что введена хотя бы одна буква

        if (strlen(buffer) == 0)
        {
            printf("Ввод не может быть пустым. Попробуйте ещё раз.\n");

            continue;
        }

        char op = buffer[0];
        if (op == '+' || op == '-' || op == '*' || op == '/')
        {
            return op;
        }
        else

        {
            printf("Недопустимая операция. Используйте +, -, * или /. Попробуйте ещё раз.\n");
        }
    }
}

int main(void)
{
    int num1, num2;

    char operation;
    long long result;

    // Ввод первого числа
    num1 = (int)get_integer("Введите первое целое число: ");

    // Ввод второго числа
    num2 = (int)get_integer("Введите второе целое число: ");

    // Ввод операции
    operation = get_operation();

    // Выполнение операции
    switch (operation)
    {
    case '+':
        result = (long long)num1 + num2;
        printf("Результат: %d + %d = %lld\n", num1, num2, result);
        break;
    case '-':
        result = (long long)num1 - num2;

        printf("Результат: %d - %d = %lld\n", num1, num2, result);
        break;
    case '*':
        result = (long long)num1 * num2;
        printf("Результат: %d * %d = %lld\n", num1, num2, result);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Ошибка: деление на ноль!\n");
        }
        else
        {
            result = (long long)num1 / num2;

            printf("Результат: %d / %d = %lld\n", num1, num2, result);
        }
        break;
    }

    return 0;
}
