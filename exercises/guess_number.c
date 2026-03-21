#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Инициализация генератора случайных чисел
    char play_again;

    do
    {
        int secret_number = rand() % 100 + 1; // Случайное число от 1 до 100
        int guess, attempts = 0;
        int valid_input;

        printf("\n=== Игра 'Угадай число' ===\n");
        printf("Я загадал число от 1 до 100. Попробуй угадать!\n");

        while (1)
        {
            printf("Твоя попытка: ");
            valid_input = scanf("%d", &guess);

            // Очистка буфера ввода

            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            // Проверка корректности ввода
            if (valid_input != 1)
            {
                printf("Ошибка: введите целое число!\n");
                continue;
            }

            // Проверка диапазона
            if (guess < 1 || guess > 100)
            {
                printf("Ошибка: число должно быть в диапазоне от 1 до 100!\n");
                continue;
            }

            attempts++; // Учитываем только корректные попытки

            // Сравнение и подсказки
            if (guess < secret_number)
            {
                printf("Меньше\n");
            }
            else if (guess > secret_number)
            {
                printf("Больше\n");
            }
            else
            {
                printf("Угадал!\n");
                printf("Поздравляю! Вы угадали число %d за %d попыток.\n", secret_number, attempts);
                break; // Выходим из цикла при угадывании
            }
        }

        // Предложение сыграть ещё раз

        printf("Хотите сыграть снова? (y/n): ");
        scanf(" %c", &play_again); // Пробел перед %c пропускает пробельные символы

        // Очистка буфера после ввода символа
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

    } while (play_again == 'y' || play_again == 'Y');

    printf("Спасибо за игру!\n");
    return 0;
}
