#include <iostream>

int main() {
    double firstNumber, secondNumber;
    char op;
    double answer;
    std::cout << "Welcome to the Simple Calculator!" << std::endl;
    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> op;
    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;

    if (op == '+') {
        answer = firstNumber + secondNumber;
        std::cout << "Result: " << answer << std::endl;
    } else if (op == '-') {
        answer = firstNumber - secondNumber;
        std::cout << "Result: " << answer << std::endl;
    } else if (op == '*') {
        answer = firstNumber * secondNumber;
        std::cout << "Result: " << answer << std::endl;
    } else if (op == '/') {
        if (secondNumber == 0) {
            std::cout << "Cannot divide by zero!" << std::endl;
        } else {
            answer = firstNumber / secondNumber;
            std::cout << "Result: " << answer << std::endl;
        }
    } else {
        std::cout << "Sorry, that operation is not supported." << std::endl;
    }

    return 0;
}
