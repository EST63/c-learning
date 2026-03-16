#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 10
#define NAME_LENGTH 100

int main()
{
    char names[MAX_NAMES][NAME_LENGTH];

    int count;
    char input[20]; // буфер для ввода числа

    // Запрос количества имён с проверкой корректности
    while (1)
    {
        printf("Введите количество имён (от 1 до %d): ", MAX_NAMES);
        if (fgets(input, sizeof(input), stdin) == NULL)
        {

            printf("Ошибка ввода!\n");
            return 1;
        }

        // Удаляем символ новой строки, если он есть
        input[strcspn(input, "\n")] = '\0';

        // Преобразуем строку в число
        char *end;
        count = (int)strtol(input, &end, 10);

        // Проверяем корректность преобразования и диапазон
        if (*end == '\0' && count >= 1 && count <= MAX_NAMES)
        {
            break;
        }
        else
        {
            printf("Некорректный ввод. Пожалуйста, введите число от 1 до %d.\n", MAX_NAMES);
        }
    }

    printf("\nВведите %d имён (можно с пробелами):\n", count);

    // Ввод имён с помощью fgets
    for (int i = 0; i < count; i++)
    {

        printf("%d: ", i + 1);

        if (fgets(names[i], NAME_LENGTH, stdin) == NULL)
        {
            printf("Ошибка ввода имени!\n");
            return 1;
        }
        // Удаляем символ новой строки из имени
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    // Вывод всех имён в столбик с порядковыми номерами
    printf("\n--- Все имена ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, names[i]);
    }

    // Поиск самого длинного имени
    int max_length = 0;
    int longest_index = 0;

    for (int i = 0; i < count; i++)
    {
        int current_length = strlen(names[i]);
        if (current_length > max_length)
        {
            max_length = current_length;

            longest_index = i;
        }
    }

    printf("\n--- Самое длинное имя ---\n");
    printf("Имя: %s\n", names[longest_index]);
    printf("Длина: %d символов\n", max_length);

    // Вывод имён в обратном порядке
    printf("\n--- Имена в обратном порядке ---\n");
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d. %s\n", count - i, names[i]);
    }

    return 0;
}
