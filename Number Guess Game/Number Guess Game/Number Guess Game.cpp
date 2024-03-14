#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
class NumberGuessingGame 
{
private:
	int secretNumber;
	int numAttempts;
public:
	NumberGuessingGame() 
{
	// Initialize random seed
	srand(time(0));
	// Generate random number between 1 and 100
	secretNumber = rand() % 100 + 1;
	numAttempts = 0;
}
	void play() 
{
	int guess;
	bool guessedCorrectly = false;
	std::cout << "Welcome to the Number Guessing Game!\n";
	std::cout << "Try to guess the secret number between 1 and 100.\n\n";
	while (!guessedCorrectly) 
{
	std::cout << "Enter your guess: ";
	std::cin >> guess;
	numAttempts++;
	if (guess == secretNumber) 
{
	guessedCorrectly = true;
	std::cout << "Congratulations! You've guessed the correct number in " << numAttempts << " attempts!\n";
}
	else if (guess < secretNumber) 
{
	std::cout << "Too low! Try again.\n";
}
	else 
{
	std::cout << "Too high! Try again.\n";
}
}
}
};
int main() 
{
	NumberGuessingGame game;
	game.play();
	return 0;
}