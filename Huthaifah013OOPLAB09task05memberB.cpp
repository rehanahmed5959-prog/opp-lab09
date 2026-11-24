#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int id;
    string name;
    double price;
    int stock;

public:
    Product()
    {
        id = 0;
        name = "";
        price = 0.0;
        stock = 0;
    }
    Product(int id, string name, double price, int stock)
    {
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
    bool operator==(const Product& other) const
    {
        return id == other.id;
    }

    bool operator>(const Product& other) const
    {
        return price > other.price;
    }

    bool operator<(const Product& other) const
    {
        return price < other.price;
    }

    friend ostream& operator<<(ostream& out, const Product& p)
    {
        out << "ID: " << p.id << p.name
            << " | Price: $" << p.price
            << " | Stock: " << p.stock;
        return out;
    }
};