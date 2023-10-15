/*One of the major advantages of Inheritance is code reusability */
/*Access Specifier 
Private: This cannot be access outside the class this can only be accessed by the member Functions declared in the public access specifier 
Public: This can be accesed anywhere in the class and outside the class
Protected: This access specifier lies between Private and Public Access Specifier so this kind of access specifier may or may not be accessed according to our needs 
like if we have declared some property protected then only the child class can access it and the parent class can have access to the property
*/
#include<iostream>
using namespace std;
class vehicle{
    private:
        int maxSpeed;
    protected:
        int numTyres;
    public:
        string color;
};
// so the syntax to inherit the class is by  Class name  : access Specifier  base class name to inherit
class car : public vehicle{                         // so here we have inherited the class vehicle in public mode so the protected member will be inherited as protected and the 
    public:                                                           // the public member will be inheritedd as the public member 
    int numGears;
    void Print(){
    numTyres = 4;
        cout<<"NumTyres  " << numTyres <<endl;
        cout<<"Color  "<<color<<endl;
        cout<<"Numgears  "<<numGears<<endl;
       // cout<<"MaxSpeed"<<maxSpeed<<endl;       // similarly here the private member is not at all inherited 
    }
};  
int main(){
    vehicle v;
    v.color = "Blue";
   // v.numTyres = 4;     // so we can see that the Numtyre member is inherited as protected data member so we cannot access this outside the class
   // v.maxSpeed=80;     // similarly here the private member is not at all inherited 

    car c;
    c.numGears= 4;
   // c.numTyres= 4;   // So we can see that this  data member is inherited as protected member so we cannot access it outside the class 
    c.color= "Black";
    c.Print();
}