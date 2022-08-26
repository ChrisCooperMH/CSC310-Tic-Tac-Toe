#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
using namespace std;

class Board {
private:
const static int rows = 3;
const static int columns = 3;
string board[rows][columns];
bool isGameWon = false;
bool isDraw = false;
public:
Board() {
}

void checkForWin() {
  if ((board[0][0] == "x" && board[1][0] == "x" && board[2][0] == "x") || (board[0][0] == "o" && board[1][0] == "o" && board[2][0] == "o")) { // 1,2,3
    isGameWon = true;
    board[0][0] = toupper(board[0][0][0]);
    board[1][0] = toupper(board[1][0][0]);
    board[2][0] = toupper(board[2][0][0]);
  }
  else if ((board[0][0] == "x" && board[0][1] == "x" && board[0][2] == "x") || (board[0][0] == "o" && board[0][1] == "o" && board[0][2] == "o")) { // 1,4,7
    isGameWon = true;
    board[0][0] = toupper(board[0][0][0]);
    board[0][1] = toupper(board[0][1][0]);
    board[0][2] = toupper(board[0][2][0]);
  }
  else if ((board[0][0] == "x" && board[1][1] == "x" && board[2][2] == "x") || (board[0][0] == "o" && board[1][1] == "o" && board[2][2] == "o")) { // 1,5,9
    isGameWon = true;
    board[0][0] = toupper(board[0][0][0]);
    board[1][1] = toupper(board[1][1][0]);
    board[2][2] = toupper(board[2][2][0]);
  }
  else if ((board[1][0] == "x" && board[1][1] == "x" && board[1][2] == "x") || (board[1][0] == "o" && board[1][1] == "o" && board[1][2] == "o")) { // 2,5,8
    isGameWon = true;
    board[1][0] = toupper(board[1][0][0]);
    board[1][1] = toupper(board[1][1][0]);
    board[1][2] = toupper(board[1][2][0]);
  }
  else if ((board[2][0] == "x" && board[2][1] == "x" && board[2][2] == "x") || (board[2][0] == "o" && board[2][1] == "o" && board[2][2] == "o")) { // 3,6,9
    isGameWon = true;
    board[2][0] = toupper(board[2][0][0]);
    board[2][1] = toupper(board[2][1][0]);
    board[2][2] = toupper(board[2][2][0]);
  }
  else if ((board[0][1] == "x" && board[1][1] == "x" && board[2][1] == "x") || (board[0][1] == "o" && board[1][1] == "o" && board[2][1] == "o")) { // 4,5,6
    isGameWon = true;
    board[0][1] = toupper(board[0][1][0]);
    board[1][1] = toupper(board[1][1][0]);
    board[2][1] = toupper(board[2][1][0]);
  }
  else if ((board[0][2] == "x" && board[1][2] == "x" && board[2][2] == "x") || (board[0][2] == "o" && board[1][2] == "o" && board[2][2] == "o")) { // 7,8,9
    isGameWon = true;
    board[0][2] = toupper(board[0][2][0]);
    board[1][2] = toupper(board[1][2][0]);
    board[2][2] = toupper(board[2][2][0]);
  }
  else if ((board[2][0] == "x" && board[1][1] == "x" && board[0][2] == "x") || (board[2][0] == "o" && board[1][1] == "o" && board[0][2] == "o")) { // 3,5,7
    isGameWon = true;
    board[2][0] = toupper(board[2][0][0]);
    board[1][1] = toupper(board[1][1][0]);
    board[0][2] = toupper(board[0][2][0]);
  }
}
void drawGame() {
  isDraw = true;
}
bool gameWon() {
  return isGameWon;
}
bool isADraw() {
  return isDraw;
}
void restart() {
  isGameWon = false;
  isDraw = false;
}
void initialBoard() {
  int start = 1;
  cout << "Tic-Tac-Toe!" << endl;
  for (int i = 0; i < columns; i++) {
    cout << "+---+";
  } //graphics stuff
  cout << endl;
  for (int i = 0; i < rows; i++) { //drawing numbers
    for (int x = 0; x < columns; x++) {
      board[i][x] = to_string(start);
      cout << "| " << board[i][x] << " |";
      start += 3;
      if (start > 9) { //makes the board 147 258 369
        start -= 8;
      }
    }
    cout << endl;
    for (int i = 0; i < columns; i++) {
      cout << "+---+";
    } //graphics stuff
    cout << endl;
  }
  cout << endl << endl;
}
void drawBoard() {
  cout << "Tic-Tac-Toe!" << endl;
  for (int i = 0; i < columns; i++) {
    cout << "+---+";
  } //graphics stuff
  cout << endl;
  for (int i = 0; i < rows; i++) { //drawing numbers
    for (int x = 0; x < columns; x++) {
      cout << "| " << board[i][x] << " |";
    }
    cout << endl;
    for (int i = 0; i < columns; i++) {
      cout << "+---+";
    } //graphics stuff
    cout << endl;
  }
}
void updateBoardX(int n) {
  int first = rows-rows;
  if (n == 1) {
    board[0][0] = "x";
  }
  if (n == 2) {
    board[1][0] = "x";
  }
  if (n == 3) {
    board[2][0] = "x";
  }
  if (n == 4) {
    board[0][1] = "x";
  }
  if (n == 5) {
    board[1][1] = "x";
  }
  if (n == 6) {
    board[2][1] = "x";
  }
  if (n == 7) {
    board[0][2] = "x";
  }
  if (n == 8) {
    board[1][2] = "x";
  }
  if (n == 9) {
    board[2][2] = "x";
  }
  cout << endl << endl;
}
void updateBoardO(int n) {
  int first = rows-rows;
  if (n == 1) {
    board[0][0] = "o";
  }
  if (n == 2) {
    board[1][0] = "o";
  }
  if (n == 3) {
    board[2][0] = "o";
  }
  if (n == 4) {
    board[0][1] = "o";
  }
  if (n == 5) {
    board[1][1] = "o";
  }
  if (n == 6) {
    board[2][1] = "o";
  }
  if (n == 7) {
    board[0][2] = "o";
  }
  if (n == 8) {
    board[1][2] = "o";
  }
  if (n == 9) {
    board[2][2] = "o";
  }
  cout << endl << endl;
}
};
#endif