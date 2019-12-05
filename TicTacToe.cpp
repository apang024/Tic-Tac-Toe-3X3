#include <vector>
#include <iostream>

using namespace std;

// Function Definitions
void drawBoard(const vector<char>& gameBoard);
void initVector(vector<char>& v);
int convertPosition(char boardPosition);
bool validPlacement(const vector<char>& gameBoard, int positionIndex);
int getPlay(const vector<char>& gameBoard);
bool gameWon(const vector<char>& gameBoard);
bool boardFull(const vector<char>& gameBoard);

// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
    // Variables that you may find useful to utilize
    vector<char> gameBoard(9);
    int curPlay;
    int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'

    initVector(gameBoard);
    drawBoard(gameBoard);

    while (!gameWon(gameBoard) && !boardFull(gameBoard)) {
        curPlay = getPlay(gameBoard);

        if (whosTurn == PLAYER1) { //if player 1 turn getPlay and set to 'X'
            gameBoard.at(curPlay) = 'X';
            whosTurn = PLAYER2;
            drawBoard(gameBoard);
        }

        else if (whosTurn == PLAYER2) { //if player 2 turn getplay and set to 'O'
            gameBoard.at(curPlay) = 'O';
            whosTurn = PLAYER1;
            drawBoard(gameBoard);
        }
    }
    
    if (boardFull(gameBoard) && !gameWon(gameBoard)) {
        cout << "No one wins" << endl;
    }
    else if (whosTurn == PLAYER1) {
        cout << "Player 2 Wins!!" << endl;
    }
    else if (whosTurn == PLAYER2) {
        cout << "Player 1 Wins!!" << endl;
    }

   return 0;
}

void drawBoard(const vector<char>& gameBoard) {
   for (int i = 0; i < 9; i += 3) {
      cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
         << gameBoard.at(i + 2) << "  " << endl;
      if (i < 6) {
         cout << "-----|-----|-----" << endl;
      }
   }
   cout << endl;
    
   return;
}

void initVector(vector<char>& v) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        char c = 'a';
        v.at(i) = c + i;
    }
   return;
}

int convertPosition(char boardPosition) {
   boardPosition -= 'a';
   return boardPosition;
}

bool validPlacement(const vector<char>& gameBoard, int positionIndex) {
   unsigned int i = positionIndex;
   if ((positionIndex < gameBoard.size()) && gameBoard.at(i) != 'X' && gameBoard.at(i) != 'O'){
       return true;
   }
   return false;
}

int getPlay(const vector<char>& gameBoard) {
    char boardPosition = ' ';

    while (!(validPlacement(gameBoard, convertPosition(boardPosition)))) {
        cout << "Please choose a position: " << endl;
        cin >> boardPosition;
    }
    return convertPosition(boardPosition);
}

bool gameWon(const vector<char>& gameBoard) {
    if (gameBoard.at(0) == gameBoard.at(1) && gameBoard.at(1) == gameBoard.at(2)) { //row 1
        return true;
    }
    else if (gameBoard.at(3) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(5)) { //row 2
        return true;
    }
    else if (gameBoard.at(6) == gameBoard.at(7) && gameBoard.at(7) == gameBoard.at(8)) { //row 3
        return true;
    }
    else if (gameBoard.at(0) == gameBoard.at(3) && gameBoard.at(3) == gameBoard.at(6)) { //column 1
        return true;
    }
    else if (gameBoard.at(1) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(5)) { //column 2
        return true;
    }
    else if (gameBoard.at(2) == gameBoard.at(5) && gameBoard.at(5) == gameBoard.at(8)) { //column 3
        return true;
    }
    else if (gameBoard.at(0) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(8)) { //diagonal L
        return true;
    }
    else if (gameBoard.at(2) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(6)) { //diagonal R
        return true;
    }
    return false;
}

bool boardFull(const vector<char>& gameBoard) {
    for (unsigned int i = 0; i < gameBoard.size(); ++i) {
        if (gameBoard.at(i) != 'X' && gameBoard.at(i) != 'O') {
            return false;
        }
    }
    return true;
}

