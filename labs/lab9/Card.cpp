/*************
Shana Slavin
sslavin
Lab 9
Lab Section: 004
Nashrat Humaira
*************/

#include "Card.hpp"

//setters
void Card::set_suit(Card::Suit suit){
  this->s = suit;
}

void Card::set_val(int value){
  this->val = value;
}

//getters
Card::Suit Card::get_suit(){
  return this->s;
}

int Card::get_val(){
  return this->val;
}

//builds deck
void build_deck(Card deck[]){
  for(int i = 0; i < 52; i++){
    deck[i].set_suit(static_cast<Card::Suit>(i%4));
    deck[i].set_val((i%13)+2);
  }
}

//prints faces
string Card::print_deck(){

  stringstream out;

  switch(Card::get_val()){
    case 11: out << 'J';
    break;
    case 12: out << 'Q';
    break;
    case 13: out << 'K';
    break;
    case 14: out << 'A';
    break;
    default: out << Card::get_val();
  }

  switch(Card::get_suit()){
    case Card::Suit::HEARTS: out << "\u2665";
    break;
    case Card::Suit::DIAMONDS: out << "\u2666";
    break;
    case Card::Suit::SPADES: out << "\u2660";
    break;
    case Card::Suit::CLUBS: out << "\u2663";
    break;
  }

  return out.str();
}
