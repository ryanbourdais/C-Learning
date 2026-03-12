#include <iostream>
#include <limits>
#include <random>

int generateNumber() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(1, 100);
    return dist(gen);
}

void clearBadInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        int guess = 0;
        int guesses = 0;
        int number = generateNumber();

        while (guess != number && guesses < 10) {
            std::cout << "Enter your guess (1 - 100): ";

            if (!(std::cin >> guess)) {
                std::cout << "Invalid input! Please enter a whole number.\n";
                clearBadInput();
                continue;
            }

            if (guess < 1 || guess > 100) {
                std::cout << "Invalid input! Please enter a number between 1 and 100.\n";
                continue;
            }

            guesses++;

            if (guess < number) {
                std::cout << "Too low! Try again.\n";
            } else if (guess > number) {
                std::cout << "Too high! Try again.\n";
            } else {
                std::cout << "Congratulations! You guessed the number in "
                          << guesses << " guesses.\n";
            }
        }

        std::cout << "The number was: " << number << '\n';
        std::cout << "Want to play again? (y/n): ";
        std::cin >> playAgain;
    }

    return 0;
}
