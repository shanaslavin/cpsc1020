#include "Fruit.hpp"

double Fruit::totalFruitSales = 0.0;
int Fruit::fruitCount = 0;

//Constructor
//Regular constructor
Fruit::Fruit(){
  name = " ";
  weight = 0.0;
  pricePerlb = 0.0;
  pricePerEach = 0.0;
  howMany = 0;

  fruitCount++;
}
//Regular
Fruit::Fruit(string name, double weight, double pricePerlb,
              double pricePerEach, int howMany){
  this->name = name;
  this->weight = weight;
  this->pricePerlb = pricePerlb;
  this->pricePerEach = pricePerEach;
  this->howMany = howMany;

  fruitCount++;
}

//Destructor
Fruit::~Fruit(){
  fruitCount--;
}

//Other functions
void Fruit::calculateTax(ofstream& out){
  if(weight == 0){
    eachSale = howMany * pricePerEach;
    eachSalesTax= eachSale * TAX;
    out << "Sales Tax: " << eachSalesTax << endl;
  }
  else if(weight > 0){
    eachSale = weight * pricePerlb;
    eachSalesTax = eachSale * TAX;
    out << "Sales Tax: " << eachSalesTax << endl;
  }
  dailySalesTax += eachSalesTax;
}
void Fruit::calculateSale(ofstream& out){
  if(weight == 0){
    out << eachSale << endl;
    calculateTax(out);
  }
  else if(weight > 0){
    out << eachSale << endl;
    calculateTax(out);
  }
  double total = 0.0;
  total = eachSale + eachSalesTax;
  dailySales += total;
  totalFruitSales += total;
  out << "Total: " << total << endl;
}
void Fruit::printReceipt(ofstream& out){
  ProduceStand::printReceipt(out);
  out << "Sales:" << endl;
  out << name << setw(50);
  calculateSale(out);
}
void Fruit::printInfo(ofstream& out){
  out << setw(25) << "Number of fruit sales for the day: ";
  out << fruitCount << endl;
  out << setw(25) << "Total fruit sales of $" << totalFruitSales;
  out << " for the day" << endl;
}
