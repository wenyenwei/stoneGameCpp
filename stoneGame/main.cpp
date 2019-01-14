#include <iostream>
#include <cmath>
using namespace std;

bool automodeInputValid(string );
int main() {

    cout << "Welcome to Stone Game." << endl;
    cout << "How many people are playing? \n";
    int playerSize;
    string playerList[playerSize];
    cin >> playerSize;

    int playerIndex = 0;
    while(playerIndex < playerSize) {
        cout << "Enter Player" << playerIndex + 1 <<" : " << endl;
        cin >> playerList[playerIndex];
        cout << "Hi, " << playerList[playerIndex] << endl;
        playerIndex++;
    }

    bool automodeCheckPassed;
    bool automode;
    string automodeInput;
    do {
        cout << "Auto Mode? y/n \n";
        cin >> automodeInput;
        automodeCheckPassed = automodeInputValid(automodeInput);
    } while(!automodeCheckPassed);

    automode = automodeInput == "y";


    int randPlayerToStart = rand() % playerSize;
    string currentPlayer = playerList[randPlayerToStart];

    cout << "Player " << currentPlayer << " goes first. \n";

    const int MAX_CHIPS = 20;
    int numOfChips = rand() % MAX_CHIPS;
    int chipsToDeduct;
    int maxChipsEntry = floor(MAX_CHIPS / 2);

    while(numOfChips > 0) {
        cout << "There are currently " << numOfChips << " chips in the pile. \n";
        cout << "Player " << currentPlayer << " enter chips to take: " << endl;




        if (automode) {
            chipsToDeduct = rand() % maxChipsEntry + 1;
        }else {
            cin >> chipsToDeduct;
        }


        numOfChips = numOfChips - chipsToDeduct;

        if (numOfChips < 1){
            cout << currentPlayer << " lose!";
            return 0;
        }

        currentPlayer = playerList[(randPlayerToStart + 1) % playerSize];
    }

}



bool automodeInputValid(string automodeInput) {
    if (automodeInput == "y" || automodeInput == "n") {
        return true;
    }else {
        return false;
    }
}
