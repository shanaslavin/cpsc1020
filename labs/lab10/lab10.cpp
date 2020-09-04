/****************
Shana Slavin
sslavin
Lab 010
Lab Section 004
Nashrat Humaira
****************/

#include "Deck.hpp"

int main(int argc, char const *argv[]) {
  Deck player;
  player.shuffle(); //shuffles deck

  //prints deck
  cout << "Deck has " << player.num_cards() << " cards" << endl;
  cout << player.print() << endl;

  cout << endl;
  cout << "Draw 5 cards" << endl;
  vector<Card> hand = player.draw(5);

  stringstream hand5;

  // Print the hand
  //interterator
  for(auto itr = hand.cbegin(); itr != hand.cend(); itr++){
    cout << (*itr).print() ;
  }

  //formatting purposes
  cout << endl;
  cout << endl;

  //prints out new deck
  cout << "Deck has " << player.num_cards() << " cards" << endl;
  cout << player.print() << endl;;

  return 0;
}
