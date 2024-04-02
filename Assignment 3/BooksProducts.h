#ifndef BooksProducts_H
#define BooksProducts_H
#include <iostream>
#include <string>
#include "Abstract_product.h"

using namespace std;

class BookProduct:public Product {
private:
    string title;
    double price;
    string author;
    string genre;
    int quantityAvailable;
public:
    BookProduct(const string& title, double price, const string& author,
        const string& genre, int quantityAvailable)
        : title(title), price(price), author(author),
        genre(genre), quantityAvailable(quantityAvailable) {}

    string getTitle() const { 
        return title; 
    }
    double getPrice() const { 
        return price; 
    }
    string getAuthor() const { 
        return author; 
    }
    string getGenre() const { 
        return genre; 
    }
    int getQuantityAvailable() const { 
        return quantityAvailable; 
    }
    void setPrice(int x) {
        price = x;
    }
    void setQuantityAvailable(int x) {
        quantityAvailable = x;
    }

};



#endif