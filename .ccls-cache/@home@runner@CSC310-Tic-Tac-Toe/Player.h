#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
int choice;
int wins;
int losses;
int draws;
string name;
string fname;
public:
Player() {
  wins = 0;
  losses = 0;
  draws = 0;
}

//accessors
string getName() const{
  return name;
}
string getFName() const {
  return fname;
}
int getWins() const {
  return wins;
}
int getLosses() const {
  return losses;
}
int getDraws() const {
  return draws;
}
//modifiers
void setName(string n) {
  name = n;
}
void setFName(string f) {
  fname = f;
}
void setWins(int w) {
  wins = w;
}
void setLosses(int l) {
  losses = l;
}
void setDraws(int d) {
  draws = d;
}

};

#endif