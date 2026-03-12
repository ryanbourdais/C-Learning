#include <stdio.h>
#include <stdlib.h>

double miles_to_kilometers(double miles) {
    return miles * 1.60934;
}

double kilometers_to_miles(double kilometers) {
    return kilometers / 1.60934;
}

double pounds_to_kilograms(double pounds) {
    return pounds * 0.453592;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms / 0.453592;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

int get_and_validate_choice() {
    int choice;
    while(1){
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }
        if (choice >= 1 && choice <= 6) {
            return choice;// Recursively call until a valid choice is made
        }
        printf("Invalid choice!\n");
    }   
}

int main() {
    
    printf("What would you like to convert?\n1: Miles to Kilometers\n2: Kilometers to Miles\n3: Pounds to Kilograms\n4: Kilograms to Pounds\n5: Fahrenheit to Celsius\n6: Celsius to Fahrenheit\n");
    int choice;
    choice = get_and_validate_choice();
    double input, result;
    switch (choice) {
        case 1:
            printf("Enter miles: ");
            scanf("%lf", &input);
            result = miles_to_kilometers(input);
            printf("%.2lf miles = %.2lf kilometers\n", input, result);
            break;
        case 2:
            printf("Enter kilometers: ");
            scanf("%lf", &input);
            result = kilometers_to_miles(input);
            printf("%.2lf kilometers = %.2lf miles\n", input, result);
            break;
        case 3:
            printf("Enter pounds: ");
            scanf("%lf", &input);
            result = pounds_to_kilograms(input);
            printf("%.2lf pounds = %.2lf kilograms\n", input, result);
            break;
        case 4:
            printf("Enter kilograms: ");
            scanf("%lf", &input);
            result = kilograms_to_pounds(input);
            printf("%.2lf kilograms = %.2lf pounds\n", input, result);
            break;
        case 5:
            printf("Enter Fahrenheit: ");
            scanf("%lf", &input);
            result = fahrenheit_to_celsius(input);
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", input, result);
            break;
        case 6:
            printf("Enter Celsius: ");
            scanf("%lf", &input);
            result = celsius_to_fahrenheit(input);
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", input, result);
            break;
        default:
            printf("Invalid choice!\n");
    }
    char continue_choice;
    printf("Do you want to perform another conversion? (y/n): ");
    scanf(" %c", &continue_choice);
    if (continue_choice == 'y' || continue_choice == 'Y') {
        main(); // Recursively call main to perform another conversion
    }
    return 0;
}