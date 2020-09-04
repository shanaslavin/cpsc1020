#ifndef FRUIT_H
#define FRUIT_H

#include <string>
#include "ProduceStand.hpp"
#include <fstream>
#include <iostream>
using namespace std;

class Fruit : public ProduceStand
{
  private:

    static double totalFruitSales;
    static int fruitCount;

  public:
    Fruit();
    Fruit(string, double, double, double, int);
    virtual ~Fruit();

    virtual void calculateTax(ofstream&);
    virtual void calculateSale(ofstream&);
    virtual void printReceipt(ofstream&);
    void printInfo(ofstream&);
};

#endif
