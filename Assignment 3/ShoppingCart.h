#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "ProductManger.h"
#include "Abstract_product.h" 

using namespace std;

template<typename T>
class ShoppingCart {
private:
    vector<T> products;
    vector<int> quantities;

    int findProductIndex(const T& product) const {
        for (int i = 0; i < products.size(); ++i) {
            if (products[i] == product) {
                return i;
            }
        }
        return -1; 
    }

public:
    ShoppingCart() {}

    vector<T> getProducts() const {
        return products;
    }
    
    void addProduct(const T& product, ProductManager<Product>& productManager) {
        vector <Product> prods = productManager.getProducts();
        bool productExists = false;
        string name2 = product.getName();
        for (const auto& p : productManager.getProducts()) {
            string name1 = p.getName();
            if (name2 == name1) {
                productExists = true;
                break;
            }
        }
        if (!productExists) {
            cout << "Product does not exist in the product manager, nothing has been added." << endl;
            return;
        }

        int index = findProductIndex(product);
        if (index != -1) {
            quantities[index]++;
        }
        else {
            products.push_back(product);
            quantities.push_back(1);
        }

        productManager.removeProduct(product);
    }
    

    void removeProduct(const T& product, ProductManager<T>& productManager) {
        int index = findProductIndex(product);
        if (index != -1) {
            quantities[index]--;
            if (quantities[index] == 0) {
                products.erase(products.begin() + index);
                quantities.erase(quantities.begin() + index);
                productManager.addProduct(product);
            }
        }
        else {
            cout << "Product not found in the shopping cart." << endl;
        }
    }

    void displayCart() const {
        if (products.empty()) {
            cout << "The shopping cart is empty." << endl;
            return;
        }
        cout << "Shopping Cart:" << endl;
        for (int i = 0; i < products.size(); ++i) {
            cout << products[i] << " - Quantity: " << quantities[i] << endl;
        }
    }
    
};

