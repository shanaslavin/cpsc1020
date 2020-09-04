/*********************
Shana Slavin
sslavin
Lab 010
Lab Section 04
Nashrat Humaira
*********************/

#include "Deck.hpp"

//builds deck
void Deck::build_deck(){

  int i;

  for(i = 0; i < 52; i++){
    auto value = ((i % 13) + 2);
    auto suit = Card::Suit::HEARTS;
    switch (i%4) {
      case 0: suit = Card::Suit::HEARTS;
      break;
      case 1: suit = Card::Suit::SPADES;
      break;
      case 2: suit = Card::Suit::CLUBS;
      break;
      case 3: suit = Card::Suit::DIAMONDS;
      break;
    }
    this->cards.push_back(Card(value, suit));
  }
}

int Deck::num_cards(){
  return cards.size();
}

//constructor
Deck::Deck(){
  build_deck();
}

//deconstructor
Deck::~Deck(){

}

//shuffles deck
void Deck::shuffle(){
  random_shuffle(cards.begin(), cards.end());
}

void Deck::reset(){
  cards.clear();
}

Card Deck::draw(){
  Card drawCard;

  drawCard = cards.back();

  cards.pop_back();

  return drawCard;
}

//draws the last 5 cards
vector<Card> Deck::draw(int num){
  vector<Card> vectorofCards; //creates temporary deck

  int i;

  for(i = 0; i < num; i++){
    Card temp = draw();
    vectorofCards.push_back(temp);
  }
  return vectorofCards;
}

//prints deck
string Deck::print(){

  //creates a stringstream
  stringstream string;

  int i;

  for(i = 0; i < num_cards(); i++){
    string << cards.at(i).print() << " ";
  }

  return string.str();
}
