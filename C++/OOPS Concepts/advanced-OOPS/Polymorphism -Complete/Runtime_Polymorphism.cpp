#include<iostream>
using namespace std;
class Vehicle {
    public:
        string color;
        virtual void print(){
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
    v2->print();        // here v2 is pointing to the derived class car but now we have used virtual keyword infront of the member function of class Vehicle so it will be working during runtime only
    //if we want to call the print function of class car how we will do it??
    /*By Runtime Polymorphism ->  So in order to acheive runtime polymorphism we need to take help of virtual functions 
        Virtual Functions => Virtual Functions are those functions that are created in base class and the same function is overiden in the derived class
        by adding virtual keyword i am letting the compiler to decide the function during the runtime and during runtime the compiler sees that the pointer
        is pointing to which class object and when it finds that class car is having a member function print() so it calls it.
         */
        // if we  remove  the print member function from the base class then we will encounter an error 
        // this is because while removing the member Function in the process we also removed the virtual keyword which was enabling the runtime polymorphism.
        // so we will encounter an error

}