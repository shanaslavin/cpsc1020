/****************
Shana Slavin
sslavin
Lab 5
Lab Section: 004
Nashrat Humaira
****************/

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]){
  //initializing variables
  int id = 0;
  int prices = 0;
  long double avgPrice = 0.0L;
  long double priceOfBook = 0.0L;
  long double totalVal = 0.0L;
  string bookTitle;

  //opening output file
  ifstream(inputPtr);
  ofstream(outputPtr);
  inputPtr.open(argv[1]);
  outputPtr.open(argv[2]);

  if (inputPtr.is_open() && outputPtr.is_open()){
    outputPtr << setw(4) << "ID  ";
    outputPtr << setw(25) << "Title";
    outputPtr << setw(10) << "Price" << endl;
    
    while(inputPtr >> id){
      inputPtr.imbue(std::locale("en_US.UTF-8"));
      
      while(inputPtr >> get_money(priceOfBook)){
        //finds average
        totalVal += priceOfBook;
        prices++;
        avgPrice = totalVal / prices;
      }
      //resets values
      prices = 0;
      totalVal = 0.0L;
     
      inputPtr.clear();
      getline(inputPtr, bookTitle);
      
      if(bookTitle.length() > 25){
        bookTitle.erase(25, std::string::npos);
        bookTitle.replace(22, std::string::npos, 3, '.');
      }
      
      outputPtr << setw(4) << id << "  ";
      outputPtr << setw(25) << bookTitle;
      outputPtr.imbue(std::locale("en_US.UTF-8"));
      outputPtr << setw(10) << put_money(avgPrice) << endl;

    }

  }   

  else{
    cout << "File could not be opened correctly." << endl;
  }

  inputPtr.close();
  outputPtr.close();

  return 0;

}
