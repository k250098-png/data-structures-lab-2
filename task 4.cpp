#include <iostream>
using namespace std;

class SafeArray {
private:
    int* arr;
    int size;

public:
  
    SafeArray(int s) {
        if (s <= 0) {
            cout << "Error: Array size must be positive. Defaulting to size 1.\n";
            s = 1;
        }
        size = s;
        arr = new int[size];
        
    
        for(int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }


    ~SafeArray() {
        delete[] arr;
    }

    void insert(int index, int value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
            cout << "Inserted " << value << " at index " << index << ".\n";
        } else {
            cout << "Error: Index " << index << " is out of bounds for insertion.\n";
        }
    }

    int retrieve(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            cout << "Error: Index " << index << " is out of bounds for retrieval.\n";
            return -1; 
        }
    }
};

int main() {
    SafeArray myArray(5);


    myArray.insert(0, 10);
    myArray.insert(4, 50);
    cout << "Value at index 0: " << myArray.retrieve(0) << "\n";
    cout << "Value at index 4: " << myArray.retrieve(4) << "\n";


    myArray.insert(5, 60);
    myArray.insert(-1, 99);
    int invalidVal = myArray.retrieve(6);

    return 0;
}
