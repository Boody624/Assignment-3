#ifndef FoodProducts_H
#define FoodProdcuts_H

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
    FoodType type;
public:
   
    FoodProduct(double pricePerKilo = -1, string expiryDate = " ",
        double quantity = -1, FoodType type = FoodType::Other)
        : pricePerKilo(pricePerKilo), expiryDate(expiryDate),
        quantity(quantity), type(type) {}

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


};
#endif