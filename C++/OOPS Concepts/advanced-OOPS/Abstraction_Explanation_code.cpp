#include <iostream>

using namespace std;  // Use the standard namespace for easier access to std functions

// Base class
class Shape {
public:
    // Abstract method to calculate area
    virtual double calculateArea() = 0;
    
    // Abstract method to display shape details
    virtual void display() = 0;
};

// Derived class representing a Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Implementation of calculateArea for a circle
    double calculateArea() override {
        return 3.14159 * radius * radius;
    }

    // Implementation of display for a circle
    void display() override {
        cout << "Shape: Circle\n";
        cout << "Radius: " << radius << "\n";
        cout << "Area: " << calculateArea() << "\n";
    }
};

// Derived class representing a Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Implementation of calculateArea for a rectangle
    double calculateArea() override {
        return length * width;
    }

    // Implementation of display for a rectangle
    void display() override {
        cout << "Shape: Rectangle\n";
        cout << "Length: " << length << "\n";
        cout << "Width: " << width << "\n";
        cout << "Area: " << calculateArea() << "\n";
    }
};

int main() {
    // Create objects of Circle and Rectangle
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // Polymorphic behavior, as both objects are treated as Shapes
    Shape* shapes[] = { &circle, &rectangle };

    for (int i = 0; i < 2; i++) {
        shapes[i]->display();
        cout << "----------------------\n";
    }

    return 0;
}
