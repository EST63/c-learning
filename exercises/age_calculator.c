// age_calculator.c - каалькулятор возраста с улудшениями
#include <stdio.h>
int main(void)
{
    // запрос имени с помощью fgets()
    printf("Введите ваше имя: ");
    char name[50];
    fgets(name, sizeof(name), stdin);
    // запрос года рождения с помощью scanf()
    int age;
    printf("Введите ваш год рождения: ");
    if ((scanf("%d", &age)) != 1)
    {
        printf("Вы ввели некорректные данные\n");
        return 1;
    }
    if (age <= 0)
    {
        printf("Вы ввели некорректный год рождения\n");
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
    if (current_year <= 0)
    {
        printf("Вы ввели некорректный год\n");
        return 1;
    }
    while (getchar() != '\n')
    {
    }

    // расчет возраста
    int year_of_birth = current_year - age;
    // если возраст вне диапозона от 0 до 150 - сообщение об ошибке и завершение программы
    if (year_of_birth < 0 || year_of_birth > 150)
    {
        printf("Ваш возраст вне диапозона от 0 до 150\n");
        return 1;
    }
    printf("Ваше имя: %s", name);
    printf("Ваш возраст: %d\n", year_of_birth);
    printf("Ваш год рождения: %d\n", age);
    return 0;
}
