// this is one of the very important programs in terms of Copy Contstructor ,Shallow Copy , Deep Copy and object as a refernce 
#include<iostream>
#include<cstring>
using namespace std;
class Student{
    private:
        int age ;
    public:
        char *name;
        Student(int age , char * name ){
              this->age=age;
              this->name= new char[strlen(name)+1];
              strcpy(this->name,name);
         }
         Student(Student const &s)                 // creating our own new copy constructor that will do a Deep copy instead of doing a shallow copy
         {                                                          // why i am writing const before the before the student parameter we cannot make any changes in the student object we can only read the 
                                                                    // the  value of the student of object without making any changes 
            this->age= s.age;
            this->name= new char[strlen(s.name)+1];
            strcpy(this->name,s.name);
        }
        void display()
        {
            cout<<"Name = "<<name<<"\t"<<"Age = "<<age<<endl;
        }
};
int main()
{
    char name[] = "abcd";
    Student s1(20, name);
    s1.display();                   //  it will display the name as abcd 
    Student s2(s1);
    s2.name[0]= 'x';            // here we explicitly changed the value of name[0] to x since internal copy constructor uses shallow copy method it will be reflected in the object 
    s1.display();                   // Now when use will see the name of object s1 then you will find that it is changed to xbcd
    s2.display();
    /*So how we will solve this problem we will solve this problem by making our own new copy constructor that we not do a shallow copy instead it will do a deep copyso how it will work*/
}