// in this program we will learn about shallow and Deep copy 
/*So what is Shallow Copy -> Basically shallow copy is whenever we pass an array 
    rather than copying the entire array we just copy the address of the 0th Index*/
    /*So shallow copy is copying just the reference of the array and not copying the entire array*/
#include<iostream>
#include<cstring>
using namespace std;
class Student{
    private:
        int age ;
        char *name;
    public:
        Student(int age , char * name ){
            this->age=age;
            // so the below name has done a shallow copy any changes in the name further will be reflected
            //  " this->name=name; "
            // so what is the solution to avoid this problem the solution that we have to copy the array into another array and and then point it to the copied array 
            //so what we will do is we will copy the the array to a newly allocated array
            this->name= new char[strlen(name)+1]; // allocating the memory of the data member name of class 
            strcpy(this->name,name);            // this strcpy will copy 
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
    s1.display();
    name[3]='e';
    Student s2(24,name ); // now when wwe pass the name argument it wont be reflected in other argument
    s2.display();
    s1.display();
}
