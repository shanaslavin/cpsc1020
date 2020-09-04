#include "functions.hpp"

void readWriteData(ifstream& input, ofstream& receipt, ofstream& email){
  //Variables
  string produce = " ";
  string produceName = " ";
  double weight = 0.0;
  double pricePerW = 0.0;
  double pricePerE = 0.0;
  int numOfProduce = 0;

  //Reading information
  input >> produce;
  input >> produceName;
  input >> weight;
  input >> pricePerW;
  input >> pricePerE;
  input >> numOfProduce;

  //Construct ProduceStand object
  ProduceStand stand;
  stand.set_standName("The World's Best Produce Stand Ever!");


  char mailList = ' ';
  string customerName = " ";
  string customerEmail = " ";
  int strNum = 0;
  string strName = " ";
  string city = " ";

}
