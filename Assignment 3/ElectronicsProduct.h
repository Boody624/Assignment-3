#pragma once
#include <iostream>
#include <string>
#include "Abstract_product.h"
using namespace std;
enum class ElectronicsType { Phone, Laptop, Watch, Other };
class ElectronicsProduct: public Product{
private:
    double pricePerDevice;
    string name;
    int numDevicesAvailable;
    int warrantyYears;
    string factory;
    ElectronicsType type;
public:
    
    ElectronicsProduct(ElectronicsType type = ElectronicsType::Other, double pricePerDevice = -1, int numDevicesAvailable = -1,
        int warrantyYears = -1, string factory = " " , string name = " " )
        : type(type), pricePerDevice(pricePerDevice), numDevicesAvailable(numDevicesAvailable),
        warrantyYears(warrantyYears), factory(factory), name(name) {}

    double getPricePerDevice() const { 
        return pricePerDevice; 
    }
    int getQuantity() const {
        return numDevicesAvailable; 
    }
    int getWarrantyYears() const { 
        return warrantyYears; 
    }
    string getFactory() const { 
        return factory; 
    }
    ElectronicsType getType() const {
        return type; 
    }
    string getName() const {
        return name;
    }
    bool operator==(const Product& other) const {
        return this->getName() == other.getName();
    }

};

