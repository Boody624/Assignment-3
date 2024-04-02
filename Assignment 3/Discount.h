#ifndef Discount_H
#define Discount_H

#include <iostream>
#include <string>
#include <vector>
#include "Abstract_product.h"
#include "ShoppingCart.h"
using namespace std;
enum class Type { Percentage, FixedAmount, BOGO, Coupon };

class Discount {
private:
    Type type;
    double value;
public:

    Discount() : type(Type::Percentage), value(0.0) {}
    Discount(Type type, double value) : type(type), value(value) {}

    Type getType() const{
        return type;
    }
    double getValue() const {
        return value;
    }
    double applyDiscount(Product* product) const {
        double price = product->getPrice();
        switch (type) {
        case Type::Percentage:
            product->setPrice(price * (1.0 - value / 100.0));
            return (price * (1.0 - value / 100.0));
            break;
        case Type::FixedAmount:
            product->setPrice(price -value);
            return price- value;
            break;

        case Type::BOGO:

            return price;
            break;

        case Type::Coupon:
            product->setPrice(price * 0.75);
            return (price * 0.75);
            break;

        }
    }
    template<typename T>
    double operator-(Product* product) const {
        return applyDiscount(product);
    }
    template<typename T>
    double combineDiscounts(Product* product, const vector<Discount>& discounts) {
        double discountedPrice = product->getPrice();
        for (const Discount& discount : discounts) {
            discountedPrice = discount - product;
        }
        return discountedPrice;
    }


};











#endif 
