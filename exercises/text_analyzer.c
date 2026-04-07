#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

int main()
{
    char text[MAX_LEN + 1];
    int choice;

    printf("Введите строку текста: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
    {
        printf("Ошибка ввода строки.\n");
        return 1;
    }

    // Удаляем символ \n в конце, если он есть
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n')
    {
        text[len - 1] = '\0';
    }

    do
    {
        printf("Меню:\n");
        printf("1. Подсчитать гласные и согласные\n");
        printf("2. Подсчитать цифры\n");
        printf("3. В верхний регистр\n");
        printf("4. В нижний регистр\n");
        printf("5. Выйти\n");
        printf("Ваш выбор: ");

        if (scanf("%d", &choice) != 1)
        {

            // Очистка буфера ввода при неверном вводе
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("Ошибка: введите целое число от 1 до 5.\n\n");
            continue;
        }

        // Очистка буфера после scanf
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        switch (choice)
        {
        case 1:
        {
            int vowels = 0, consonants = 0;
            for (int i = 0; text[i] != '\0'; i++)
            {
                if (isalpha((unsigned char)text[i]))
                {
                    char c = tolower((unsigned char)text[i]);

                    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    {
                        vowels++;
                    }
                    else
                    {
                        consonants++;
                    }
                }
            }
            printf("Гласных: %d, согласных: %d\n\n", vowels, consonants);
            break;
        }
        case 2:
        {
            int digits = 0;
            for (int i = 0; text[i] != '\0'; i++)
            {
                if (isdigit((unsigned char)text[i]))
                {
                    digits++;
                }
            }
            printf("Цифр: %d\n\n", digits);
            break;
        }
        case 3:
        {
            printf("Результат: ");
            for (int i = 0; text[i] != '\0'; i++)
            {
                printf("%c", toupper((unsigned char)text[i]));
            }
            printf("\n\n");
            break;
        }
        case 4:
        {
            printf("Результат: ");
            for (int i = 0; text[i] != '\0'; i++)
            {
                printf("%c", tolower((unsigned char)text[i]));
            }
            printf("\n\n");

            break;
        }
        case 5:
        {
            printf("До свидания!\n");
            break;
        }
        default:
        {
            printf("Ошибка: введите целое число от 1 до 5.\n\n");
            break;
        }
        }
    } while (choice != 5);

    return 0;
}
