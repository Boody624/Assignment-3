#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Abstract_product.h"
#include "ShoppingCart.h"
#include "productManger.h"
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
    template<typename T>
    double applyDiscount(ProductManager<T> &productManager, ShoppingCart<T>& cart) const {
        cout<<"What is the index of your desired to discount product"<<endl;
		int index;
        cin >> index;
        double price = productManager.products[index].getPrice();
        switch (type) {
        case Type::Percentage:
            productManager.products[index].setPrice(price * (1.0 - value / 100.0));
            return (price * (1.0 - value / 100.0));
            break;
        case Type::FixedAmount:
            productManager.products[index].setPrice(price -value);
            return (price- value);
            break;

        case Type::BOGO:
            cart.addProduct(productManager.products[index], productManager);
            return price;
            break;

        case Type::Coupon:
            productManager.products[index].setPrice(price * 0.75);
            return (price * 0.75);
            break;

        }
        return price;
    }
    template<typename T>
    double operator-(Product* product) const {
        return this->applyDiscount(product);
    }

    template<typename T>
    double combineDiscounts(Product* product, vector<Discount>& discounts) {
        double discountedPrice = product->getPrice();
        for (int i = 0; i < discounts.size(); ++i) {
            discountedPrice = product - this;
        }
        return discountedPrice;
    }


};




