#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

struct word_choice {
    char word[20];
};

void load_words(struct word_choice word_choices[], int *count ) {
    FILE *file = fopen("word_choices.txt", "r");
    if (file == NULL) {
        *count = 0;
        return;
    }
    *count = 0;
    while (*count < 100 &&
            fscanf(file, "%19[^\n]\n", word_choices[*count].word) == 1) {
            (*count)++;
        }
        fclose(file);
}

void initialize_game(struct word_choice word_choices[], char chosen_word[20], bool *gameOver, char current_guesses[20], char incorrect_guesses[10], int *incorrect_guess_count) {
    int random_index = rand() % 100; // Randomly select a word
    strcpy(chosen_word, word_choices[random_index].word);
    memset(current_guesses, '_', strlen(chosen_word)); // Initialize current guesses with underscores
    current_guesses[strlen(chosen_word)] = '\0'; // Null-terminate the string
    memset(incorrect_guesses, 0, sizeof(incorrect_guesses)); // Clear incorrect guesses
    *incorrect_guess_count = 0; // Reset incorrect guess count
    *gameOver = false; // Game is not over at the start
}

void print_board(char current_guesses[20], char incorrect_guesses[10], int incorrect_guess_count) {
    printf("Current word: %s\n", current_guesses);
    printf("Incorrect guesses: ");
    for (int i = 0; i < incorrect_guess_count; i++) {
        printf("%c ", incorrect_guesses[i]);
    }
    printf("\n");
}

void play_turn(char current_guesses[20], char incorrect_guesses[10], int *incorrect_guess_count, char chosen_word[20]) {
    printf("Enter your guess: ");
    char guess;
    scanf(" %c", &guess);
    // Check if the guess is correct
    bool correct = false;
    for (int i = 0; chosen_word[i] != '\0'; i++) {
        if (chosen_word[i] == guess) {
            current_guesses[i] = guess; // Update current guesses
            correct = true;
        }
    }
    if (!correct) {
        incorrect_guesses[*incorrect_guess_count] = guess; // Add to incorrect guesses
        (*incorrect_guess_count)++;
    }
}
    
void validate_game(char chosen_word[20], char current_guesses[20], char incorrect_guesses[10], int incorrect_guess_count, bool *gameOver) {
    // Check if the player has guessed the word
    if (strcmp(chosen_word, current_guesses) == 0) {
        printf("Congratulations! You've guessed the word: %s\n", chosen_word);
        *gameOver = true;
        return;
    }
    // Check if the player has made too many incorrect guesses
    if (incorrect_guess_count >= 6) {
        printf("Game Over! You've made too many incorrect guesses. The word was: %s\n", chosen_word);
        *gameOver = true;
    }
}

void play_game(char chosen_word[20], char current_guesses[20], char incorrect_guesses[10], int incorrect_guess_count, bool gameOver) {
    while(!gameOver)
    {
        print_board(current_guesses, incorrect_guesses, incorrect_guess_count);
        play_turn(current_guesses, incorrect_guesses, &incorrect_guess_count, chosen_word);
        validate_game(chosen_word, current_guesses, incorrect_guesses, incorrect_guess_count, &gameOver);
    }
}

int main()
{
    srand((unsigned)time(NULL)); // Seed the random number generator
    struct word_choice word_choices[100];
    int count = 0;
    load_words(word_choices, &count);
    bool playing = true;
    bool gameOver;
    char current_guesses[20];
    char incorrect_guesses[10];
    char chosen_word[20];
    int incorrect_guess_count;
    while(playing) {
        printf("Welcome to Hangman!\n");
        printf("1. Start Game\n2. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Starting game...\n");
                initialize_game(word_choices, chosen_word, &gameOver, current_guesses, incorrect_guesses, &incorrect_guess_count);
                play_game(chosen_word, current_guesses, incorrect_guesses, incorrect_guess_count, gameOver);
                break;
            case 2:
                printf("Exiting...\n");
                playing = false;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

}