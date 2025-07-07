#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main() {
  string userInput;
  int opponentMove;
  int winCount = 0;
  int lostCount = 0;
  bool validInput = true;
  bool play = true;
  cout << "'Rock Paper Scissors Lizard Spock' is an expanded version of the classic game, Rock Paper Scissors. It adds two more options: Lizard and Spock.\n\n";
  cout << "Scenarios:\n- Rock beats Scissors and Lizard\n- Paper beats Rock and Spock\n- Scissors beats Paper and Lizard\n- Lizard beats Paper and Spock\n- Spock beats Rock and Scissors\n\n";
  while (play) {
    bool valid = false;
    cout << "Your Move: ";
    cin >> userInput;
    std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c){ return std::tolower(c); }); // Convert userInput to lower case
    srand(time(NULL));
    opponentMove = rand() % 5;

    if (userInput.compare("rock") == 0) {
      if (opponentMove == 0) {
        cout << "Opponent's Move: Rock\n";
        cout << "Tie\n";
      } else if (opponentMove == 1) {
        cout << "Opponent's Move: Paper\n";
        cout << "Paper covers Rock\n";
        lostCount++;
      } else if (opponentMove == 2) {
        cout << "Opponent's Move: Scissors\n";
        cout << "Rock crushes Scissors\n";
        winCount++;
      } else if (opponentMove == 3) {
        cout << "Opponent's Move: Lizard\n";
        cout << "Rock crushes Lizard\n";
        winCount++;
      } else {
        cout << "Opponent's Move: Spock\n";
        cout << "Spock vaporizes Rock\n";
        lostCount++;
      }
    } else if (userInput.compare("paper") == 0) {
      if (opponentMove == 0) {
        cout << "Opponent's Move: Rock\n";
        cout << "Paper covers Rock\n";
        winCount++;
      } else if (opponentMove == 1) {
        cout << "Opponent's Move: Paper\n";
        cout << "Tie\n";
      } else if (opponentMove == 2) {
        cout << "Opponent's Move: Scissors\n";
        cout << "Scissors cuts Paper\n";
        lostCount++;
      } else if (opponentMove == 3) {
        cout << "Opponent's Move: Lizard\n";
        cout << "Lizard eats Paper\n";
        lostCount++;
      } else {
        cout << "Opponent's Move: Spock\n";
        cout << "Paper disaproves Spock\n";
        winCount++;
      }
    } else if (userInput.compare("scissors") == 0) {
      if (opponentMove == 0) {
        cout << "Opponent's Move: Rock\n";
        cout << "Rock crushes Scissors\n";
        lostCount++;
      } else if (opponentMove == 1) {
        cout << "Opponent's Move: Paper\n";
        cout << "Scissors cuts Paper\n";
        winCount++;
      } else if (opponentMove == 2) {
        cout << "Opponent's Move: Scissors\n";
        cout << "Tie\n";
      } else if (opponentMove == 3) {
        cout << "Opponent's Move: Lizard\n";
        cout << "Scissors decapitates Lizard\n";
        winCount++;
      } else {
        cout << "Opponent's Move: Spock\n";
        cout << "Spock smashes Scissors\n";
        lostCount++;
      }
    } else if (userInput.compare("lizard") == 0) {
      if (opponentMove == 0) {
        cout << "Opponent's Move: Rock\n";
        cout << "Rock crushes Lizard\n";
        lostCount++;
      } else if (opponentMove == 1) {
        cout << "Opponent's Move: Paper\n";
        cout << "Lizard eats Paper\n";
        winCount++;
      } else if (opponentMove == 2) {
        cout << "Opponent's Move: Scissors\n";
        cout << "Scissors decapitates Lizard\n";
        lostCount++;
      } else if (opponentMove == 3) {
        cout << "Opponent's Move: Lizard\n";
        cout << "Tie\n";
      } else {
        cout << "Opponent's Move: Spock\n";
        cout << "Lizard poisons Spock\n";
        winCount++;
      }
    } else if (userInput.compare("spock") == 0) {
      if (opponentMove == 0) {
        cout << "Opponent's Move: Rock\n";
        cout << "Spock vaporizes Rock\n";
        winCount++;
      } else if (opponentMove == 1) {
        cout << "Opponent's Move: Paper\n";
        cout << "Paper disaproves Spock\n";
        lostCount++;
      } else if (opponentMove == 2) {
        cout << "Opponent's Move: Scissors\n";
        cout << "Spock smashes Scissors\n";
        winCount++;
      } else if (opponentMove == 3) {
        cout << "Opponent's Move: Lizard\n";
        cout << "Lizard poisons Spock\n";
        lostCount++;
      } else {
        cout << "Opponent's Move: Spock\n";
        cout << "Tie\n";
      }
    } else {
        cout << "Invalid Input\n";
        validInput = false;
    }
    if (validInput) {
      while (!valid) {
        cout << "\nPlay Again? (y/n): ";
        cin >> userInput;
        std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c){ return std::tolower(c); }); // Convert userInput to lower case
        if (userInput.compare("n") == 0) {
          play = false;
          valid = true;
        } else if (userInput.compare("y") == 0) {
          valid = true;
        }
      }
      cout << "\n";
    } else {
      validInput = true;
    }
  }
  cout << "Wins: " << winCount << " | Losses: " << lostCount << "\n";
  cout << "Enter anything to quit: ";
  cin >> userInput;
  return 0;
}