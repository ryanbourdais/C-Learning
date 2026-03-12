
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int guess = 0;
    int guesses = 0;
    int number = 0;
    
    srand((unsigned)time(NULL));
    number = rand() % 100 + 1;

    while (guess != number && guesses < 10)
    {
        printf("Enter your guess (1 - 100): ");
        scanf("%d", &guess);
        if(guess < 1 || guess > 100)
        {
            printf("Invalid input! Please enter a number between 1 and 100.\n");
            continue;
        }
        guesses++;
        if (guess < number)
        {
            printf("Too low! Try again.\n");
        }
        else if (guess > number)
        {
            printf("Too high! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d guesses.\n", guesses);
        }
    }
    printf("The number was: %d\n", number);
    printf("Want to play again? (y/n): ");
    char playAgain;
    scanf(" %c", &playAgain);
    if (playAgain == 'y' || playAgain == 'Y')
    {        
        main();
    }
    return 0;
}