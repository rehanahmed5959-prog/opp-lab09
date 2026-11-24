#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    T* items;
    int capacity;
    int top;

public:
    Stack(int cap) {
        capacity = cap;
        top = 0;
        items = new T[capacity];
    }

    ~Stack() {
        delete[] items;
    }

    bool isEmpty() {
        return top == 0;
    }

    bool isFull() {
        return top == capacity;
    }

    int size() {
        return top;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack is full, cannot push " << value << endl;
            return;
        }
        items[top] = value;
        top++;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        top--;
        return items[top];
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        return items[top - 1];
    }
};

int main() {
    Stack<int> nums(3);
    nums.push(10);
    nums.push(20);
    nums.push(30);
    nums.push(40);

    cout << "Popping:";
    while (!nums.isEmpty()) {
        cout << " " << nums.pop();
    }
    cout << endl;

    string word = "LAHORE";
    Stack<char> letters(6);
    for (int i = 0; i < 6; i++) {
        letters.push(word[i]);
    }

    cout << "LAHORE reversed: ";
    while (!letters.isEmpty()) {
        cout << letters.pop();
    }
    cout << endl;


    Stack<string> history(5);
    history.push("example.com");
    history.push("github.com");
    history.push("gutech.edu.pk");

    cout << "Current page: " << history.peek() << endl;
    history.pop();
    cout << "After Back: " << history.peek() << endl;

    return 0;
}