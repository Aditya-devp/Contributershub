/*In this we will learn about Pure virtual functions
Pure Virtual Functions are those functions which does not have any definitions 
 */
#include<iostream>
using namespace std;
/*what is the true definition of an abstract class 
   -> so any class containing a pure virtual function is called an abstract class (abstract class in basic terms means incomplete class )
   -> we cannot create object of an abstract class(very important point) this due to incomplete function or the pure virttual function we cannot create the object  
*/
class Vehicle{
    public:
    string color;
    virtual void print() = 0;       // so this is how we declare a pure virtual function  
};
class car : public Vehicle{  //so here car class has inherited Vehicle class it has two options either become an abstract class or implement all the pure virtual functions and complete them
    public:
        int numGears;
        void print(){
            cout<< "Car"<<endl;
        }
};
int main(){
    car c;
    c.print();
}
/*What is the use case for Pure Virtual Functions
    the best use case of a pure virtual function is the calculation of salary at any organisation so we can say every employee in 
    an organisation is holding a certain position and the salary of each individual may vary so we create a salary calculator in the 
    base class as a pure virtual function and then complete in each different base class according to the position of the employee.
    this is one of the best use case of a Pure Virtual Functions.
*/