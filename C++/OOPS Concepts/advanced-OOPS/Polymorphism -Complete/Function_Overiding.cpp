// Function Overloading is also an example of Compile Time polymorphism
#include<iostream>
using namespace std;
class Vehicle {
    public:
        string color;
        void print(){
            cout<<"Vehicle"<<endl;
        }    
};
class Car : public Vehicle{
    public:
    int numGears;
    void print(){                               // same function is in base class andd same function i have declared in the chiild class 
        cout<<"Car"<<endl;
    }
};
int main()
{
    Vehicle v;
    Car c;
    v.print();              // vehicle class function will be called..
    c.print();              // car class function will be called..
    Vehicle *v1 = new Vehicle;
    Vehicle *v2;
    // 
    v2 = &c;    // here base class pointer is pointing to derived class object but we cannot do it vice-versa
    v1->print();        // it is clear that vehicle class function  will be printed
    // but what if we call the class member function with pointer type object which points to the object of the derived class 
    v2->print();        // here v2 is pointing to the derived class car but when we call the print function it calls the  member functions of the base class
    // here the compiler does not checks  that the object is pointing to which class , it  just sees the pointer is which class type  for eg "base class" so it calls the base class member functions

/*So the above Function Overriding method is also a Compile  time Polymorphism Example */
}