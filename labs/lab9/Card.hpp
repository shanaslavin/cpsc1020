/***************
Shana Slavin
sslavin
Lab 9
Lab Section: 004
Nashrat Humaira
***************/
#ifndef CARD_HPP
#define CARD_HPP


#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

class Card{

  public:
     enum class Suit {HEARTS = 0, DIAMONDS = 1, SPADES = 3, CLUBS = 4};

  void set_suit(Suit suitVar);
  void set_val(int);
  string print_deck();

  Suit get_suit();
  int get_val();

private:
  int val;
  Suit s;

};


void build_deck(Card[]);

#endif
