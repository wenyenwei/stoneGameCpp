#include <iostream>
using namespace std;
int main() {
    cout << "Welcome to Stone Game." << endl;
    cout << "How many people are playing? \n";
    int playerSize;
    cin >> playerSize;
    string playerList[playerSize];
    int playerIndex = 0;
    while(playerIndex < playerSize) {
        cout << "Enter Player" << playerIndex + 1 <<" : " << endl;
        cin >> playerList[playerIndex];
        cout << "Hi, " << playerList[playerIndex] << endl;
        playerIndex++;
    }


    int randPlayerToStart = rand() % playerSize;
    string currentPlayer = playerList[randPlayerToStart];

    cout << "Player " << currentPlayer << " goes first. \n";

    const int MAX_CHIPS = 20;
    int numOfChips = rand() % MAX_CHIPS;
    int chipsToDeduct;
    while(numOfChips > 0) {
        cout << "There are currently " << numOfChips << " chips in the pile. \n";
        cout << "Player " << currentPlayer << " enter chips to take: " << endl;

        cin >> chipsToDeduct;

        numOfChips = numOfChips - chipsToDeduct;

        if (numOfChips < 1){
            cout << currentPlayer << " lose!";
            return 0;
        }

        currentPlayer = playerList[randPlayerToStart++ % playerSize];
    }

}