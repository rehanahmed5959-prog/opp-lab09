#include<iostream>
using namespace std;

template <typename T>

void printArray(T arr[] , int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<endl;
        if(i < n-1){
            cout<<" ";
        }
    }
    cout<<endl;
}

template <typename T>

T findMax(T arr[] , int n){
    T temporary = arr[0];
    for(int i = 1; i < n; i++){
        if(temporary < arr[i]){
            temporary = arr[i];
        }
    }
    return temporary;
}
template <typename T>
int countValue(T arr[], int n, T value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

template <typename T>
int search(T arr[], int n, T value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int nums[] = {4, 9, 2, 9, 7};
    printArray(nums, 5);
    cout << "Max: " << findMax(nums, 5)
         << ", count of 9: " << countValue(nums, 5, 9) << endl;

    double temps[] = {31.5, 28.0, 35.2};
    printArray(temps, 3);
    cout << "Max: " << findMax(temps, 3) << endl;

    string names[] = {"Ali", "Sara", "Zain", "Sara"};
    printArray(names, 4);
    cout << "Max: " << findMax(names, 4)
         << ", Sara found at index " << search(names, 4, string("Sara")) << endl;

    char grades[] = {'B', 'A', 'C', 'A', 'A'};
    printArray(grades, 5);
    cout << "Count of A: " << countValue(grades, 5, 'A')
         << ", D found at index " << search(grades, 5, 'D') << endl;

    return 0;
}