/*********************
Shana Slavin
sslavin
Lab 010
Lab Section 04
Nashrat Humaira
*********************/


#include "Card.hpp"

Card::Card() {
  this->value = 2;
  this->suit = Card::Suit::HEARTS;
}

Card::Card(int value, Suit suit) {
  this->value = value;
  this->suit = suit;
}

Card::Card(const Card& card) {
  this->value = card.value;
  this->suit = card.suit;
}

int Card::get_value() const { return this->value; }
void Card::set_value(int value) { this->value = value; }

Card::Suit Card::get_suit() const { return this->suit; }
void Card::set_suit(Card::Suit suit) { this->suit = suit; }

string Card::print() const {
  stringstream out;

  switch (this->value) {
    case 11: out << 'J'; break;
    case 12: out << 'Q'; break;
    case 13: out << 'K'; break;
    case 14: out << 'A'; break;
    default: out << this->value;
  }

  switch (this->suit) {
    case Card::Suit::HEARTS:    out << "\u2665"; break;
    case Card::Suit::DIAMONDS:  out << "\u2666"; break;
    case Card::Suit::SPADES:    out << "\u2660"; break;
    case Card::Suit::CLUBS:     out << "\u2663"; break;
  }

  return out.str();
}
