#include <iostream>
#include <string>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* data;
    int count;
    int capacity;

    void grow();

public:
    DynamicArray(int cap = 2);
    ~DynamicArray();
    void push_back(T value);
    bool removeAt(int index);
    T get(int index);
    int size();
    int getCapacity();
    bool isEmpty();
};

template <typename T>
void DynamicArray<T>::grow() {
    int newCapacity = capacity * 2;
    T* bigger = new T[newCapacity];

    for (int i = 0; i < count; i++) {
        bigger[i] = data[i];
    }

    delete[] data;
    data = bigger;
    capacity = newCapacity;
}

template <typename T>
DynamicArray<T>::DynamicArray(int cap) {
    capacity = cap;
    count = 0;
    data = new T[capacity];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
void DynamicArray<T>::push_back(T value) {
    if (count == capacity) {
        grow();
    }
    data[count] = value;
    count++;
}

template <typename T>
bool DynamicArray<T>::removeAt(int index) {
    if (index < 0 || index >= count) {
        return false;
    }
    for (int i = index; i < count - 1; i++) {
        data[i] = data[i + 1];
    }
    count--;
    return true;
}

template <typename T>
T DynamicArray<T>::get(int index) {
    return data[index];
}

template <typename T>
int DynamicArray<T>::size() {
    return count;
}

template <typename T>
int DynamicArray<T>::getCapacity() {
    return capacity;
}

template <typename T>
bool DynamicArray<T>::isEmpty() {
    return count == 0;
}

class Product {
private:
    int id;
    string name;
    double price;
    int stock;

public:
    Product() {
        id = 0;
        name = "";
        price = 0.0;
        stock = 0;
    }

    Product(int id, string name, double price, int stock) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->stock = stock;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    void setPrice(double newPrice) { price = newPrice; }
    void setStock(int newStock) { stock = newStock; }

    bool operator==(const Product& other) const {
        return id == other.id;
    }

    bool operator>(const Product& other) const {
        return price > other.price;
    }

    bool operator<(const Product& other) const {
        return price < other.price;
    }

    friend ostream& operator<<(ostream& out, const Product& p) {
        out << "[ID: " << p.id << "] " << p.name
            << " | Price: $" << p.price
            << " | Stock: " << p.stock;
        return out;
    }
};

template <typename T>
void printArray(const T arr[], int n) {
    if (n <= 0) {
        cout << "No items to display." << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

template <typename T>
int searchItem(const T arr[], int n, const T& target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

template <typename T>
T findMax(const T arr[], int n) {
    T maxItem = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxItem) {
            maxItem = arr[i];
        }
    }
    return maxItem;
}

template <typename T>
T findMin(const T arr[], int n) {
    T minItem = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minItem) {
            minItem = arr[i];
        }
    }
    return minItem;
}

template <typename T>
int countMatches(const T arr[], int n, const T& target) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

template <typename T>
void sortAscending(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    DynamicArray<Product> store;
    int choice;

    do {
        cout << "\n===== STORE MENU =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display All Products" << endl;
        cout << "3. Remove Product" << endl;
        cout << "4. Search Product by ID" << endl;
        cout << "5. View Most Expensive & Cheapest Product" << endl;
        cout << "6. Display Products Sorted by Price" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, stock;
            string name;
            double price;

            cout << "Enter Product ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Product Name: ";
            getline(cin, name);
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Stock: ";
            cin >> stock;

            store.push_back(Product(id, name, price, stock));
            cout << "Product added successfully." << endl;
            break;
        }

        case 2: {
            if (store.isEmpty()) {
                cout << "Store is empty." << endl;
                break;
            }

            cout << "--- Store Products (" << store.size()
                 << "/" << store.getCapacity() << ") ---" << endl;
            for (int i = 0; i < store.size(); i++) {
                cout << i << ". " << store.get(i) << endl;
            }
            break;
        }

        case 3: {
            if (store.isEmpty()) {
                cout << "Store is empty." << endl;
                break;
            }

            int index;
            cout << "Enter index to remove (0 to " << store.size() - 1 << "): ";
            cin >> index;

            if (store.removeAt(index)) {
                cout << "Product removed." << endl;
            } else {
                cout << "Invalid index." << endl;
            }
            break;
        }

        case 4: {
            int n = store.size();
            if (n == 0) {
                cout << "Store is empty." << endl;
                break;
            }

            int targetId;
            cout << "Enter Product ID to search: ";
            cin >> targetId;

            Product* temp = new Product[n];
            for (int i = 0; i < n; i++) {
                temp[i] = store.get(i);
            }

            int index = searchItem(temp, n, Product(targetId, "", 0.0, 0));
            if (index != -1) {
                cout << "Product found: " << temp[index] << endl;
            } else {
                cout << "Product with ID " << targetId << " not found." << endl;
            }

            delete[] temp;
            break;
        }

        case 5: {
            int n = store.size();
            if (n == 0) {
                cout << "Store is empty." << endl;
                break;
            }

            Product* temp = new Product[n];
            for (int i = 0; i < n; i++) {
                temp[i] = store.get(i);
            }

            cout << "Most Expensive: " << findMax(temp, n) << endl;
            cout << "Cheapest:       " << findMin(temp, n) << endl;

            delete[] temp;
            break;
        }

        case 6: {
            int n = store.size();
            if (n == 0) {
                cout << "Store is empty." << endl;
                break;
            }

            Product* temp = new Product[n];
            for (int i = 0; i < n; i++) {
                temp[i] = store.get(i);
            }

            sortAscending(temp, n);
            cout << "--- Products Sorted by Price ---" << endl;
            printArray(temp, n);

            delete[] temp;
            break;
        }

        case 0:
            cout << "Exiting store..." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}