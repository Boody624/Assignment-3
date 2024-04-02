#ifndef Order_H
#define	Order_H
#include "ProductManger.h"
#include "ShoppingCart.h"
#include "FoodProducts.h"
#include "ElectronicsProduct.h"
#include "BooksProducts.h"
#include "Discount.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Order {
private:
    static int nextID; 
    int orderID;
    ShoppingCart<ElectronicsProduct> electronicsCart;
    ShoppingCart<FoodProduct> foodCart;
    ShoppingCart<BookProduct> bookCart;
    vector<Discount> discounts;

public:
    Order() : orderID(nextID++) {}

    void addDiscount(const Discount& discount) {
        discounts.push_back(discount);
    }
    template <typename T>
    double computeDiscountedPrice(const vector<Discount>& discounts) const {
        double totalPrice = 0.0;
        vector<T> products = ShoppingCart.getProducts();
        for (int i = 0; i < products.size(); ++i) {
            double productPrice = products[i].getPrice() * quantities[i];

            for (const auto& discount : discounts) {
                if (discount.isApplicable(products[i])) {
                    productPrice = discount.applyDiscount(productPrice);
                }
            }

            totalPrice += productPrice;
        }

        return totalPrice;
    }

    double computeTotalPrice() const {
        double totalPrice = 0.0;

        // Apply discounts on electronics products
        // Iterate through the electronics cart and apply discounts
        // Update totalPrice accordingly

        // Apply discounts on food products
        // Iterate through the food cart and apply discounts
        // Update totalPrice accordingly

        // Apply discounts on book products
        // Iterate through the book cart and apply discounts
        // Update totalPrice accordingly

        return totalPrice;
    }
};

int Order::nextID = 1;

#endif