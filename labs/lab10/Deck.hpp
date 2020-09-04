/*******************
Shana Slavin
sslavin
Lab 010
Lab Section: 004
Nashrat Humaira
*******************/

#ifndef DECK_H
#define DECK_H

#include "Card.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class Deck{
  private:
    vector<Card> cards;
    void build_deck();

  public:
    Deck();
    ~Deck();

    int num_cards();

    void shuffle();
    void reset();

    Card draw();

    vector<Card> draw(int num);

    string print();
};


#endif
