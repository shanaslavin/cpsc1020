#include <iostream>
#include <algorithm>
#include "stdlib.h"

#include "Card.hpp"
#include "Deck.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  Deck player;
  player.shuffle();

  cout << player.print();

  cout << "Draw 5 cards" << endl;
  vector<Card> hand = player.draw(5);

  // Print the hand

  cout << player.print();

  return 0;
}
