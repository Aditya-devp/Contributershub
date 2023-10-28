#include<iostream>
using namespace std;
#include<string>
class Student{
    public:
      //string name
        int roll;                           // 4 bytes
        int age;                        // 4bytes
        void get_details()
        {
        //    cout<<"Enter the name"<<endl;
          //  getline(cin,name);
            cout<<"Enter the Roll Number"<<endl;
            cin>>roll;
            cout<<"Enter the Age"<<endl;
            cin>>age;
        }
        void display()
        {
            //cout<<"Name\t"<<name<<endl;
            cout<<"Roll Number\t"<<roll<<endl;
            cout<<"Age\t"<<age<<endl;
        }    
};
//dynamic object creation of  
int main()
{
  Student  *s3 = new Student;
  (*s3).age=21;               // this can also be written as  s3-> age=21;
  (*s3).roll=22;              // this can also be written as s3->roll =22; // both codes work similarly 
  cout<<"Age is \t"<<s3->age<<endl;       // look here i used this code to acces the value of the variable age 
  cout<<"Roll Number is\t"<<s3->roll<<endl;   //look here i used this code to access the value of the variable  roll
  return 0;
}