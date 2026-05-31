#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

// Функция замены подстроки в строке
void replace_in_line(const char *line, const char *old_word, const char *new_word, 
                     char *result, size_t result_size) {
    const char *start = line;
    char *pos;
    result[0] = '\0';  // Очищаем результат
    
    while ((pos = strstr(start, old_word)) != NULL) {
        // Копируем часть до найденного слова
        size_t chunk_len = pos - start;
        if (strlen(result) + chunk_len + strlen(new_word) + 1 > result_size) {
            fprintf(stderr, "Ошибка: буфер результата слишком мал\n");
            return;
        }
        strncat(result, start, chunk_len);
        strcat(result, new_word);
        start = pos + strlen(old_word);
    }
    
    // Добавляем остаток строки
    if (strlen(result) + strlen(start) + 1 > result_size) {
        fprintf(stderr, "Ошибка: буфер результата слишком мал\n");
        return;
    }
    strcat(result, start);
}

// Функция отображения файла с номерами строк
void display_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }
    
    char line[MAX_LINE_LEN];
    int line_num = 1;
    
    printf("\n=== Содержимое файла %s ===\n", filename);
    while (fgets(line, sizeof(line), file) != NULL) {
        // Удаляем символ новой строки для красивого вывода
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        printf("%4d: %s\n", line_num++, line);
    }
    
    fclose(file);
}

// Функция замены слов в файле
int replace_in_file(const char *filename, const char *old_word, const char *new_word) {
    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        perror("Ошибка открытия файла для чтения");
        return 0;
    }
    
    // Создаём временный файл
    FILE *temp = tmpfile();
    if (temp == NULL) {
        perror("Ошибка создания временного файла");
        fclose(input);
        return 0;
    }
    
    char line[MAX_LINE_LEN];
    char new_line[MAX_LINE_LEN * 2];  // Увеличенный буфер для результата
    int replacements = 0;
    
    while (fgets(line, sizeof(line), input) != NULL) {
        // Удаляем символ новой строки для обработки
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        // Заменяем слова в строке
        replace_in_line(line, old_word, new_word, new_line, sizeof(new_line));
        
        // Записываем обработанную строку во временный файл
        fprintf(temp, "%s\n", new_line);
        
        // Подсчитываем количество замен (простой способ)
        const char *pos = line;
        while ((pos = strstr(pos, old_word)) != NULL) {
            replacements++;
            pos += strlen(old_word);
        }
    }
    
    // Перезаписываем исходный файл
    freopen(filename, "w", input);
    rewind(temp);
    
    char buffer[MAX_LINE_LEN];
    while (fgets(buffer, sizeof(buffer), temp) != NULL) {
        fputs(buffer, input);
    }
    
    fclose(input);
    fclose(temp);
    
    return replacements;
}

// Функция показа меню и получения выбора пользователя
char get_choice(void) {
    char choice;
    printf("\n=== Меню ===\n");
    printf("1. Показать содержимое файла\n");
    printf("2. Заменить слова\n");
    printf("3. Выйти\n");
    printf("Ваш выбор: ");
    
    scanf(" %c", &choice);
    return choice;
}

int main(int argc, char *argv[]) {
    // Проверка аргументов командной строки
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <имя_файла>\n", argv[0]);
        return 1;
    }
    
    const char *filename = argv[1];
    char choice;
    
    printf("Текстовый редактор для файла: %s\n", filename);
    
    while (1) {
        choice = get_choice();
        
        switch (choice) {
            case '1':
                display_file(filename);
                break;
                
            case '2': {
                char old_word[100], new_word[100];
                printf("Введите слово для замены: ");
                scanf("%99s", old_word);
                printf("Введите новое слово: ");
                scanf("%99s", new_word);
                
                int count = replace_in_file(filename, old_word, new_word);
                if (count >= 0) {
                    printf("Выполнено замен: %d\n", count);
                    printf("Файл обновлён!\n");
                } else {
                    printf("Ошибка при замене слов\n");
                }
                break;
            }
                
            case '3':
                printf("До свидания!\n");
                return 0;
                
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
                break;
        }
    }
    
    return 0;
}