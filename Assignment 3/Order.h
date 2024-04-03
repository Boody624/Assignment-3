#pragma once
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
    int orderID;
    

public:
    static int nextID;
    ShoppingCart<ElectronicsProduct> electronicsCart;
    ShoppingCart<FoodProduct> foodCart;
    ShoppingCart<BookProduct> bookCart;
    vector<Discount> discounts;
    Order() : orderID(nextID++) {}
    Order(const ShoppingCart<ElectronicsProduct>& electronicsCart, 
        const ShoppingCart<FoodProduct>& foodCart, 
        const ShoppingCart<BookProduct>& bookCart):electronicsCart(electronicsCart), 
        foodCart(foodCart), bookCart(bookCart), orderID(nextID++) {}
    void display() const {
        cout << "Order ID: " << orderID << endl;
        cout << "Shopping Cart:";
        electronicsCart.displayCart();
		foodCart.displayCart();
		bookCart.displayCart();
    }
    void addDiscount(const Discount& discount) {
        discounts.push_back(discount);
    }
    template <typename T>
    void applyDiscounts() {
        ShoppingCart<T> cart;
        vector <T> produc = cart.getProducts();
        cout<<"Enter your desired number of the product"<<endl;
		int n;
        cin >> n;

        discounts[n].applyDiscount<T>(produc[n], cart);
    }
    

    template <typename T>
    double computeTotalPrice(const vector<Discount>& discounts) const {
        double totalPrice = 0.0;
        vector<T> products = ShoppingCart.getProducts();
        for (int i = 0; i < products.size(); ++i) {
            double productPrice = products[i].getPrice() * products.size();

            for (const auto& discount : discounts) {
                if (discount.isApplicable(products[i])) {
                    productPrice = discount.applyDiscount(productPrice);
                }
            }

            totalPrice += productPrice;
        }

        return totalPrice;
    }



};


