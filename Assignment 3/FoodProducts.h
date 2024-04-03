#pragma once

#include <iostream>
#include <string>
#include "Abstract_product.h"
using namespace std;
enum class FoodType {Vegetable, Fruit, Other };

class FoodProduct:public Product {
private:
    double pricePerKilo;
    string expiryDate;
    double quantity;
    string name;
    FoodType type;
public:
   
    FoodProduct(FoodType type = FoodType::Other, double pricePerKilo = -1, string expiryDate = " ",
        double quantity = -1, string n = "")
        : pricePerKilo(pricePerKilo), expiryDate(expiryDate),
        quantity(quantity), type(type), name(n) {}

    string getName() const {
        return name; 
    }
    double getPricePerKilo() const { 
        return pricePerKilo; 
    }
    string getExpiryDate() const { 
        return expiryDate; 
    }
    double getQuantity() const { 
        return quantity; 
    }
    FoodType getType() const { 
        return type; 
    }
    bool operator==(const Product& other) const {
        return this->getName() == other.getName();
    }

};
