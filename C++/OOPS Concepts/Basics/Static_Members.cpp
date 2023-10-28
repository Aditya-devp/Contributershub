// A property that should be combined with respect to all the objects of the class and should be maintained 
//i.e value should be same  throughout all the objects of the class
// Static is the  Concept that comes into action  
// Static in simple words means that the property belongs to the class not to the object  
// static functions can only access static data member and static member functions
#include<iostream>
using namespace std;
class Student{
    private:
    static int totalStudents;          //total number of students present inside the class , so how do we declare => "static int variable_name"

    public:
    int roll_number;
    int age;
    // so here we are going to declare the static member functions
    static int gettotalStudents(){
        return totalStudents;
    }
    
    Student(){                               // so what we did over here is we created a constructor so whenever a object is created the value of total student will be incrementetd by one 
     totalStudents++; 
    }
};
// next thing comes into picture is how do we initialize the static data members the code line 13 explains how do we intialize static data members
int Student :: totalStudents=0;  // this how we intialize static data members 
int main(){
    Student s1;
    cout<<s1.roll_number<<" "<<s1.age<<endl;
    // so how do we print the value of static variable
    cout<<Student :: gettotalStudents()<<" "<<endl; 
    // what if we access the static data member of a class using the object of the class lets see
    cout<<s1.gettotalStudents()<<endl;
    //so the above line of works but it is logically incorrect expression... 
    // so what if we want to update the value of the static variable using the object lets see
   // s1.totalStudents=20;
    // Now we will create another student an see if the change is being reflected in the newly object created lets see...
    Student s2;
    cout<<s2.gettotalStudents()<<endl;                             // so it is showing the value now lets see the what the value of object s1 is containing // now called the member function
    cout<<s1.gettotalStudents()<<endl;                             // so it is showing the value // now called by the member functions
    // whether you change the value of the static variable through object s1 or s2 or any other object the static variable value will be changed automatically 
    // this because static variable is never inside the object container it is always inside the class and is accesed by all the objects of the class..
    // Just Like static data members static member function also exist
    // Very Important thing the name  of the Static data members and the static member function should not be the same
}
