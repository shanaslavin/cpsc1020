/*******************
Shana Slavin
sslavin
lab 9
Lab Section: 004
Nashrat Humaira
*******************/

#include "Card.hpp"

int main(){

  //declare variables
  int i;
  int draw = 0;
  int p1TimesWon = 0;
  int p2TimesWon = 0;

  Card deck1[52];
  Card deck2[52];

  //builds deck
  build_deck(deck1);
  build_deck(deck2);

  //shuffles deck
  random_shuffle(&deck1[0], &deck1[52]);
  random_shuffle(&deck2[0], &deck2[52]);

  //plays game and prints to screen
  for(int i = 0; i < 52; i++){
    cout << deck1[i].print_deck();
    cout << " ";
    cout << deck2[i].print_deck();

    if(deck1[i].get_val() < deck2[i].get_val()){
      cout << " P2 Wins" << endl;
      p2TimesWon++;
    }
    if(deck1[i].get_val() > deck2[i].get_val()){
      cout << " P1 Wins" << endl;
      p1TimesWon++;
    }
    if (deck1[i].get_val() == deck2[i].get_val()){
      cout << " Draw" << endl;
      draw++;
    }
  }

  cout << endl;
  cout << " P1 Total Wins = " << p1TimesWon << endl;
  cout << " P2 Total Wins = " << p2TimesWon << endl;
  cout << " Draws = " << draw << endl;


  return 0;
}
