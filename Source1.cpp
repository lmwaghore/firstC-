#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <string>
#include <math.h>

using namespace std;

void showMenu();
void selection();
void playGame1();
void playGame2();
void playGame3();
void playGame4();

int main() {
	//gets random number using clock time changing
	srand(time(NULL));
	selection();
	return 0;
}
//user menu
void showMenu() {
	cout << "------------------" << endl << "0. Quit" << endl;
	cout << "1. Play Game 1 (guess the number)" << endl;
	cout << "2. Play Game 2 (pull sticks)" << endl;
	cout << "3. Play Game 3 (roll some dice)" << endl;
	cout << "4. Play Game 4 (Rock, Paper Scissors)" << endl;
}

//user selection
void selection() {
	int choice;

	do {
		showMenu();
		cin >> choice;

		switch (choice) {
		case 0:
			cout << "Alright. See ya later!" << endl;
			break;
		case 1:
			playGame1();
			break;
		case 2:
			playGame2();
			break;
		case 3:
			playGame3();
			break;
		case 4:
			playGame4();
			break;
		}
	} while (choice != 0);
}

//user guesses number
void playGame1() {
	vector<int> playerGuess;
	string again;
	do {
		int randomNum = rand() % 501;

		cout << "Try to guess a number between 0 and 500" << endl << "What is your guess?" << endl;

		while (true) {
			int guess;
			cin >> guess;
			playerGuess.push_back(guess);

			if (guess == randomNum) {
				cout << "Good guess! You win!" << endl;
				cout << "You guessed " << playerGuess.size() << " times." << endl;
				cout << "Your guesses were: ";
				for (int i = 0; i < playerGuess.size(); i++) {
					cout << playerGuess[i] << " ";
				}
				cout << endl;
				break;
			}
			else if (guess < randomNum) {
				cout << "Guess is too low. Try again." << endl;
			}
			else {
				cout << "Guess is too high. Try again." << endl;
			}
		}
		cout << "___________" << endl;
		cout << "Play Again?" << endl;
		cout << "___________" << endl;
		cin >> again;
	} while (again.compare("yes") == 0);
}
//user pulls sticks vs computer
void playGame2() {
	string again;
	do {
		int initialSticks;
		cout << "Number of sticks to begin game?" << endl;
		cin >> initialSticks;
		int roundCounter = 0;

		//stick picking
		while (initialSticks > 0) {
			if (initialSticks >= 1) {
				roundCounter++;
				int computerPicks;
				int remainSticks;

				if (initialSticks == 1) {
					initialSticks--;
					cout << "Round " << roundCounter << ", 1 sticks to start, computer took 1, so 0 sticks remain" << endl;
				}
				else {
					// randomly picks 1 or 2 sticks
					if ((rand() % 101) > 50) {
						computerPicks = 1;
					}
					else {
						computerPicks = 2;
					}
					int remainSticks = initialSticks - computerPicks;

					cout << "Round " << roundCounter << ", " << initialSticks << " sticks to start, computer took " << computerPicks << ", so " << remainSticks << " sticks remain" << endl;
					initialSticks -= computerPicks;
				}
				if (initialSticks == 0) {
					cout << "Computer wins!" << endl;
					break;
				}
				roundCounter++;
				int playerPick;
				if (initialSticks == 1) {
					string lastAnswer;
					cout << "Take last stick? yes or no?" << endl;
					cout << flush;
					cin >> lastAnswer;

					if (lastAnswer.compare("yes") == 0) {
						cout << "Round " << roundCounter << ", " << initialSticks << " sticks to start, human took 1, so 0 sticks remain" << endl;
						initialSticks--;
					}
					else {
						roundCounter++;
						cout << "Round " << roundCounter << " , the human chose not to win. " << initialSticks << " remain" << endl;
					}
				}
				else {
					do {
						cout << "Take 1 or 2 stick2?" << endl;
						cin >> playerPick;
					} while ((playerPick > 2) || (playerPick < 1));
					remainSticks = initialSticks - playerPick;
					cout << "Round " << roundCounter << ", " << initialSticks << " sticks to start, human took " << playerPick << ", so " << remainSticks << " sticks remain" << endl;
					initialSticks -= playerPick;
				}
				if (initialSticks == 0) {
					cout << "Human wins!" << endl;
					break;
				}
			}
		}
		cout << "___________" << endl;
		cout << "Play Again?" << endl;
		cout << "___________" << endl;
		cin >> again;
	} while (again.compare("yes") == 0);
}
// user rolls dice
void playGame3() {
	string again;
	do {
		int numberDice;
		int numberRolls;
		cout << "How many dice to roll" << endl;
		cin >> numberDice;
		cout << "How many times to roll dice" << endl;
		cin >> numberRolls;
		cout << "You have chosen to throw " << numberDice << " dice " << numberRolls << " times." << endl;

		int matchCounter = 0;
		int temp = 6 * numberDice + 1;

		vector<double> diceSums((temp), 0);
		//rolls dice d times
		for (int d = 1; d <= numberRolls; d++) {
			cout << "Roll " << d << ": ";
			vector<int> dieValues;
			int sum = 0;

			//dice rolls
			for (int i = 0; i < numberDice; i++) {
				int randomNumber = (rand() % 6) + 1;
				sum += randomNumber;
				dieValues.push_back(randomNumber);
				cout << randomNumber << " ";
			}
			diceSums[sum]++;
			//checks for yahtzee
			int matchDie = 0;
			for (int j = 0; j < numberDice; ++j) {
				if (dieValues[0] == dieValues[j]) {
					matchDie = matchDie + 1;
				}
			}
			if (matchDie == numberDice) {
				matchCounter++;
			}
			cout << " = " << sum << endl;
		}
		double matchPercent = (matchCounter *1.0 / numberRolls) * 100;
		double matchPercentRounded = round(matchPercent * 10.0) / 10.0;
		cout << "Of the " << numberRolls << " throws, " << matchCounter << " showed the same value on all of the dice which is " << matchPercentRounded << "% of all throws." << endl;

		for (int k = numberDice; k < temp; k++) {
			if (diceSums[k] != 0.0) {
				cout << "The sum " << k << " appeared " << diceSums[k] << " times" << endl;
			}
		}
		cout << "___________" << endl;
		cout << "Play Again?" << endl;
		cout << "___________" << endl;
		cin >> again;
	} while (again.compare("yes") == 0);
}

