#include<iostream>
#include<string>
using namespace std;
class Employee{
    private:
        string name;
        int id;
        char sex;
    public:
        void initialize(){
            cout<<"Enter the Name"<<endl;
            cin>>name;
            cout<<"Enter the ID"<<endl;
            cin>>id;
            cout<<"Enter the Sex"<<endl;
            cin>>sex;
        }
        void Display(){
            cout<<"Name\t"<<name<<endl;
            cout<<"ID\t"<<id<<endl;
            cout<<"Sex\t"<<sex<<endl;
        }
        string get_Employee(){                                                      // The Getter Function Declared inside the body of the class
            return name;
        }
        void set_newname(string &s){                                            // The Setter Function used inside the body of the class 
            name=s;                                                                          // we can copy the string value just like an integer data type
        }
};
int main()
{
    Employee e;
    e.initialize();
    cout<<"The Name of the Employee is  "<<e.get_Employee()<<endl;
    cout<<endl;
    e.Display();
    string s ="Ballu";
    e.set_newname(s);
    cout<<endl;
    e.Display();
}