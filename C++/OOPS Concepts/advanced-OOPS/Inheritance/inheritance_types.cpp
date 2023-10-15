// we will study about the types of inheritance ...
/*
1. Single Inheritance
    class A-> class B

2. Multilevel Inheritance 
class A->B->C           // this is a type of multtilevel inheritance 

3. Hierrachial Inheritance 
class A-> class B
           ->class C
           ->class D
more than one derived class associated with a single parent class or base class is an example of hierarchial Inheritance

4. Multiple Inheritance 
    class A ->Class D
    class B ->Class D
    class C ->Class D

    A derived class having more than one parent class or base class is called a Mutilple Inheritance .
*/

#include<iostream>
using namespace std; 
class teacher{
    public:
    string name;
    string age ;
    void print(){
        cout<<"Teacher"<<endl;          // here also we created a member function named print()
    }
};
class Student{
    public:
    void print(){
        cout<<"Student"<<endl;          // here also we created a member function named print()
    }
};
class TA :public teacher, public Student{                   // In case of a multiple inheritance we use this syntax to create multiple inheritance 
    public:                                                                     // during the time of the object creation it follow the order in which the base classes are inherited the constructor are also called in that manner only
            void print()
            {
                cout<<"TA"<<endl;
            }
};
int main()
{
    TA a;
    a.print();                                                              // if class TA does not have any member function name same as that of member functions of base class then the correct way to call the member function that is inherited from the class is by
                                                                               //  a.Student :: print() this is the correct way to call the member function with same name inside multiple parent clasess which is inherited
                                                                              // it is also applicable in case of the data members
}
// Use the next Code For hybrid inheritance . Learn Hybrid inheritance from Hybrid Inheritance.cpp