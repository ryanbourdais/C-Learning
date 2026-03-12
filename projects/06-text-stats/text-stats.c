#include <stdio.h>
#include <string.h>
#include <stdbool.h>


FILE *check_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    return file;
}

void close_file(FILE *file) {
    if (file != NULL) {
        fclose(file);
    }
}

int count_chars(FILE *file) {
    int count = 0;
    while (fgetc(file) != EOF) {
        count++;
    }
    return count;
}

int count_words(FILE *file) {
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    int count = 0;
    char word[256];
    while (fscanf(file, "%255s", word) == 1) {
        count++;
    }
    return count;
}

int count_lines(FILE *file) {
    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        count++;
    }
    return count;
}

int main() {
    printf("Enter a file path: ");
    char file_path[256];
    fgets(file_path, sizeof(file_path), stdin);
    file_path[strcspn(file_path, "\n")] = '\0';
    FILE *file = check_file(file_path);
    if (file == NULL) {
        return 1;
    }
    int char_count = count_chars(file);
    rewind(file);
    int word_count = count_words(file);
    rewind(file);
    int line_count = count_lines(file);
    close_file(file);
    printf("Number of characters: %d\n", char_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of lines: %d\n", line_count);
    return 0;
}