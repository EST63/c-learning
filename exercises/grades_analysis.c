#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 30
#define NAME_LENGTH 100

// Прототипы функций
float average(int grades[], int n);
int max_grade(int grades[], int n, int *index);
int min_grade(int grades[], int n, int *index);

int above_average_count(int grades[], int n, float avg);

int main()
{
    int num_students;

    // Запрос количества студентов с проверкой
    do
    {
        printf("Введите количество студентов (1-%d): ", MAX_STUDENTS);
        if (scanf("%d", &num_students) != 1)
        {
            // Очистка буфера ввода

            while (getchar() != '\n')
                ;
            num_students = 0;
        }
    } while (num_students < 1 || num_students > MAX_STUDENTS);

    char names[MAX_STUDENTS][NAME_LENGTH];
    int grades[MAX_STUDENTS];

    // Ввод данных для каждого студента
    for (int i = 0; i < num_students; i++)
    {

        // Очистка буфера перед вводом имени
        while (getchar() != '\n')
            ;

        // Ввод имени
        printf("Студент %d. Введите имя: ", i + 1);
        fgets(names[i], NAME_LENGTH, stdin);

        // Удаление символа \n в конце строки

        size_t len = strlen(names[i]);
        if (len > 0 && names[i][len - 1] == '\n')
        {

            names[i][len - 1] = '\0';
        }

        // Ввод оценки с проверкой
        int grade;
        do
        {
            printf("Введите оценку для %s (0-100): ", names[i]);
            if (scanf("%d", &grade) != 1)
            {
                // Очистка буфера ввода
                while (getchar() != '\n')
                    ;
                grade = -1; // Некорректное значение для повторной проверки
            }

        } while (grade < 0 || grade > 100);

        grades[i] = grade;
    }

    // Вычисление статистики
    float avg = average(grades, num_students);

    int max_index, min_index;
    int max_val = max_grade(grades, num_students, &max_index);
    int min_val = min_grade(grades, num_students, &min_index);
    int above_avg_count = above_average_count(grades, num_students, avg);

    // Вывод результатов
    printf("\n"
           "================================================\n"

           "              АНАЛИЗ УСПЕВАЕМОСТИ\n"
           "================================================\n");

    // Таблица студентов и оценок
    printf("Список студентов:\n");
    printf("%-20s %s\n", "Имя", "Оценка");

    printf("-------------------- --------\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("%-20s %6d\n", names[i], grades[i]);
    }

    printf("\nСтатистика:\n");
    printf("Средняя оценка: %.2f\n", avg);

    printf("Максимальная оценка: %d (студент %s)\n", max_val, names[max_index]);
    printf("Минимальная оценка: %d (студент %s)\n", min_val, names[min_index]);
    printf("Студентов с оценкой выше средней: %d\n", above_avg_count);

    return 0;
}

// Функция вычисления среднего арифметического
float average(int grades[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += grades[i];
    }
    return (float)sum / n;
}

// Функция поиска максимальной оценки и её индекса
int max_grade(int grades[], int n, int *index)
{
    int max_val = grades[0];
    *index = 0;

    for (int i = 1; i < n; i++)
    {
        if (grades[i] > max_val)
        {
            max_val = grades[i];
            *index = i;
        }
    }

    return max_val;
}

// Функция поиска минимальной оценки и её индекса
int min_grade(int grades[], int n, int *index)
{
    int min_val = grades[0];
    *index = 0;

    for (int i = 1; i < n; i++)
    {
        if (grades[i] < min_val)
        {
            min_val = grades[i];
            *index = i;
        }
    }
    return min_val;
}

// Функция подсчёта студентов с оценкой выше средней
int above_average_count(int grades[], int n, float avg)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (grades[i] > avg)
        {
            count++;
        }
    }

    return count;
}
