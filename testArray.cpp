#include <iostream>
#include <string>
#include "DynamicArray.h"
using namespace std;

int main() {
    DynamicArray<int> nums(2);

    cout << "Empty at start? " << nums.isEmpty() << endl;

    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30); // triggers grow()

    cout << "Size: " << nums.size() << ", Capacity: " << nums.getCapacity() << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums.get(i) << " ";
    }
    cout << endl;

    nums.removeAt(1);
    cout << "After removing index 1, size: " << nums.size() << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums.get(i) << " ";
    }
    cout << endl;

    DynamicArray<string> names(2);
    names.push_back("Ali");
    names.push_back("Sara");
    cout << "First name: " << names.get(0) << endl;

    return 0;
}