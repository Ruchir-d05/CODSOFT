#include <iostream>
#include<cstdlib>  
#include  <ctime>    


int  main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int numberToGuess = std::rand() % 100 + 1; 
    int guess = 0;

    std::cout << "I have generated a random number between 1 and 100. Try to guess it!" << std::endl;

    while (guess != numberToGuess) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess < numberToGuess) {
            std::cout << "Too low, try again." << std::endl;
        } else if (guess > numberToGuess) {
            std::cout << "Too high, try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
        }
    }

    return 0;
}
