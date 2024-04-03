#include "BooksProducts.h"
#include "Discount.h"
#include "FoodProducts.h"
#include "ElectronicsProduct.h"
#include "ProductManger.h"
#include "ShoppingCart.h"
#include "Order.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int Order::nextID = 0;
void displayAppliedDiscounts(const vector<Discount>& discounts);
int main() {

    ProductManager<Product> productManager;

    ElectronicsProduct laptop(ElectronicsType::Laptop, 1200, 5, 2, "HP", "Pavilion 15");
    productManager.addProduct(laptop);
    ElectronicsProduct phone(ElectronicsType::Phone, 500, 10, 1, "Apple", "iPhone 15");
    productManager.addProduct(phone);

    FoodProduct vegetable(FoodType::Vegetable, 2, "2024-04-01", 100, "Carrot");
    productManager.addProduct(vegetable);
    FoodProduct fruit(FoodType::Fruit, 3, "2024-04-03", 50, "Apple");
    productManager.addProduct(fruit);

    BookProduct novel("Pride and Prejudice", 30, "Jane Austen", "Romance", 20);
    productManager.addProduct(novel);
    BookProduct textbook("Mathematics", 50, "John Smith", "Education", 20);
    productManager.addProduct(textbook);

    productManager.sortProducts(SortBy::Price);
    productManager.sortProducts(SortBy::Quantity);
    productManager.sortProducts(SortBy::Name);

    // Remove a product and then add it back
    productManager - textbook;
    productManager + textbook;

    // Create shopping carts and add products
    ShoppingCart<BookProduct> cart1;
    cart1.addProduct(novel, productManager);
    ShoppingCart<BookProduct> cart2;
    cart2.addProduct(textbook, productManager);
    ShoppingCart<FoodProduct> cart3;
	cart3.addProduct(fruit, productManager);
    ShoppingCart<FoodProduct> cart4;
	cart4.addProduct(vegetable, productManager);
    ShoppingCart<ElectronicsProduct> cart5;
	cart5.addProduct(phone, productManager);
    ShoppingCart<ElectronicsProduct> cart6;
	cart6.addProduct(laptop, productManager);
    Order order1(cart5, cart3, cart2);
    Order order2(cart6, cart4, cart1);

    // Calculate and display warranty statistics
    cout << "Max warranty: " << productManager.getMaxWarrantyYears<ElectronicsProduct>() << " years" << endl;
    cout << "Min warranty: " << productManager.getMinWarrantyYears<ElectronicsProduct>() << " years" << endl;
    cout << "Average warranty: " << productManager.getAvgWarrantyYears<ElectronicsProduct>() << " years" << endl;

    Discount discount1(Type::BOGO, 0);
    order1.display();
    cout << "Order 1 details before applying discounts:" << endl;
    order1.addDiscount(discount1);
    order1.applyDiscounts(productManager);
    cout << "Order 2 details before applying discounts:" << endl;
    order2.display();


    Discount NileCart(Type::Coupon, 20);
    cout << "Order 1 details after applying discounts:" << endl;
    order1.display();
    order2.addDiscount(NileCart);
    order2.applyDiscounts(productManager);
    cout << "Order 2 details after applying discounts:" << endl;
	order2.display();

    return 0;
}

void displayAppliedDiscounts(const vector<Discount>& discounts) {
    cout << "Applied Discounts:" << endl;
    for (const Discount& discount : discounts) {
        string discountType;
        Type dis = discount.getType();
        switch (dis) {
        case Type::Percentage:
            discountType = "Percentage";
            break;
        case Type::FixedAmount:
            discountType = "Fixed Amount";
            break;
        case Type::BOGO:
            discountType = "BOGO";
            break;
        case Type::Coupon:
            discountType = "Coupon";
            break;
        }
        cout << "Discount Type: " << discountType << ", Value: " << discount.getValue() << endl;
    }
}