void playGame4() {
	string again;
	do {
		int rounds;
		cout << "How many rounds would you like to play?" << endl;
		cin >> rounds;

		int computerChoice = (rand() % 4);
		int userChoice;
		int compWins = 0;
		int userWins = 0;
		int ties = 0;

		for (int i = 0; i < rounds; i++) {
			int userChoice;
			do {
				cout << "Choose:" << endl;
				cout << "1. Rock" << endl;
				cout << "2. Paper" << endl;
				cout << "3. Scissors" << endl;
				cin >> userChoice;
			} while ((userChoice > 3) || (userChoice < 1));
			switch (userChoice) {
			case 1:
				cout << "-You chose Rock" << endl;
				break;
			case 2:
				cout << "-You chose Paper" << endl;
				break;
			case 3:
				cout << "-You chose Scissors" << endl;
				break;
			}

			switch (computerChoice) {
			case 1:
				cout << "-I chose Rock" << endl;
				break;
			case 2:
				cout << "-I chose Paper" << endl;
				break;
			case 3:
				cout << "-I chose Scissors" << endl;
				break;
			}
			//determining a winner
			if (computerChoice == userChoice)
			{
				cout << "* This is a tie" << endl;
				cout << endl;
				ties++;
			}
			else if ((computerChoice == 1 && userChoice == 3) || (userChoice == 2 && computerChoice == 1) || (userChoice == 3 && computerChoice == 2))
			{
				cout << "* I won" << endl;
				cout << endl;
				compWins++;
			}
			else {
				cout << "* You won" << endl;
				cout << endl;
				userWins++;
			}
		}
		if (compWins > userWins) {
			cout << "I won " << compWins << "/" << rounds << " rounds, and you won " << userWins << "/" << rounds << " rounds, and we tied " << ties << "/" << rounds << endl;
			cout << "That means I won! Good game" << endl;
		}
		else if (userWins > compWins) {
			cout << "I won " << compWins << "/" << rounds << " rounds, and you won " << userWins << "/" << rounds << " rounds, and we tied " << ties << "/" << rounds << endl;
			cout << "That means you won! Good game" << endl;
		}
		else {
			cout << "I won " << compWins << "/" << rounds << " rounds, and you won " << userWins << "/" << rounds << " rounds, and we tied " << ties << "/" << rounds << endl;
			cout << "That means we tied!  Good game" << endl;
		}
		cout << "___________" << endl;
		cout << "Play Again?" << endl;
		cout << "___________" << endl;
		cin >> again;
	} while (again.compare("yes") == 0);
}