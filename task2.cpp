#include <iostream>
using namespace std;

int main() {
    int initialSize;
    cout << "Enter the initial number of products: ";
    cin >> initialSize;


    double* prices = new double[initialSize];

    for (int i = 0; i < initialSize; i++) {
        cout << "Enter price for product " << i + 1 << ": ";
        cin >> prices[i];
    }

    int newSize;
    cout << "\nEnter the new total number of products: ";
    cin >> newSize;

    if (newSize > initialSize) {
       
        double* newPrices = new double[newSize];
        for (int i = 0; i < initialSize; i++) {
            newPrices[i] = prices[i];
        }

        for (int i = initialSize; i < newSize; i++) {
            cout << "Enter price for new product " << i + 1 << ": ";
            cin >> newPrices[i];
        }

        delete[] prices;

        prices = newPrices;
        initialSize = newSize; 
    } else {
        cout << "New size is not larger than initial size. No new products added.\n";
    }

    cout << "\n--- Updated Product Prices ---\n";
    for (int i = 0; i < initialSize; i++) {
        cout << "Product " << i + 1 << ": $" << prices[i] << "\n";
    }
    delete[] prices;
    return 0;
}
