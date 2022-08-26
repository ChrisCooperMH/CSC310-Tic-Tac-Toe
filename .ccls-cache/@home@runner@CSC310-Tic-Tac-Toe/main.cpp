#include <iostream>
#include "Board.h"
#include "Player.h"
#include <string>
using namespace std;
void showWLD(Player,Player);

int main() {
  Board b;
  Player p1;
  Player p2;
  string name;
  string fname;
  string fname2;
  string activePlayer;
  string winner;
  int turns = 0;
  bool play = true;
  cout << "Player 1, enter your name." << endl;
  getline(cin, name);
  p1.setName(name);
  int space = name.find(" ", 0);
  for (int i = 0; i < space; i++) {
    fname += name[i];
  }
  if (space == -1) {
    fname = name;
  }
  p1.setFName(fname);
  cout << "Player 2, enter your name." << endl;
  getline(cin, name);
  p2.setName(name);
  space = name.find(" ", 0);
  for (int i = 0; i < space; i++) {
    fname2 += name[i];
  }
  if (space == -1) {
    fname2 = name;
  }
  p2.setFName(fname2);
  cout << endl;
  do {
    if (p1.getFName() > p2.getFName() || winner == p2.getFName()) {
      activePlayer = p2.getFName();
      cout << "Current turn: " + to_string(turns+1) << endl;
      cout << activePlayer + ", you will go first." << endl << endl;
      b.initialBoard();
      while (!b.gameWon() && !b.isADraw()) {
        cout << activePlayer + ", please select your choice." << endl << endl;
        int choice;
        cin >> choice;
        if (activePlayer == p2.getFName()) {
          b.updateBoardX(choice);
          turns++;
        }
        else if (activePlayer == p1.getFName()) {
          b.updateBoardO(choice);
          turns++;
        }
        b.checkForWin();
        if (turns > 8) {
          b.drawGame();
        }
        b.drawBoard();
        if (activePlayer == p2.getFName()) {
          activePlayer = p1.getFName();
        }
        else if (activePlayer == p1.getFName()) {
          activePlayer = p2.getFName();
        }
      }
    }
    else if (p1.getFName() < p2.getFName() || winner == p1.getFName()) {
      activePlayer = p1.getFName();
      cout << activePlayer + ", you will go first." << endl << endl;
      b.initialBoard();
      while (!b.gameWon() && !b.isADraw()) {
        cout << "Current turn: " + to_string(turns+1) << endl;
        cout << activePlayer + ", please select your choice." << endl << endl;
        int choice;
        cin >> choice;
        if (activePlayer == p1.getFName()) {
          b.updateBoardX(choice);
          turns++;
          
        }
        else if (activePlayer == p2.getFName()) {
          b.updateBoardO(choice);
          turns++;
        }
        b.checkForWin();
        if (turns > 8) {
          b.drawGame();
        }
        b.drawBoard();
        if (activePlayer == p1.getFName()) {
          activePlayer = p2.getFName();
        }
        else if (activePlayer == p2.getFName()) {
          activePlayer = p1.getFName();
        }
      }
    }
    cout << endl;
    if (b.gameWon()) {
      if (activePlayer == p1.getFName()) {
        activePlayer = p2.getFName();
      }
      else if (activePlayer == p2.getFName()) {
        activePlayer = p1.getFName();
      }
      cout << "Congratulations, " + activePlayer + ". You won!" << endl;
      winner = activePlayer;
      if (activePlayer == p1.getFName()) {
        p1.setWins(p1.getWins()+1);
        p2.setLosses(p2.getLosses()+1);
        showWLD(p1,p2);
      }
      else if (activePlayer == p2.getFName()) {
        p2.setWins(p2.getWins()+1);
        p1.setLosses(p1.getLosses()+1);
        showWLD(p1,p2);
      }
    }
    else if (b.isADraw()) {
      cout << "The game is a draw! No one wins!" << endl;
      p1.setDraws(p1.getDraws()+1);
      p2.setDraws(p2.getDraws()+1);
      showWLD(p1,p2);
    }
    cout << endl;
    string cont;
    cout << "Do you want to continue? (y/n) Note: anything other inputs will count as a no." << endl;
    cin >> cont;
    if (cont == "y") {
      play = true;
      b.restart();
      turns = 0;
    }
    else {
      cout << "Thanks for playing!" << endl;
      play = false;
      turns = 0;
    }
  } while (play);
}

void showWLD(Player p1, Player p2) {
  cout << "Games Played: " + to_string(p1.getWins()+p2.getWins()+p1.getDraws()) << endl << endl;
  cout << "Name: " + p1.getName() << endl;
  cout << "Wins: " + to_string(p1.getWins()) << endl;
  cout << "Losses: " + to_string(p1.getLosses()) << endl;
  cout << "Draws: " + to_string(p1.getDraws()) << endl;
  cout << endl;
  cout << "Name: " + p2.getName() << endl;
  cout << "Wins: " + to_string(p2.getWins()) << endl;
  cout << "Losses: " + to_string(p2.getLosses()) << endl;
  cout << "Draws: " + to_string(p2.getDraws()) << endl;
}