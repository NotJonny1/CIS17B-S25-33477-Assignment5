#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

// Generic package template
template<typename T>
class Package {
private:
    T item;
public:
    Package(T i) : item(i) {}
    void label() {
        std::cout << "Generic package containing: " << typeid(T).name() << "\n";
    }
};

// Specialization for string
template<>
class Package<std::string> {
private:
    std::string item;
public:
    Package(std::string i) : item(i) {}
    void label() {
        std::cout << "Book package: \"" << item << "\"\n";
    }
};

// Partial specialization for pointer types
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        std::cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

// Box template
template<typename T, int Size>
class Box {
private:
    std::array<T, Size> items;
    int count = 0;
public:
    bool addItem(const T& item) {
        if (count < Size) {
            items[count++] = item;
            std::cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        return false;
    }

    void printItems() const {
        std::cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            std::cout << " - " << items[i] << "\n";
        }
    }
};

// Generic shipItem function template
template<typename T>
void shipItem(const T& item) {
    std::cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

// Specialization for double
template<>
void shipItem(const double& item) {
    std::cout << "Shipping temperature-controlled item: " << item << "°C\n";
}

// Main function to demonstrate behavior
int main() {
    // Create different types of packages
    Package<int> p1(42);
    Package<std::string> p2("C++ Primer");
    double temp = 36.5;
    Package<double*> p3(&temp);

    // Label them
    p1.label();
    p2.label();
    p3.label();

    std::cout << "\n";

    // Create a box for strings (books)
    Box<std::string, 3> bookBox;
    bookBox.addItem("The Pragmatic Programmer");
    bookBox.addItem("Clean Code");
    bookBox.printItems();

    std::cout << "\n";

    // Ship different types of items
    shipItem(123);
    shipItem(std::string("Packing Peanuts"));
    shipItem(22.5);

    return 0;
}
