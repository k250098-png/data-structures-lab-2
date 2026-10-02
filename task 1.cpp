#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int marks[SIZE];
    int sum = 0;
    int highest, lowest;

    cout << "Enter the marks of 10 students:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
        sum += marks[i];
    }

    double average = static_cast<double>(sum) / SIZE;

    // Initialize highest and lowest with the first element for comparison
    highest = marks[0];
    lowest = marks[0];
    int aboveAverageCount = 0;

    cout << "\n--- Class Results ---\n";
    cout << "All Marks: ";
    for (int i = 0; i < SIZE; i++) {
        cout << marks[i] << " ";
        
        if (marks[i] > average) {
            aboveAverageCount++;
        }
        if (marks[i] > highest) {
            highest = marks[i];
        }
        if (marks[i] < lowest) {
            lowest = marks[i];
        }
    }

    cout << "\nClass Average: " << average << "\n";
    cout << "Students above average: " << aboveAverageCount << "\n";
    cout << "Highest Mark: " << highest << "\n";
    cout << "Lowest Mark: " << lowest << "\n";

    return 0;
}
