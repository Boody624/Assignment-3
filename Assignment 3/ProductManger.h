#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ElectronicsProduct.h"

using namespace std;

enum class SortBy { Price, Quantity, Name };

template<typename T>
class ProductManager {
private:

    

public:
    vector<T> products;

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
    void operator- (Product x)
    {
        removeProduct(x);
    }
    void operator+ (Product x)
    {
        addProduct(x);
    }
    void sortProducts(SortBy sortBy) {
        for (int i = 0; i < products.size() - 1; ++i) {
            for (int j = 0; j < products.size() - i - 1; ++j) {
                
                if (sortBy == SortBy::Price) {
                    if (products[j].getPrice() > products[j + 1].getPrice()) {
                        swap(products[j], products[j + 1]);
                    }
                }
                else if (sortBy == SortBy::Quantity) {                
                    if (products[j].getQuantity() > products[j + 1].getQuantity()) {
                        swap(products[j], products[j + 1]);
                    }
                }
                else if (sortBy == SortBy::Name) {
                    if (products[j].getName() > products[j + 1].getName()) {
                        swap(products[j], products[j + 1]);
                    }
                }
                }
            }
        }
    

    template<typename U = T>
    typename enable_if<is_same<U, ElectronicsProduct>::value, double>::type
        getMaxWarrantyYears() const {
        double maxWarranty = 0.0;
        for (const auto& product : products) {
            const ElectronicsProduct& elecProduct = static_cast<const ElectronicsProduct&>(product);
            double warranty = elecProduct.getWarrantyYears();
            if (warranty > maxWarranty) {
                maxWarranty = warranty;
            }
        }
        return maxWarranty;
    }

    template<typename U = T>
    typename enable_if<is_same<U, ElectronicsProduct>::value, double>::type
        getMinWarrantyYears() const {
        double minWarranty = numeric_limits<double>::max();
        for (const auto& product : products) {
            const ElectronicsProduct& elecProduct = static_cast<const ElectronicsProduct&>(product);
            double warranty = elecProduct.getWarrantyYears();
            if (warranty < minWarranty) {
                minWarranty = warranty;
            }
        }
        return minWarranty;
    }

    template<typename U = T>
    typename enable_if<is_same<U, ElectronicsProduct>::value, double>::type
        getAvgWarrantyYears() const {
        double totalWarranty = 0.0;
        int electronicsCount = 0;
        for (const auto& product : products) {
            const ElectronicsProduct& elecProduct = static_cast<const ElectronicsProduct&>(product);
            totalWarranty += elecProduct.getWarrantyYears();
            electronicsCount++;
        }
        if (electronicsCount == 0) {
            return 0.0; 
        }
        return totalWarranty / electronicsCount;
    }
    

};

template<typename T>
ostream& operator<<(ostream& os, const ProductManager<T>& productManager) {
    for (int i = 0; i < productManager.products.size(); ++i) {
        os << productManager.products[i].getName() << endl;
    }
    return os;
}









