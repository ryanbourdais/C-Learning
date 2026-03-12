#include <stdio.h>
#include <iostream>

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
        std::cerr << "Error: Division by zero is not allowed.\n";
        return 0;
    }
    return a / b;
}

int main(void) {
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;
    std::cout << "Enter an operator (+, -, *, /): ";
    char op;
    std::cin >> op;
    switch (op)
    {
    case '+':
        std::cout << "Result: " << add(a, b) << std::endl;
        break;
    case '-':
        std::cout << "Result: " << subtract(a, b) << std::endl;
        break;
    case '*':
        std::cout << "Result: " << multiply(a, b) << std::endl;
        break;
    case '/':
        if(b == 0) {
            std::cerr << "Error: Division by zero is not allowed.\n";
            std::cout << "NaN\n";
            break;
        }
        std::cout << "Result: " << divide(a, b) << std::endl;
        break;
    default:
        std::cerr << "Error: Invalid operator.\n";
        break;
    }
    std::cout << "Continue? (y/n): ";
    char cont;
    std::cin >> cont;
    if (cont == 'y' || cont == 'Y') {
        main();
    }
    return 0;
}