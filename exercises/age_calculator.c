// age_calculator.c - калькулятор возраста с улудшениями
#include <stdio.h>
#include <string.h>

int main(void)
{
    // запрос имени с помощью fgets()
    printf("Введите ваше имя: ");
    char name[50];
    fgets(name, sizeof(name), stdin);
    // удаление последнего символа - перевод строки
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
    {
        name[len - 1] = '\0';
    }

    // запрос года рождения с помощью scanf()
    int brith_year;
    printf("Введите ваш год рождения: ");
    if ((scanf("%d", &brith_year)) != 1)
    {
        printf("Ошибка введите целое число.\n");
        return 1;
    }
    // проверка на разумный год
    if (brith_year < 1900 || brith_year > 2026)
    {
        printf("Ошибка:год рождения вне диапозона от 1900 до 2026\n");
        return 1;
    }
    while (getchar() != '\n')
    {
    }

    // запрос текущего года с помощью scanf()
    int current_year;
    printf("Введите текущий год: ");
    if ((scanf("%d", &current_year) != 1))
    {
        printf("Вы ввели некорректные данные\n");
        return 1;
    }
    if (current_year < 2025 || current_year > 2026)
    {
        printf("Ошибка: текущий год вне диапозона от 2025 до 2026\n");
        return 1;
    }
    while (getchar() != '\n')
    {
    }

    // расчет возраста
    int age = current_year - brith_year;
    // если возраст вне диапозона от 0 до 150 - сообщение об ошибке и завершение программы
    if (age < 0 || age > 150)
    {
        printf("Ваш возраст вне диапозона от 0 до 150\n");
        return 1;
    }

    // вывод результатов
    printf("Ваше имя: %s\n", name);
    printf("Ваш возраст: %d\n", age);
    printf("Ваш год рождения: %d\n", brith_year);
    return 0;
}
