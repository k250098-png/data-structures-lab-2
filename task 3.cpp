#include <iostream>
using namespace std;

int main() {
    int oldRows, oldCols;
    cout << "Enter initial number of students (rows): ";
    cin >> oldRows;
    cout << "Enter initial number of subjects (cols): ";
    cin >> oldCols;


    int** marks = new int*[oldRows];
    for (int i = 0; i < oldRows; i++) {
        marks[i] = new int[oldCols];
    }

    cout << "\nEnter marks for initial students and subjects:\n";
    for (int i = 0; i < oldRows; i++) {
        for (int j = 0; j < oldCols; j++) {
            cout << "Student " << i + 1 << ", Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    int newRows, newCols;
    cout << "\nEnter new number of students: ";
    cin >> newRows;
    cout << "Enter new number of subjects: ";
    cin >> newCols;

 
    int** newMarks = new int*[newRows];
    for (int i = 0; i < newRows; i++) {
        newMarks[i] = new int[newCols];
    }

    cout << "\nProcessing new dimensions...\n";
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
          
            if (i < oldRows && j < oldCols) {
                newMarks[i][j] = marks[i][j];
            } else {
                cout << "Enter NEW mark for Student " << i + 1 << ", Subject " << j + 1 << ": ";
                cin >> newMarks[i][j];
            }
        }
    }

    cout << "\n--- Updated Marks Table ---\n";
    for (int i = 0; i < newRows; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < newCols; j++) {
            cout << newMarks[i][j] << "\t";
        }
        cout << "\n";
    }


    for (int i = 0; i < oldRows; i++) {
        delete[] marks[i]; // Delete each row
    }
    delete[] marks; 

   
    for (int i = 0; i < newRows; i++) {
        delete[] newMarks[i];
    }
    delete[] newMarks;

    return 0;
}
