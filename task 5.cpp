#include <iostream>
using namespace std;

int main() {
    int numClasses;
    cout << "Enter the number of classes: ";
    cin >> numClasses;

    
    int** classes = new int*[numClasses];
    
   
    int* studentsPerClass = new int[numClasses];

    for (int i = 0; i < numClasses; i++) {
        cout << "Enter number of students in class " << i + 1 << ": ";
        cin >> studentsPerClass[i];

      
        classes[i] = new int[studentsPerClass[i]];

        for (int j = 0; j < studentsPerClass[i]; j++) {
            cout << "  Mark for student " << j + 1 << ": ";
            cin >> classes[i][j];
        }
    }

    cout << "\n--- Class Marks and Averages ---\n";
    for (int i = 0; i < numClasses; i++) {
        int sum = 0;
        cout << "Class " << i + 1 << " Marks: ";
        
        for (int j = 0; j < studentsPerClass[i]; j++) {
            cout << classes[i][j] << " ";
            sum += classes[i][j];
        }

        double average = static_cast<double>(sum) / studentsPerClass[i];
        cout << "| Average: " << average << "\n";
    }

    for (int i = 0; i < numClasses; i++) {
        delete[] classes[i];
    }
    delete[] classes;
    delete[] studentsPerClass;

    return 0;
}
