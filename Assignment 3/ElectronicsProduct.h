#ifndef ElectronicsProduct_H
#define ElectronicsProduct_H
#include <iostream>
#include <string>
#include "Abstract_product.h"
using namespace std;
enum class ElectronicsType { Phone, Laptop, Watch, Other };
class ElectronicsProduct: public Product{
private:
    double pricePerDevice;
    int numDevicesAvailable;
    int warrantyMonths;
    string factory;
    ElectronicsType type;
public:
    
    ElectronicsProduct(ElectronicsType type = ElectronicsType::Other, double pricePerDevice = -1, int numDevicesAvailable = -1,
        int warrantyMonths = -1, string factory = " " )
        : type(type), pricePerDevice(pricePerDevice), numDevicesAvailable(numDevicesAvailable),
        warrantyMonths(warrantyMonths), factory(factory) {}

    double getPricePerDevice() const { 
        return pricePerDevice; 
    }
    int getNumDevicesAvailable() const { 
        return numDevicesAvailable; 
    }
    int getWarrantyMonths() const { 
        return warrantyMonths; 
    }
    string getFactory() const { 
        return factory; 
    }
    ElectronicsType getType() const {
        return type; 
    }


};



















#endif 
