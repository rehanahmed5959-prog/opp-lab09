#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Number Of Students ";
    cin >> n;

    int* marks = new int[n];
    cout<<"Enter "<<n<<"Marks: ";
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin>>marks[i];
        total+= marks[i];
    }
    double average = (total * 1.0) / n;
    int highest = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] > highest) {
            highest = marks[i];
        }
    }
    
    cout << "Average: " << total / n << endl;

    delete[] marks; 
    marks = nullptr;
    return 0;
}