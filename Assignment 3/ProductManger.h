#ifndef ProductManager_H
#define ProductManager_H
#include <iostream>
#include <string>
#include <vector>
#include "ElectronicsProduct.h"

using namespace std;

enum class SortBy { Price, Quantity, Name };

template<typename T>
class ProductManager {
private:
vector<T> products;

void sortProductsByAttribute(vector<T>& sortedProducts, SortBy sortBy) const {
    for (size_t i = 0; i < sortedProducts.size() - 1; ++i) {
        for (size_t j = 0; j < sortedProducts.size() - i - 1; ++j) {
            switch (sortBy) {
            case SortBy::Price:
            if (sortedProducts[j].getPrice() > sortedProducts[j + 1].getPrice()) {
                swap(sortedProducts[j], sortedProducts[j + 1]);
            }
                    break;
                case SortBy::Quantity:
                    if (sortedProducts[j].getQuantity() > sortedProducts[j + 1].getQuantity()) {
                        swap(sortedProducts[j], sortedProducts[j + 1]);
                    }
                    break;
                case SortBy::Name:
                    if (sortedProducts[j].getName() > sortedProducts[j + 1].getName()) {
                        swap(sortedProducts[j], sortedProducts[j + 1]);
                    }
                    break;
                }
            }
        }
    }
public:
    ProductManager() {}
    vector<T> getProducts() {
        return products;

    }
    void addProduct(const T& product) {
        products.push_back(product);
    }

    void removeProduct(const T& product) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (*it == product) {
                products.erase(it);
                return;
            }
        }
    }

    void displayProducts() const {
        for (const auto& product : products) {
            cout << product << endl;
        }
    }

    vector<T> sortProducts(const string& sortBy) const {
        vector<T> sortedProducts = products;
        if (sortBy == "Price") {
            sortProductsByAttribute(sortedProducts, SortBy::Price);
        }
        else if (sortBy == "Quantity") {
            sortProductsByAttribute(sortedProducts, SortBy::Quantity);
        }
        else if (sortBy == "Name") {
            sortProductsByAttribute(sortedProducts, SortBy::Name);
        }
        else {
            cout<< "Invalid sort option";
            return products;
        }
        return sortedProducts;
    }
    
    

};

template<typename T>
ostream& operator<<(ostream& os, const ProductManager<T>& productManager) {
    for (int i = 0; i < productManager.products.size(); ++i) {
        os << productManager.products[i] << endl;
    }
    return os;
}


template<typename T>
ProductManager<T> operator+(const ProductManager<T>& lhs, const T& rhs) {
    ProductManager<T> result = lhs;
    result.addProduct(rhs);
    return result;
}

template<typename T>
ProductManager<T> operator-(const ProductManager<T>& lhs, const T& rhs) {
    ProductManager<T> result = lhs;
    result.removeProduct(rhs);
    return result;
}




#endif 
