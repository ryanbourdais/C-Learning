#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}

int main(void) {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("Enter an operator (+, -, *, /): ");
    char operator;
    scanf(" %c", &operator);
    switch (operator)
    {
    case '+':
        printf("Result: %d\n", add(a, b));
        break;
    case '-':
        printf("Result: %d\n", subtract(a, b));
        break;
    case '*':
        printf("Result: %d\n", multiply(a, b));
        break;
    case '/':
        if(b == 0) {
            fprintf(stderr, "Error: Division by zero is not allowed.\n");
            printf("NaN\n");
            break;
        }
        printf("Result: %d\n", divide(a, b));
        break;
    default:
        fprintf(stderr, "Error: Invalid operator.\n");
        break;
    }
    printf("Continue? (y/n): ");
    char cont;
    scanf(" %c", &cont);
    if (cont == 'y' || cont == 'Y') {
        main();
    }
    return 0;
}