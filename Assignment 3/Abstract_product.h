#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
	string name;
	string ID;
	float price;
	string category;
	string brand;
	int quantity;
public:
	Product(string n = "", string i = "", float p = -1, string c = "", string b = "", int quantity = 0)
		:name(n), ID(i), price(p), category(c),brand(b), quantity(quantity){}
	string getName() const{
		return name;
	}
	string getID()const {
		return ID;
	}
	int getQuantity() const {
		return quantity;
	}
	float getPrice() const {
		return price;
	}
	string getCategory() const {
		return category;
	}
	string getBrand() const {
		return brand;
	}
	void setName(string s) {
		name = s;
	}
	void setID(string s) {
		ID = s;
	}
	void setPrice(float s) {
		price = s;
	}
	void setCategory(string s) {
		category = s;
	}
	void setBrand(string s) {
		brand = s;
	}
	bool operator==(const Product& other) const {
		return this->getName() == other.getName();
	}
	friend ostream& operator<<(ostream& os, const Product& p)
	{
		os << " Name: " << p.name << " ,Price per unit: " << p.price << " ,Quantity: " << p.quantity;
		return os;
	}
};


