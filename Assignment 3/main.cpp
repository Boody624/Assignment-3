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

void displayAppliedDiscounts(const vector<Discount>& discounts);
int main() {

    
    // Create ProductManager instance
    ProductManager<ElectronicsProduct> electronicsManager;
    ProductManager<FoodProduct> foodManager;
    ProductManager<BookProduct> bookManager;
    ElectronicsType type = ElectronicsType::Phone;
    // Create and add different products to ProductManager instances
    ElectronicsProduct phone(ElectronicsType::Phone, 500, 10, 1, "Apple");
    electronicsManager.addProduct(phone);
    ElectronicsProduct laptop(ElectronicsType::Laptop, 1200, 5, 2, "HP");
    electronicsManager.addProduct(laptop);

    FoodProduct vegetable("Vegetable", 2, 100, "2024-04-01", "Carrot", "Vegetable");
    foodManager.addProduct(vegetable);
    FoodProduct fruit("Fruit", 3, 50, "2024-04-03", "Apple", "Fruit");
    foodManager.addProduct(fruit);

    BookProduct novel("Novel", 20, 30, "Jane Austen", "Romance", "Pride and Prejudice");
    bookManager.addProduct(novel);
    BookProduct textbook("Textbook", 50, 20, "John Smith", "Education", "Mathematics");
    bookManager.addProduct(textbook);

    // Display sorted products
    cout << "Sorted by price:" << endl;
    cout << electronicsManager.sortProducts("Price") << endl;

    cout << "Sorted by quantity:" << endl;
    cout << foodManager.sortProducts("Quantity") << endl;

    cout << "Sorted lexicographically by name:" << endl;
    cout << bookManager.sortProducts("Name") << endl;

    // Test overloaded operators
    ProductManager<ElectronicsProduct> combinedElectronics = electronicsManager + laptop;
    cout << "Combined electronics products:" << endl;
    cout << combinedElectronics << endl;

    ProductManager<BookProduct> updatedBooks = bookManager - textbook;
    cout << "Updated book products:" << endl;
    cout << updatedBooks << endl;

    // Calculate and display warranty statistics
    /*cout << "max warranty: " << electronicsmanager.getmaxwarranty() << " years" << endl;
    cout << "min warranty: " << electronicsmanager.getminwarranty() << " years" << endl;
    cout << "average warranty: " << electronicsmanager.getaveragewarranty() << " years" << endl;*/

    // Create orders
    Order order1;
    order1.addProduct(phone);
    order1.addProduct(vegetable);

    Order order2;
    order2.addProduct(laptop);
    order2.addProduct(fruit);

    // Display order details before applying discounts
    cout << "Order 1 details before applying discounts:" << endl;
    // Display order details for order1

    cout << "Order 2 details before applying discounts:" << endl;
    // Display order details for order2

    // Apply BOGO discount
    // Apply NileCart coupon and percentage discount

    // Display order details after applying discounts
    cout << "Order 1 details after applying discounts:" << endl;
    // Display order details for order1

    cout << "Order 2 details after applying discounts:" << endl;
    // Display order details for order2

    return 0;
    









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
