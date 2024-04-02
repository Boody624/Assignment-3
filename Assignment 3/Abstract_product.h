#ifndef Abstract_product_H
#define Abstract_product_H
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
public:
	Product(string n = "", string i = "", float p = -1, string c = "", string b = "")
		:name(n), ID(i), price(p), category(c),brand(b){}
	string getName() const{
		return name;
	}
	string getID()const {
		return ID;
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

};

#endif 

